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

        // 6. Fix printf / snprintf family boundaries around 0x600cdc90..0x600cddc8
        Address acdc90 = toAddr(0x600cdc90);
        Function fcdc90 = fm.getFunctionAt(acdc90);
        if (fcdc90 != null) {
            fcdc90.setBody(new AddressSet(acdc90, toAddr(0x600cdc9f)));
        }

        Address acdca0 = toAddr(0x600cdca0);
        Function fcdca0 = fm.getFunctionAt(acdca0);
        if (fcdca0 == null) {
            createFunction(acdca0, "FUN_600cdca0");
            fcdca0 = fm.getFunctionAt(acdca0);
        }
        if (fcdca0 != null) {
            fcdca0.setBody(new AddressSet(acdca0, toAddr(0x600cdcc3)));
        }

        Address acdcc4 = toAddr(0x600cdcc4);
        Function fcdcc4 = fm.getFunctionAt(acdcc4);
        if (fcdcc4 != null) {
            fcdcc4.setBody(new AddressSet(acdcc4, toAddr(0x600cdd2b)));
        }

        Address acdd2c = toAddr(0x600cdd2c);
        Function fcdd2c = fm.getFunctionAt(acdd2c);
        if (fcdd2c == null) {
            createFunction(acdd2c, "FUN_600cdd2c");
            fcdd2c = fm.getFunctionAt(acdd2c);
        }
        if (fcdd2c != null) {
            fcdd2c.setBody(new AddressSet(acdd2c, toAddr(0x600cdd6b)));
        }

        Address acdd6c = toAddr(0x600cdd6c);
        Function fcdd6c = fm.getFunctionAt(acdd6c);
        if (fcdd6c != null) {
            fcdd6c.setBody(new AddressSet(acdd6c, toAddr(0x600cdd87)));
        }

        Address acdd88 = toAddr(0x600cdd88);
        Function fcdd88 = fm.getFunctionAt(acdd88);
        if (fcdd88 == null) {
            createFunction(acdd88, "FUN_600cdd88");
            fcdd88 = fm.getFunctionAt(acdd88);
        }
        if (fcdd88 != null) {
            fcdd88.setBody(new AddressSet(acdd88, toAddr(0x600cddb3)));
        }

        Address acddb4 = toAddr(0x600cddb4);
        Function fcddb4 = fm.getFunctionAt(acddb4);
        if (fcddb4 != null) {
            fcddb4.setBody(new AddressSet(acddb4, toAddr(0x600cddc7)));
        }

        Address acddc8 = toAddr(0x600cddc8);
        Function fcddc8 = fm.getFunctionAt(acddc8);
        if (fcddc8 != null) {
            fcddc8.setBody(new AddressSet(acddc8, toAddr(0x600cdfa0)));
        }

        // 7. Define function boundary for _raise_r at 0x601023fa
        Address a1023fa = toAddr(0x601023fa);
        disassemble(a1023fa);
        Function f1023fa = fm.getFunctionAt(a1023fa);
        if (f1023fa == null) {
            createFunction(a1023fa, "FUN_601023fa");
            f1023fa = fm.getFunctionAt(a1023fa);
        }
        if (f1023fa != null) {
            f1023fa.setBody(new AddressSet(a1023fa, toAddr(0x60102449)));
        }

        // 8. Fix 0x600cea74 boundary (132 bytes: 0x600cea74..0x600ceaf7)
        Address aea74 = toAddr(0x600cea74);
        Function fea74 = fm.getFunctionAt(aea74);
        if (fea74 != null) {
            fea74.setBody(new AddressSet(aea74, toAddr(0x600ceaf7)));
        }

        // 9. Fix 0x600cf63e boundary (32 bytes: 0x600cf63e..0x600cf65d)
        Address af63e = toAddr(0x600cf63e);
        Function ff63e = fm.getFunctionAt(af63e);
        if (ff63e != null) {
            ff63e.setBody(new AddressSet(af63e, toAddr(0x600cf65d)));
        }
        
        // 10. Fix 0x600da590 boundary (6 bytes: 0x600da590..0x600da595)
        Address ada590 = toAddr(0x600da590);
        Function fda590 = fm.getFunctionAt(ada590);
        if (fda590 != null) {
            fda590.setBody(new AddressSet(ada590, toAddr(0x600da595)));
        }
        
        // 11. Fix 0x600db8e8 boundary (8 bytes: 0x600db8e8..0x600db8ef)
        Address adb8e8 = toAddr(0x600db8e8);
        Function fdb8e8 = fm.getFunctionAt(adb8e8);
        if (fdb8e8 != null) {
            fdb8e8.setBody(new AddressSet(adb8e8, toAddr(0x600db8ef)));
        }
        
        Address adb8f0 = toAddr(0x600db8f0);
        Function fdb8f0 = fm.getFunctionAt(adb8f0);
        if (fdb8f0 == null) {
            createFunction(adb8f0, "FUN_600db8f0");
            fdb8f0 = fm.getFunctionAt(adb8f0);
        }
        if (fdb8f0 != null) {
            fdb8f0.setBody(new AddressSet(adb8f0, toAddr(0x600db901)));
        }
        
        // 12. Fix 0x600dc124 boundary (28 bytes: 0x600dc124..0x600dc13f)
        Address adc124 = toAddr(0x600dc124);
        Function fdc124 = fm.getFunctionAt(adc124);
        if (fdc124 != null) {
            fdc124.setBody(new AddressSet(adc124, toAddr(0x600dc13f)));
        }
        
        Address adc140 = toAddr(0x600dc140);
        Function fdc140 = fm.getFunctionAt(adc140);
        if (fdc140 == null) {
            createFunction(adc140, "FUN_600dc140");
            fdc140 = fm.getFunctionAt(adc140);
        }
        if (fdc140 != null) {
            fdc140.setBody(new AddressSet(adc140, toAddr(0x600dc19d)));
        }
        
        // 13. Fix 0x600dc9c0 boundary (184 bytes: 0x600dc9c0..0x600dca77) merging spurious 0x600dca10
        Address adca10 = toAddr(0x600dca10);
        Function fdca10 = fm.getFunctionAt(adca10);
        if (fdca10 != null) {
            println("Removing spurious split function at " + adca10);
            fm.removeFunction(adca10);
        }
        Address adc9c0 = toAddr(0x600dc9c0);
        Function fdc9c0 = fm.getFunctionAt(adc9c0);
        if (fdc9c0 != null) {
            fdc9c0.setBody(new AddressSet(adc9c0, toAddr(0x600dca77)));
        }
        
        // 14. Fix 0x600de54a boundary (56 bytes: 0x600de54a..0x600de581)
        Address ade54a = toAddr(0x600de54a);
        Function fde54a = fm.getFunctionAt(ade54a);
        if (fde54a != null) {
            fde54a.setBody(new AddressSet(ade54a, toAddr(0x600de581)));
        }
        
        // 15. Fix 0x600de6e8 boundary (22 bytes: 0x600de6e8..0x600de6fd)
        Address ade6e8 = toAddr(0x600de6e8);
        Function fde6e8 = fm.getFunctionAt(ade6e8);
        if (fde6e8 != null) {
            fde6e8.setBody(new AddressSet(ade6e8, toAddr(0x600de6fd)));
        }
        
        // 16. Fix 0x600dee28 boundary (152 bytes: 0x600dee28..0x600deebf)
        Address adee28 = toAddr(0x600dee28);
        Function fdee28 = fm.getFunctionAt(adee28);
        if (fdee28 != null) {
            fdee28.setBody(new AddressSet(adee28, toAddr(0x600deebf)));
        }
        
        // 17. Fix 0x600e049a boundary (46 bytes: 0x600e049a..0x600e04c7)
        Address ade049a = toAddr(0x600e049a);
        Function fde049a = fm.getFunctionAt(ade049a);
        if (fde049a != null) {
            fde049a.setBody(new AddressSet(ade049a, toAddr(0x600e04c7)));
        }
        
        // 18. Fix 0x600e0be8 boundary (6 bytes: 0x600e0be8..0x600e0bed)
        Address ade0be8 = toAddr(0x600e0be8);
        Function fde0be8 = fm.getFunctionAt(ade0be8);
        if (fde0be8 != null) {
            fde0be8.setBody(new AddressSet(ade0be8, toAddr(0x600e0bed)));
        }
        
        // 19. Fix 0x600e0bee boundary (16 bytes: 0x600e0bee..0x600e0bfd)
        Address ade0bee = toAddr(0x600e0bee);
        Function fde0bee = fm.getFunctionAt(ade0bee);
        if (fde0bee != null) {
            fde0bee.setBody(new AddressSet(ade0bee, toAddr(0x600e0bfd)));
        }
        
        // 20. Fix 0x600e0d54 boundary (38 bytes: 0x600e0d54..0x600e0d79)
        Address ade0d54 = toAddr(0x600e0d54);
        Function fde0d54 = fm.getFunctionAt(ade0d54);
        if (fde0d54 != null) {
            fde0d54.setBody(new AddressSet(ade0d54, toAddr(0x600e0d79)));
        }
        
        // 21. Fix 0x600e63a4 boundary (150 bytes: 0x600e63a4..0x600e6439, removing spurious 0x600e63d0)
        Address ade63d0 = toAddr(0x600e63d0);
        Function fde63d0 = fm.getFunctionAt(ade63d0);
        if (fde63d0 != null) {
            fm.removeFunction(ade63d0);
        }
        Address ade63a4 = toAddr(0x600e63a4);
        Function fde63a4 = fm.getFunctionAt(ade63a4);
        if (fde63a4 != null) {
            fde63a4.setBody(new AddressSet(ade63a4, toAddr(0x600e6439)));
        }
        
        println("FixSpuriousSplits completed successfully.");
    }
}


