import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

public class FixSpuriousSplits extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        
        // 1. Fix 0x600a7870 / 0x600a7896
        Address a7870 = toAddr(0x600a7870);
        Address a7896 = toAddr(0x600a7896);
        Function f7896 = fm.getFunctionAt(a7896);
        if (f7896 != null) {
            println("Removing spurious split function at " + a7896);
            fm.removeFunction(a7896);
        }
        Function f7870 = fm.getFunctionAt(a7870);
        if (f7870 != null) {
            Address end7870 = toAddr(0x600a7870 + 714 - 1);
            f7870.setBody(new AddressSet(a7870, end7870));
        }
        
        // 2. Fix 0x600b5540 / 0x600b56aa
        Address a5540 = toAddr(0x600b5540);
        Address a56aa = toAddr(0x600b56aa);
        Function f56aa = fm.getFunctionAt(a56aa);
        if (f56aa != null) {
            println("Removing spurious split function at " + a56aa);
            fm.removeFunction(a56aa);
        }
        Function f5540 = fm.getFunctionAt(a5540);
        if (f5540 != null) {
            Address end5540 = toAddr(0x600b5540 + 364 - 1);
            f5540.setBody(new AddressSet(a5540, end5540));
        }

        // 3. Fix 0x600b6378 / 0x600b643a
        Address a6378 = toAddr(0x600b6378);
        Address a643a = toAddr(0x600b643a);
        Function f643a = fm.getFunctionAt(a643a);
        if (f643a != null) {
            println("Removing spurious split function at " + a643a);
            fm.removeFunction(a643a);
        }
        Function f6378 = fm.getFunctionAt(a6378);
        if (f6378 != null) {
            Address end6378 = toAddr(0x600b6378 + 260 - 1);
            f6378.setBody(new AddressSet(a6378, end6378));
        }

        // 4. Remove mid-function fragment 0x60092ada (inside 0x600929f4)
        Address a2ada = toAddr(0x60092ada);
        Function f2ada = fm.getFunctionAt(a2ada);
        if (f2ada != null) {
            println("Removing mid-function fragment at " + a2ada);
            fm.removeFunction(a2ada);
        }
        Address a29f4 = toAddr(0x600929f4);
        Function f29f4 = fm.getFunctionAt(a29f4);
        if (f29f4 != null) {
            Address end29f4 = toAddr(0x600929f4 + 754 - 1);
            f29f4.setBody(new AddressSet(a29f4, end29f4));
        }

        // 5. Merge BTU Task 0x600a9f04 / 0x600a9f10 / 0x600a9fce
        Address a9f10 = toAddr(0x600a9f10);
        Address a9fce = toAddr(0x600a9fce);
        Function f9f10 = fm.getFunctionAt(a9f10);
        if (f9f10 != null) {
            println("Removing split fragment at " + a9f10);
            fm.removeFunction(a9f10);
        }
        Function f9fce = fm.getFunctionAt(a9fce);
        if (f9fce != null) {
            println("Removing split fragment at " + a9fce);
            fm.removeFunction(a9fce);
        }
        Address a9f04 = toAddr(0x600a9f04);
        Function f9f04 = fm.getFunctionAt(a9f04);
        if (f9f04 != null) {
            Address end9f04 = toAddr(0x600aa1d7);
            println("Expanding BTU_Task 0x600a9f04 to span 0x600a9f04 - " + end9f04);
            f9f04.setBody(new AddressSet(a9f04, end9f04));
        }
        
        println("FixSpuriousSplits completed successfully.");
    }
}
