// Print functions that reference each given data address (e.g. a string).
// Usage: -postScript FindRef.java 0x601230e7 0x...
// @category Stadia
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

public class FindRef extends GhidraScript {
    @Override
    public void run() throws Exception {
        ReferenceManager rm = currentProgram.getReferenceManager();
        FunctionManager fm = currentProgram.getFunctionManager();
        for (String a : getScriptArgs()) {
            Address addr;
            try { addr = toAddr(a); } catch (Exception e) { println("bad addr " + a); continue; }
            println("REF TO " + a + ":");
            ReferenceIterator ri = rm.getReferencesTo(addr);
            boolean any = false;
            while (ri.hasNext()) {
                Reference r = ri.next();
                Function f = fm.getFunctionContaining(r.getFromAddress());
                println("   from " + r.getFromAddress()
                        + (f != null ? "  in " + f.getName() + " @" + f.getEntryPoint() : "  (no func)"));
                any = true;
            }
            if (!any) println("   (no refs)");
        }
    }
}
