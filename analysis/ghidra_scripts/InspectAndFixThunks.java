import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class InspectAndFixThunks extends GhidraScript {
    @Override
    public void run() throws Exception {
        Listing listing = currentProgram.getListing();
        FunctionManager fm = currentProgram.getFunctionManager();

        String[] addrs = {"0x600926a0", "0x600926b8", "0x600925bc", "0x600ee18a"};
        for (String a : addrs) {
            Address addr = toAddr(a);
            println("==================================================");
            println("INSPECTING " + a);
            Function f = fm.getFunctionContaining(addr);
            if (f != null) {
                println("Existing function: " + f.getName() + " @ " + f.getEntryPoint() + " body=" + f.getBody());
            } else {
                println("No function containing " + a);
            }
            // Disassemble starting at addr if not already instructions
            Instruction inst = listing.getInstructionAt(addr);
            if (inst == null) {
                println("Disassembling at " + a);
                disassemble(addr);
            }
            Address cur = addr;
            for (int i = 0; i < 20; i++) {
                inst = listing.getInstructionAt(cur);
                if (inst == null) break;
                println(String.format("  0x%08x: %-24s (len=%d)", inst.getAddress().getOffset(), inst.toString(), inst.getLength()));
                Reference[] refs = inst.getReferencesFrom();
                for (Reference r : refs) {
                    println("       -> ref to " + r.getToAddress() + " (" + r.getReferenceType() + ")");
                }
                cur = inst.getAddress().add(inst.getLength());
            }
        }
    }
}
