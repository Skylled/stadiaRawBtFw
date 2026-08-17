import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;

public class FixThunkBoundaries extends GhidraScript {
    @Override
    public void run() throws Exception {
        Listing listing = currentProgram.getListing();
        FunctionManager fm = currentProgram.getFunctionManager();

        // 1. Fix 0x600ee18a
        Address addr_ee18a = toAddr("0x600ee18a");
        disassemble(addr_ee18a);
        
        // 2. Fix FUN_600926a0: entry 0x600926a0, body 0x600926a0..0x600926b3
        Address entry_26a0 = toAddr("0x600926a0");
        Function f_26a0 = fm.getFunctionAt(entry_26a0);
        if (f_26a0 != null) {
            fm.removeFunction(entry_26a0);
        }
        
        // Disassemble and create function at 0x600ee18a
        Address end_ee18a = toAddr("0x600ee1bd");
        AddressSet set_ee18a = new AddressSet(addr_ee18a, end_ee18a);
        Function f_ee18a = fm.getFunctionAt(addr_ee18a);
        if (f_ee18a != null) fm.removeFunction(addr_ee18a);
        f_ee18a = fm.createFunction("FUN_600ee18a", addr_ee18a, set_ee18a, SourceType.USER_DEFINED);
        println("Created FUN_600ee18a: " + f_ee18a);

        // Recreate FUN_600926a0
        AddressSet set_26a0 = new AddressSet(entry_26a0, toAddr("0x600926b3"));
        f_26a0 = fm.createFunction("FUN_600926a0", entry_26a0, set_26a0, SourceType.USER_DEFINED);
        println("Recreated FUN_600926a0: " + f_26a0);

        // 3. Fix 0x60077744 stub
        Address entry_7744 = toAddr("0x60077744");
        Function f_7744 = fm.getFunctionAt(entry_7744);
        if (f_7744 != null) {
            fm.removeFunction(entry_7744);
            AddressSet set_7744 = new AddressSet(entry_7744, toAddr("0x60077749"));
            f_7744 = fm.createFunction("FUN_60077744", entry_7744, set_7744, SourceType.USER_DEFINED);
            println("Recreated FUN_60077744: " + f_7744);
        }

        // 4. Create FUN_600925bc
        Address entry_25bc = toAddr("0x600925bc");
        disassemble(entry_25bc);
        Function f_25bc = fm.getFunctionAt(entry_25bc);
        if (f_25bc != null) fm.removeFunction(entry_25bc);
        AddressSet set_25bc = new AddressSet(entry_25bc, toAddr("0x6009266b"));
        f_25bc = fm.createFunction("FUN_600925bc", entry_25bc, set_25bc, SourceType.USER_DEFINED);
        println("Created FUN_600925bc: " + f_25bc);

        // 5. Fix FUN_600926b8
        Address entry_26b8 = toAddr("0x600926b8");
        Function f_26b8 = fm.getFunctionAt(entry_26b8);
        if (f_26b8 != null) fm.removeFunction(entry_26b8);
        AddressSet set_26b8 = new AddressSet(entry_26b8, toAddr("0x600926cb"));
        f_26b8 = fm.createFunction("FUN_600926b8", entry_26b8, set_26b8, SourceType.USER_DEFINED);
        println("Recreated FUN_600926b8: " + f_26b8);
    }
}
