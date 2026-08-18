import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;

public class FixAdvDataSplit extends GhidraScript {
    @Override
    public void run() throws Exception {
        Listing listing = currentProgram.getListing();
        FunctionManager fm = currentProgram.getFunctionManager();

        Address entry_4570 = toAddr("0x600c4570");
        Address entry_463c = toAddr("0x600c463c");
        Address end_4570 = toAddr("0x600c4665");

        Function f_463c = fm.getFunctionAt(entry_463c);
        if (f_463c != null) {
            fm.removeFunction(entry_463c);
            println("Removed spurious split function at 0x600c463c");
        }

        Function f_4570 = fm.getFunctionAt(entry_4570);
        if (f_4570 != null) {
            fm.removeFunction(entry_4570);
            println("Removed old FUN_600c4570");
        }

        disassemble(entry_4570);
        AddressSet set_4570 = new AddressSet(entry_4570, end_4570);
        f_4570 = fm.createFunction("FUN_600c4570", entry_4570, set_4570, SourceType.USER_DEFINED);
        println("Created merged FUN_600c4570 (size=" + f_4570.getBody().getNumAddresses() + "): " + f_4570);
    }
}
