import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.mem.Memory;

public class InspectWave5 extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] addrs = {
            "0x60051824", "0x60052254", "0x60059f98", "0x6005bdb4", "0x6005d9a8",
            "0x600600c4", "0x600600f8", "0x6006012c", "0x60060804", "0x6006180c",
            "0x600619bc", "0x60061cc8", "0x60067ddc", "0x6006820c", "0x6007946c",
            "0x60084d34", "0x600866c4", "0x60091c10", "0x60090cbc", "0x60091098",
            "0x600cb210", "0x600cbdd4"
        };
        
        Listing listing = currentProgram.getListing();
        FunctionManager fm = currentProgram.getFunctionManager();
        ReferenceManager rm = currentProgram.getReferenceManager();
        
        for (String a : addrs) {
            Address addr = toAddr(a);
            Function f = fm.getFunctionContaining(addr);
            println("==================================================");
            if (f == null) {
                println("No function at " + a);
                continue;
            }
            println("FUNCTION: " + f.getName() + " @ " + f.getEntryPoint() + " (size: " + f.getBody().getNumAddresses() + ")");
            
            // Print all instructions and references
            InstructionIterator iter = listing.getInstructions(f.getBody(), true);
            while (iter.hasNext()) {
                Instruction inst = iter.next();
                Reference[] refs = inst.getReferencesFrom();
                StringBuilder sb = new StringBuilder();
                sb.append(String.format("  0x%08x: %-24s", inst.getAddress().getOffset(), inst.toString()));
                for (Reference r : refs) {
                    Address to = r.getToAddress();
                    Data d = listing.getDataAt(to);
                    Function targetF = fm.getFunctionAt(to);
                    if (targetF != null) {
                        sb.append(" -> fn:").append(targetF.getName()).append(" @ ").append(to);
                    } else if (d != null) {
                        sb.append(" -> data:").append(d.getDefaultValueRepresentation()).append(" (").append(d.getDataType().getName()).append(") @ ").append(to);
                    } else {
                        sb.append(" -> ref:").append(to);
                    }
                }
                println(sb.toString());
            }
        }
    }
}
