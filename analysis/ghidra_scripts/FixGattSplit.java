import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;

public class FixGattSplit extends GhidraScript {
    @Override
    public void run() throws Exception {
        Listing listing = currentProgram.getListing();
        FunctionManager fm = currentProgram.getFunctionManager();

        Address entry_fea0 = toAddr("0x600afea0");
        Address entry_fee4 = toAddr("0x600afee4");
        Address end_fea0 = toAddr("0x600aff11");

        Function f_fee4 = fm.getFunctionAt(entry_fee4);
        if (f_fee4 != null) {
            fm.removeFunction(entry_fee4);
            println("Removed spurious split function at 0x600afee4");
        }

        Function f_fea0 = fm.getFunctionAt(entry_fea0);
        if (f_fea0 != null) {
            fm.removeFunction(entry_fea0);
            println("Removed old FUN_600afea0");
        }

        disassemble(entry_fea0);
        AddressSet set_fea0 = new AddressSet(entry_fea0, end_fea0);
        f_fea0 = fm.createFunction("FUN_600afea0", entry_fea0, set_fea0, SourceType.USER_DEFINED);
        println("Created merged FUN_600afea0 (size=" + f_fea0.getBody().getNumAddresses() + "): " + f_fea0);
    }
}
