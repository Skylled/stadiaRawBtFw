// Print the defined data (or raw dword) at each given address, resolving it as a
// little-endian pointer if plausible, and naming the function/symbol at that pointer.
// Usage: -postScript PrintData.java 0x600585e8 0x...
// @category Stadia
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;

public class PrintData extends GhidraScript {
    @Override
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        FunctionManager fm = currentProgram.getFunctionManager();
        SymbolTable st = currentProgram.getSymbolTable();
        for (String a : getScriptArgs()) {
            Address addr;
            try { addr = toAddr(a); } catch (Exception e) { println("bad addr " + a); continue; }
            println("DATA AT " + a + ":");
            Data d = getDataAt(addr);
            if (d != null) {
                println("   defined data: type=" + d.getDataType().getName() + " value=" + d.getDefaultValueRepresentation());
            }
            try {
                int raw = mem.getInt(addr);
                println("   raw dword (LE) = 0x" + Integer.toHexString(raw));
                Address ptrTarget = addr.getNewAddress(raw & 0xFFFFFFFFL);
                Function f = fm.getFunctionContaining(ptrTarget);
                if (f != null) {
                    println("   -> as pointer, lands in function " + f.getName() + " @" + f.getEntryPoint());
                } else {
                    Symbol[] syms = st.getSymbols(ptrTarget);
                    if (syms.length > 0) {
                        println("   -> as pointer, lands on symbol " + syms[0].getName() + " @" + ptrTarget);
                    } else {
                        Data d2 = getDataContaining(ptrTarget);
                        if (d2 != null) {
                            println("   -> as pointer, lands in data " + d2.getLabel() + " @" + d2.getAddress()
                                    + " type=" + d2.getDataType().getName());
                        } else {
                            println("   -> as pointer, target @" + ptrTarget + " has no function/symbol/data");
                        }
                    }
                }
            } catch (Exception e) {
                println("   (could not read raw dword: " + e.getMessage() + ")");
            }
        }
    }
}
