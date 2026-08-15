// Pre-analysis script: parse the Cortex-M vector table at the image base,
// disassemble/create a function at each handler entry, and mark the reset vector.
// @category Stadia
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

public class SeedCortexM extends GhidraScript {
    @Override
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        // NOTE: getImageBase() is 0 for a raw BinaryLoader import; the actual
        // load address is the start of the single loaded block.
        Address base = currentProgram.getMinAddress();
        long imgStart = base.getOffset();
        long maxOff = currentProgram.getMaxAddress().getOffset();

        int created = 0;
        int invalidRun = 0;
        int maxEntries = 512; // covers SP + 15 system + up to ~160 IRQ vectors, generously
        for (int i = 1; i < maxEntries; i++) {
            Address ea = base.add((long) i * 4);
            int val;
            try { val = mem.getInt(ea); } catch (Exception e) { break; }
            long tgt = ((long) val) & 0xFFFFFFFFL;
            long faddr = tgt & ~1L;
            boolean thumb = (tgt & 1L) == 1L;
            boolean inFlash = faddr >= imgStart && faddr <= maxOff;

            if (tgt == 0) { // reserved vector slot
                invalidRun++;
                if (invalidRun > 8 && i > 16) break;
                continue;
            }
            if (thumb && inFlash) {
                invalidRun = 0;
                Address f = toAddr(faddr);
                try {
                    disassemble(f);
                    if (getFunctionAt(f) == null) {
                        createFunction(f, null);
                    }
                    created++;
                } catch (Exception e) { /* skip bad entry */ }
            } else {
                invalidRun++;
                if (invalidRun > 8 && i > 16) break;
            }
        }

        try {
            int resetVal = mem.getInt(base.add(4));
            Address reset = toAddr((((long) resetVal) & 0xFFFFFFFFL) & ~1L);
            disassemble(reset);
            Function rf = getFunctionAt(reset);
            if (rf == null) rf = createFunction(reset, "Reset_Handler");
            if (rf != null) rf.setName("Reset_Handler", SourceType.USER_DEFINED);
            currentProgram.getSymbolTable().addExternalEntryPoint(reset);
        } catch (Exception e) { /* ignore */ }

        println("SeedCortexM: seeded ~" + created + " functions from the vector table");
    }
}
