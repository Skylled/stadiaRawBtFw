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
        
        // 22. Fix 0x600e6dfe boundary (40 bytes: 0x600e6dfe..0x600e6e25)
        Address ade6dfe = toAddr(0x600e6dfe);
        Function fde6dfe = fm.getFunctionAt(ade6dfe);
        if (fde6dfe != null) {
            fde6dfe.setBody(new AddressSet(ade6dfe, toAddr(0x600e6e25)));
        }
        
        // 23. Fix 0x600e70ba boundary (40 bytes: 0x600e70ba..0x600e70e1)
        Address ade70ba = toAddr(0x600e70ba);
        Function fde70ba = fm.getFunctionAt(ade70ba);
        if (fde70ba != null) {
            fde70ba.setBody(new AddressSet(ade70ba, toAddr(0x600e70e1)));
        }
        
        // 24. Fix 0x600e70e2 boundary (312 bytes: 0x600e70e2..0x600e7219, removing spurious 0x600e7124)
        Address ade7124 = toAddr(0x600e7124);
        Function fde7124 = fm.getFunctionAt(ade7124);
        if (fde7124 != null) {
            fm.removeFunction(ade7124);
        }
        Address ade70e2 = toAddr(0x600e70e2);
        Function fde70e2 = fm.getFunctionAt(ade70e2);
        if (fde70e2 == null) {
            createFunction(ade70e2, "FUN_600e70e2");
            fde70e2 = fm.getFunctionAt(ade70e2);
        }
        if (fde70e2 != null) {
            fde70e2.setBody(new AddressSet(ade70e2, toAddr(0x600e7219)));
        }
        
        // 25. Create 0x600e7356 function (28 bytes: 0x600e7356..0x600e7371)
        Address ade7356 = toAddr(0x600e7356);
        Function fde7356 = fm.getFunctionAt(ade7356);
        if (fde7356 == null) {
            createFunction(ade7356, "FUN_600e7356");
            fde7356 = fm.getFunctionAt(ade7356);
        }
        if (fde7356 != null) {
            fde7356.setBody(new AddressSet(ade7356, toAddr(0x600e7371)));
        }
        
        // 26. Create 0x600e9dd6 function (20 bytes: 0x600e9dd6..0x600e9de9)
        Address ade9dd6 = toAddr(0x600e9dd6);
        Function fde9dd6 = fm.getFunctionAt(ade9dd6);
        if (fde9dd6 == null) {
            createFunction(ade9dd6, "FUN_600e9dd6");
            fde9dd6 = fm.getFunctionAt(ade9dd6);
        }
        if (fde9dd6 != null) {
            fde9dd6.setBody(new AddressSet(ade9dd6, toAddr(0x600e9de9)));
        }
        
        // 27. Fix 0x600ea1a0 boundary (634 bytes: 0x600ea1a0..0x600ea419)
        Address adea1a0 = toAddr(0x600ea1a0);
        Function fdea1a0 = fm.getFunctionAt(adea1a0);
        if (fdea1a0 != null) {
            fdea1a0.setBody(new AddressSet(adea1a0, toAddr(0x600ea419)));
        }
        
        // 28. Fix 0x600ea438 boundary (638 bytes: 0x600ea438..0x600ea6b5)
        Address adea438 = toAddr(0x600ea438);
        Function fdea438 = fm.getFunctionAt(adea438);
        if (fdea438 != null) {
            fdea438.setBody(new AddressSet(adea438, toAddr(0x600ea6b5)));
        }
        
        // 29. Create 0x600ea6b6 function (46 bytes: 0x600ea6b6..0x600ea6e3)
        Address adea6b6 = toAddr(0x600ea6b6);
        Function fdea6b6 = fm.getFunctionAt(adea6b6);
        if (fdea6b6 == null) {
            createFunction(adea6b6, "FUN_600ea6b6");
            fdea6b6 = fm.getFunctionAt(adea6b6);
        }
        if (fdea6b6 != null) {
            fdea6b6.setBody(new AddressSet(adea6b6, toAddr(0x600ea6e3)));
        }
        
        // 30. Create 0x600ea868 function (6 bytes: 0x600ea868..0x600ea86d)
        Address adea868 = toAddr(0x600ea868);
        Function fdea868 = fm.getFunctionAt(adea868);
        if (fdea868 == null) {
            createFunction(adea868, "FUN_600ea868");
            fdea868 = fm.getFunctionAt(adea868);
        }
        if (fdea868 != null) {
            fdea868.setBody(new AddressSet(adea868, toAddr(0x600ea86d)));
        }
        
        // 31. Create 0x600ea87a function (12 bytes: 0x600ea87a..0x600ea885)
        Address adea87a = toAddr(0x600ea87a);
        Function fdea87a = fm.getFunctionAt(adea87a);
        if (fdea87a == null) {
            createFunction(adea87a, "FUN_600ea87a");
            fdea87a = fm.getFunctionAt(adea87a);
        }
        if (fdea87a != null) {
            fdea87a.setBody(new AddressSet(adea87a, toAddr(0x600ea885)));
        }
        
        // 32. Create 0x600eab58 function (52 bytes: 0x600eab58..0x600eab8b)
        Address adeab58 = toAddr(0x600eab58);
        Function fdeab58 = fm.getFunctionAt(adeab58);
        if (fdeab58 == null) {
            createFunction(adeab58, "FUN_600eab58");
            fdeab58 = fm.getFunctionAt(adeab58);
        }
        if (fdeab58 != null) {
            fdeab58.setBody(new AddressSet(adeab58, toAddr(0x600eab8b)));
        }
        
        // 33. Create 0x600eadee function (232 bytes: 0x600eadee..0x600eaed5)
        Address adeadee = toAddr(0x600eadee);
        Function fdeadee = fm.getFunctionAt(adeadee);
        if (fdeadee == null) {
            createFunction(adeadee, "FUN_600eadee");
            fdeadee = fm.getFunctionAt(adeadee);
        }
        if (fdeadee != null) {
            fdeadee.setBody(new AddressSet(adeadee, toAddr(0x600eaed5)));
        }
        
        // 34. Create 0x600eaf26 function (24 bytes: 0x600eaf26..0x600eaf3d)
        Address adeaf26 = toAddr(0x600eaf26);
        Function fdeaf26 = fm.getFunctionAt(adeaf26);
        if (fdeaf26 == null) {
            createFunction(adeaf26, "FUN_600eaf26");
            fdeaf26 = fm.getFunctionAt(adeaf26);
        }
        if (fdeaf26 != null) {
            fdeaf26.setBody(new AddressSet(adeaf26, toAddr(0x600eaf3d)));
        }
        
        // 35. Create 0x600eb146 function (16 bytes: 0x600eb146..0x600eb155)
        Address adeb146 = toAddr(0x600eb146);
        Function fdeb146 = fm.getFunctionAt(adeb146);
        if (fdeb146 == null) {
            createFunction(adeb146, "FUN_600eb146");
            fdeb146 = fm.getFunctionAt(adeb146);
        }
        if (fdeb146 != null) {
            fdeb146.setBody(new AddressSet(adeb146, toAddr(0x600eb155)));
        }
        
        // 36. Create 0x600eb192 function (10 bytes: 0x600eb192..0x600eb19b)
        Address adeb192 = toAddr(0x600eb192);
        Function fdeb192 = fm.getFunctionAt(adeb192);
        if (fdeb192 == null) {
            createFunction(adeb192, "FUN_600eb192");
            fdeb192 = fm.getFunctionAt(adeb192);
        }
        if (fdeb192 != null) {
            fdeb192.setBody(new AddressSet(adeb192, toAddr(0x600eb19b)));
        }
        
        // 37. Fix 0x600eb19c boundary (56 bytes: 0x600eb19c..0x600eb1d3)
        Address adeb19c = toAddr(0x600eb19c);
        Function fdeb19c = fm.getFunctionAt(adeb19c);
        if (fdeb19c != null) {
            fdeb19c.setBody(new AddressSet(adeb19c, toAddr(0x600eb1d3)));
        }
        
        // 38. Create 0x600eb280 function (240 bytes: 0x600eb280..0x600eb36f)
        Address adeb280 = toAddr(0x600eb280);
        Function fdeb280 = fm.getFunctionAt(adeb280);
        if (fdeb280 == null) {
            createFunction(adeb280, "FUN_600eb280");
            fdeb280 = fm.getFunctionAt(adeb280);
        }
        if (fdeb280 != null) {
            fdeb280.setBody(new AddressSet(adeb280, toAddr(0x600eb36f)));
        }
        
        // 39. Create 0x600eb3a4 function (92 bytes: 0x600eb3a4..0x600eb3ff)
        Address adeb3a4 = toAddr(0x600eb3a4);
        Function fdeb3a4 = fm.getFunctionAt(adeb3a4);
        if (fdeb3a4 == null) {
            createFunction(adeb3a4, "FUN_600eb3a4");
            fdeb3a4 = fm.getFunctionAt(adeb3a4);
        }
        if (fdeb3a4 != null) {
            fdeb3a4.setBody(new AddressSet(adeb3a4, toAddr(0x600eb3ff)));
        }
        
        // 40. Fix 0x600eb400 boundary (40 bytes: 0x600eb400..0x600eb427)
        Address adeb400 = toAddr(0x600eb400);
        Function fdeb400 = fm.getFunctionAt(adeb400);
        if (fdeb400 != null) {
            fdeb400.setBody(new AddressSet(adeb400, toAddr(0x600eb427)));
        }
        
        // 41. Create 0x600eb4b0 function (178 bytes: 0x600eb4b0..0x600eb561)
        Address adeb4b0 = toAddr(0x600eb4b0);
        Function fdeb4b0 = fm.getFunctionAt(adeb4b0);
        if (fdeb4b0 == null) {
            createFunction(adeb4b0, "FUN_600eb4b0");
            fdeb4b0 = fm.getFunctionAt(adeb4b0);
        }
        if (fdeb4b0 != null) {
            fdeb4b0.setBody(new AddressSet(adeb4b0, toAddr(0x600eb561)));
        }
        
        // 42. Create 0x600eb8b6 function (6 bytes: 0x600eb8b6..0x600eb8bb)
        Address adeb8b6 = toAddr(0x600eb8b6);
        Function fdeb8b6 = fm.getFunctionAt(adeb8b6);
        if (fdeb8b6 == null) {
            createFunction(adeb8b6, "FUN_600eb8b6");
            fdeb8b6 = fm.getFunctionAt(adeb8b6);
        }
        if (fdeb8b6 != null) {
            fdeb8b6.setBody(new AddressSet(adeb8b6, toAddr(0x600eb8bb)));
        }
        
        // 43. Create 0x600eb8bc function (154 bytes: 0x600eb8bc..0x600eb955)
        Address adeb8bc = toAddr(0x600eb8bc);
        Function fdeb8bc = fm.getFunctionAt(adeb8bc);
        if (fdeb8bc == null) {
            createFunction(adeb8bc, "FUN_600eb8bc");
            fdeb8bc = fm.getFunctionAt(adeb8bc);
        }
        if (fdeb8bc != null) {
            fdeb8bc.setBody(new AddressSet(adeb8bc, toAddr(0x600eb955)));
        }
        
        // 44. Create 0x600eb956 function (6 bytes: 0x600eb956..0x600eb95b)
        Address adeb956 = toAddr(0x600eb956);
        Function fdeb956 = fm.getFunctionAt(adeb956);
        if (fdeb956 == null) {
            createFunction(adeb956, "FUN_600eb956");
            fdeb956 = fm.getFunctionAt(adeb956);
        }
        if (fdeb956 != null) {
            fdeb956.setBody(new AddressSet(adeb956, toAddr(0x600eb95b)));
        }
        
        // 45. Create 0x600eb95c function (198 bytes: 0x600eb95c..0x600eba21)
        Address adeb95c = toAddr(0x600eb95c);
        Function fdeb95c = fm.getFunctionAt(adeb95c);
        if (fdeb95c == null) {
            createFunction(adeb95c, "FUN_600eb95c");
            fdeb95c = fm.getFunctionAt(adeb95c);
        }
        if (fdeb95c != null) {
            fdeb95c.setBody(new AddressSet(adeb95c, toAddr(0x600eba21)));
        }
        
        // 46. Create 0x600eba22 function (10 bytes: 0x600eba22..0x600eba2b)
        Address adeba22 = toAddr(0x600eba22);
        Function fdeba22 = fm.getFunctionAt(adeba22);
        if (fdeba22 == null) {
            createFunction(adeba22, "FUN_600eba22");
            fdeba22 = fm.getFunctionAt(adeba22);
        }
        if (fdeba22 != null) {
            fdeba22.setBody(new AddressSet(adeba22, toAddr(0x600eba2b)));
        }
        
        // 47. Fix 0x600ebf2c boundary (8 bytes: 0x600ebf2c..0x600ebf33)
        Address adebf2c = toAddr(0x600ebf2c);
        Function fdebf2c = fm.getFunctionAt(adebf2c);
        if (fdebf2c != null) {
            fdebf2c.setBody(new AddressSet(adebf2c, toAddr(0x600ebf33)));
        }
        
        // 48. Create 0x600ebf52 function (6 bytes: 0x600ebf52..0x600ebf57)
        Address adebf52 = toAddr(0x600ebf52);
        Function fdebf52 = fm.getFunctionAt(adebf52);
        if (fdebf52 == null) {
            createFunction(adebf52, "FUN_600ebf52");
            fdebf52 = fm.getFunctionAt(adebf52);
        }
        if (fdebf52 != null) {
            fdebf52.setBody(new AddressSet(adebf52, toAddr(0x600ebf57)));
        }
        
        // 49. Create 0x600ebf64 function (6 bytes: 0x600ebf64..0x600ebf69)
        Address adebf64 = toAddr(0x600ebf64);
        Function fdebf64 = fm.getFunctionAt(adebf64);
        if (fdebf64 == null) {
            createFunction(adebf64, "FUN_600ebf64");
            fdebf64 = fm.getFunctionAt(adebf64);
        }
        if (fdebf64 != null) {
            fdebf64.setBody(new AddressSet(adebf64, toAddr(0x600ebf69)));
        }
        
        // 50. Create 0x600ebf6a function (12 bytes: 0x600ebf6a..0x600ebf75)
        Address adebf6a = toAddr(0x600ebf6a);
        Function fdebf6a = fm.getFunctionAt(adebf6a);
        if (fdebf6a == null) {
            createFunction(adebf6a, "FUN_600ebf6a");
            fdebf6a = fm.getFunctionAt(adebf6a);
        }
        if (fdebf6a != null) {
            fdebf6a.setBody(new AddressSet(adebf6a, toAddr(0x600ebf75)));
        }
        
        // 51. Create 0x600ebf76 function (6 bytes: 0x600ebf76..0x600ebf7b)
        Address adebf76 = toAddr(0x600ebf76);
        Function fdebf76 = fm.getFunctionAt(adebf76);
        if (fdebf76 == null) {
            createFunction(adebf76, "FUN_600ebf76");
            fdebf76 = fm.getFunctionAt(adebf76);
        }
        if (fdebf76 != null) {
            fdebf76.setBody(new AddressSet(adebf76, toAddr(0x600ebf7b)));
        }
        
        // 52. Create 0x600ec12c function (180 bytes: 0x600ec12c..0x600ec1df)
        Address adec12c = toAddr(0x600ec12c);
        Function fdec12c = fm.getFunctionAt(adec12c);
        if (fdec12c == null) {
            createFunction(adec12c, "FUN_600ec12c");
            fdec12c = fm.getFunctionAt(adec12c);
        }
        if (fdec12c != null) {
            fdec12c.setBody(new AddressSet(adec12c, toAddr(0x600ec1df)));
        }
        
        // 53. Create 0x600ec1e0 function (316 bytes: 0x600ec1e0..0x600ec31b)
        Address adec1e0 = toAddr(0x600ec1e0);
        Function fdec1e0 = fm.getFunctionAt(adec1e0);
        if (fdec1e0 == null) {
            createFunction(adec1e0, "FUN_600ec1e0");
            fdec1e0 = fm.getFunctionAt(adec1e0);
        }
        if (fdec1e0 != null) {
            fdec1e0.setBody(new AddressSet(adec1e0, toAddr(0x600ec31b)));
        }
        
        // 54. Create 0x600ec31c function (46 bytes: 0x600ec31c..0x600ec349)
        Address adec31c = toAddr(0x600ec31c);
        Function fdec31c = fm.getFunctionAt(adec31c);
        if (fdec31c == null) {
            createFunction(adec31c, "FUN_600ec31c");
            fdec31c = fm.getFunctionAt(adec31c);
        }
        if (fdec31c != null) {
            fdec31c.setBody(new AddressSet(adec31c, toAddr(0x600ec349)));
        }
        
        // 55. Fix 0x600ec584 boundary (6 bytes: 0x600ec584..0x600ec589)
        Address adec584 = toAddr(0x600ec584);
        Function fdec584 = fm.getFunctionAt(adec584);
        if (fdec584 != null) {
            fdec584.setBody(new AddressSet(adec584, toAddr(0x600ec589)));
        }
        
        // 56. Fix 0x600ec7ca boundary (234 bytes: 0x600ec7ca..0x600ec8b3)
        Address adec7ca = toAddr(0x600ec7ca);
        Function fdec7ca = fm.getFunctionAt(adec7ca);
        if (fdec7ca != null) {
            fdec7ca.setBody(new AddressSet(adec7ca, toAddr(0x600ec8b3)));
        }
        
        // 57. Create 0x600ec9c4 function (6 bytes: 0x600ec9c4..0x600ec9c9)
        Address adec9c4 = toAddr(0x600ec9c4);
        Function fdec9c4 = fm.getFunctionAt(adec9c4);
        if (fdec9c4 == null) {
            createFunction(adec9c4, "FUN_600ec9c4");
            fdec9c4 = fm.getFunctionAt(adec9c4);
        }
        if (fdec9c4 != null) {
            fdec9c4.setBody(new AddressSet(adec9c4, toAddr(0x600ec9c9)));
        }
        
        // 58. Create 0x600ec9ec function (22 bytes: 0x600ec9ec..0x600eca01)
        Address adec9ec = toAddr(0x600ec9ec);
        Function fdec9ec = fm.getFunctionAt(adec9ec);
        if (fdec9ec == null) {
            createFunction(adec9ec, "FUN_600ec9ec");
            fdec9ec = fm.getFunctionAt(adec9ec);
        }
        if (fdec9ec != null) {
            fdec9ec.setBody(new AddressSet(adec9ec, toAddr(0x600eca01)));
        }
        
        // 59. Create 0x600eca56 function (48 bytes: 0x600eca56..0x600eca85)
        Address adeca56 = toAddr(0x600eca56);
        Function fdeca56 = fm.getFunctionAt(adeca56);
        if (fdeca56 == null) {
            createFunction(adeca56, "FUN_600eca56");
            fdeca56 = fm.getFunctionAt(adeca56);
        }
        if (fdeca56 != null) {
            fdeca56.setBody(new AddressSet(adeca56, toAddr(0x600eca85)));
        }
        
        // 60. Fix 0x600eca86 boundary (56 bytes: 0x600eca86..0x600ecabd)
        Address adeca86 = toAddr(0x600eca86);
        Function fdeca86 = fm.getFunctionAt(adeca86);
        if (fdeca86 != null) {
            fdeca86.setBody(new AddressSet(adeca86, toAddr(0x600ecabd)));
        }
        
        // 61. Fix 0x600ecabe boundary (140 bytes: 0x600ecabe..0x600ecb49)
        Address adecabe = toAddr(0x600ecabe);
        Function fdecabe = fm.getFunctionAt(adecabe);
        if (fdecabe != null) {
            fdecabe.setBody(new AddressSet(adecabe, toAddr(0x600ecb49)));
        }
        
        // 62. Create 0x600ecb4a function (6 bytes: 0x600ecb4a..0x600ecb4f)
        Address adecb4a = toAddr(0x600ecb4a);
        Function fdecb4a = fm.getFunctionAt(adecb4a);
        if (fdecb4a == null) {
            createFunction(adecb4a, "FUN_600ecb4a");
            fdecb4a = fm.getFunctionAt(adecb4a);
        }
        if (fdecb4a != null) {
            fdecb4a.setBody(new AddressSet(adecb4a, toAddr(0x600ecb4f)));
        }
        
        // 63. Create 0x600ecb50 function (30 bytes: 0x600ecb50..0x600ecb6d)
        Address adecb50 = toAddr(0x600ecb50);
        Function fdecb50 = fm.getFunctionAt(adecb50);
        if (fdecb50 == null) {
            createFunction(adecb50, "FUN_600ecb50");
            fdecb50 = fm.getFunctionAt(adecb50);
        }
        if (fdecb50 != null) {
            fdecb50.setBody(new AddressSet(adecb50, toAddr(0x600ecb6d)));
        }
        
        // 64. Create 0x600ecb6e function (4 bytes: 0x600ecb6e..0x600ecb71)
        Address adecb6e = toAddr(0x600ecb6e);
        Function fdecb6e = fm.getFunctionAt(adecb6e);
        if (fdecb6e == null) {
            createFunction(adecb6e, "FUN_600ecb6e");
            fdecb6e = fm.getFunctionAt(adecb6e);
        }
        if (fdecb6e != null) {
            fdecb6e.setBody(new AddressSet(adecb6e, toAddr(0x600ecb71)));
        }
        
        // 65. Fix 0x600ecc98 boundary (60 bytes: 0x600ecc98..0x600eccd3)
        Function fdeccbe = fm.getFunctionAt(toAddr(0x600eccbe));
        if (fdeccbe != null) {
            fm.removeFunction(toAddr(0x600eccbe));
        }
        Address adecc98 = toAddr(0x600ecc98);
        Function fdecc98 = fm.getFunctionAt(adecc98);
        if (fdecc98 != null) {
            fdecc98.setBody(new AddressSet(adecc98, toAddr(0x600eccd3)));
        }
        
        // 66. Fix 0x600ed380 boundary (24 bytes: 0x600ed380..0x600ed397)
        Function fded38e = fm.getFunctionAt(toAddr(0x600ed38e));
        if (fded38e != null) {
            fm.removeFunction(toAddr(0x600ed38e));
        }
        Address aded380 = toAddr(0x600ed380);
        Function fded380 = fm.getFunctionAt(aded380);
        if (fded380 != null) {
            fded380.setBody(new AddressSet(aded380, toAddr(0x600ed397)));
        }
        
        // 67. Create 0x600ed840 function (38 bytes: 0x600ed840..0x600ed865)
        Address aded840 = toAddr(0x600ed840);
        Function fded840 = fm.getFunctionAt(aded840);
        if (fded840 == null) {
            createFunction(aded840, "FUN_600ed840");
            fded840 = fm.getFunctionAt(aded840);
        }
        if (fded840 != null) {
            fded840.setBody(new AddressSet(aded840, toAddr(0x600ed865)));
        }

        // 68. Create 0x600ed866 function (26 bytes: 0x600ed866..0x600ed87f)
        Address aded866 = toAddr(0x600ed866);
        Function fded866 = fm.getFunctionAt(aded866);
        if (fded866 == null) {
            createFunction(aded866, "FUN_600ed866");
            fded866 = fm.getFunctionAt(aded866);
        }
        if (fded866 != null) {
            fded866.setBody(new AddressSet(aded866, toAddr(0x600ed87f)));
        }

        // 69. Fix 0x600ed656 boundary (24 bytes: 0x600ed656..0x600ed66d)
        Address aded656 = toAddr(0x600ed656);
        Function fded656 = fm.getFunctionAt(aded656);
        if (fded656 != null) {
            fded656.setBody(new AddressSet(aded656, toAddr(0x600ed66d)));
        }

        // 70. Create 0x600edb6e function (90 bytes: 0x600edb6e..0x600edbc7)
        Address adedb6e = toAddr(0x600edb6e);
        Function fdedb6e = fm.getFunctionAt(adedb6e);
        if (fdedb6e == null) {
            createFunction(adedb6e, "FUN_600edb6e");
            fdedb6e = fm.getFunctionAt(adedb6e);
        }
        if (fdedb6e != null) {
            fdedb6e.setBody(new AddressSet(adedb6e, toAddr(0x600edbc7)));
        }

        // 71. Fix 0x600edbc8 boundary (44 bytes: 0x600edbc8..0x600edbf3)
        Address adedbc8 = toAddr(0x600edbc8);
        Function fdedbc8 = fm.getFunctionAt(adedbc8);
        if (fdedbc8 != null) {
            fdedbc8.setBody(new AddressSet(adedbc8, toAddr(0x600edbf3)));
        }

        // 72. Create 0x600edc44 function (8 bytes: 0x600edc44..0x600edc4b)
        Address adedc44 = toAddr(0x600edc44);
        Function fdedc44 = fm.getFunctionAt(adedc44);
        if (fdedc44 == null) {
            createFunction(adedc44, "FUN_600edc44");
            fdedc44 = fm.getFunctionAt(adedc44);
        }
        if (fdedc44 != null) {
            fdedc44.setBody(new AddressSet(adedc44, toAddr(0x600edc4b)));
        }

        // 73. Create 0x600edc4c function (6 bytes: 0x600edc4c..0x600edc51)
        Address adedc4c = toAddr(0x600edc4c);
        Function fdedc4c = fm.getFunctionAt(adedc4c);
        if (fdedc4c == null) {
            createFunction(adedc4c, "FUN_600edc4c");
            fdedc4c = fm.getFunctionAt(adedc4c);
        }
        if (fdedc4c != null) {
            fdedc4c.setBody(new AddressSet(adedc4c, toAddr(0x600edc51)));
        }

        // 74. Create 0x600edc80 function (8 bytes: 0x600edc80..0x600edc87)
        Address adedc80 = toAddr(0x600edc80);
        Function fdedc80 = fm.getFunctionAt(adedc80);
        if (fdedc80 == null) {
            createFunction(adedc80, "FUN_600edc80");
            fdedc80 = fm.getFunctionAt(adedc80);
        }
        if (fdedc80 != null) {
            fdedc80.setBody(new AddressSet(adedc80, toAddr(0x600edc87)));
        }

        // 75. Fix 0x600edffe boundary (30 bytes: 0x600edffe..0x600ee01b)
        Address adedffe = toAddr(0x600edffe);
        Function fdedffe = fm.getFunctionAt(adedffe);
        if (fdedffe != null) {
            fdedffe.setBody(new AddressSet(adedffe, toAddr(0x600ee01b)));
        }

        // 76. Fix 0x600fab0c / 0x600fab28 boundary split (50 bytes: 0x600fab0c..0x600fab3d)
        Address afab0c = toAddr(0x600fab0c);
        Address afab28 = toAddr(0x600fab28);
        Function ffab28 = fm.getFunctionAt(afab28);
        if (ffab28 != null) {
            println("Removing spurious split function at " + afab28);
            fm.removeFunction(afab28);
        }
        Function ffab0c = fm.getFunctionAt(afab0c);
        if (ffab0c != null) {
            Address endfab0c = toAddr(0x600fab0c + 50 - 1);
            ffab0c.setBody(new AddressSet(afab0c, endfab0c));
        }

        // 77. Fix 0x600facc4 / 0x600fad24 boundary split (98 bytes: 0x600facc4..0x600fad25)
        Address afacc4 = toAddr(0x600facc4);
        Address afad24 = toAddr(0x600fad24);
        Function ffad24 = fm.getFunctionAt(afad24);
        if (ffad24 != null) {
            println("Removing spurious split function at " + afad24);
            fm.removeFunction(afad24);
        }
        Function ffacc4 = fm.getFunctionAt(afacc4);
        if (ffacc4 != null) {
            Address endfacc4 = toAddr(0x600facc4 + 98 - 1);
            ffacc4.setBody(new AddressSet(afacc4, endfacc4));
        }

        // 78. Create missing function 0x600faea4 (32 bytes: 0x600faea4..0x600faec3)
        Address afaea4 = toAddr(0x600faea4);
        Function ffaea4 = fm.getFunctionAt(afaea4);
        if (ffaea4 == null) {
            createFunction(afaea4, "FUN_600faea4");
            ffaea4 = fm.getFunctionAt(afaea4);
        }
        if (ffaea4 != null) {
            ffaea4.setBody(new AddressSet(afaea4, toAddr(0x600faec3)));
        }

        // 79. Create missing function 0x600fbbd6 (22 bytes: 0x600fbbd6..0x600fbbeb)
        Address afbbd6 = toAddr(0x600fbbd6);
        Function ffbbd6 = fm.getFunctionAt(afbbd6);
        if (ffbbd6 == null) {
            createFunction(afbbd6, "FUN_600fbbd6");
            ffbbd6 = fm.getFunctionAt(afbbd6);
        }
        if (ffbbd6 != null) {
            ffbbd6.setBody(new AddressSet(afbbd6, toAddr(0x600fbbeb)));
        }

        // 80. Create missing function 0x600fbbec (22 bytes: 0x600fbbec..0x600fbc01)
        Address afbbec = toAddr(0x600fbbec);
        Function ffbbec = fm.getFunctionAt(afbbec);
        if (ffbbec == null) {
            createFunction(afbbec, "FUN_600fbbec");
            ffbbec = fm.getFunctionAt(afbbec);
        }
        if (ffbbec != null) {
            ffbbec.setBody(new AddressSet(afbbec, toAddr(0x600fbc01)));
        }

        // 81. Create missing function 0x600fc4c2 (22 bytes: 0x600fc4c2..0x600fc4d7)
        Address afc4c2 = toAddr(0x600fc4c2);
        Function ffc4c2 = fm.getFunctionAt(afc4c2);
        if (ffc4c2 == null) {
            createFunction(afc4c2, "FUN_600fc4c2");
            ffc4c2 = fm.getFunctionAt(afc4c2);
        }
        if (ffc4c2 != null) {
            ffc4c2.setBody(new AddressSet(afc4c2, toAddr(0x600fc4d7)));
        }

        // 82. Create missing function 0x600fd14a (24 bytes: 0x600fd14a..0x600fd161)
        Address afd14a = toAddr(0x600fd14a);
        Function ffd14a = fm.getFunctionAt(afd14a);
        if (ffd14a == null) {
            createFunction(afd14a, "FUN_600fd14a");
            ffd14a = fm.getFunctionAt(afd14a);
        }
        if (ffd14a != null) {
            ffd14a.setBody(new AddressSet(afd14a, toAddr(0x600fd161)));
        }

        // 83. Merge spurious split at 0x600fe00e into 0x600fdff0 (106 bytes: 0x600fdff0..0x600fe059)
        Address afe00e = toAddr(0x600fe00e);
        Function ffe00e = fm.getFunctionAt(afe00e);
        if (ffe00e != null) {
            fm.removeFunction(afe00e);
        }
        Address afdff0 = toAddr(0x600fdff0);
        Function ffdff0 = fm.getFunctionAt(afdff0);
        if (ffdff0 != null) {
            ffdff0.setBody(new AddressSet(afdff0, toAddr(0x600fe059)));
        }

        // 84. Create missing function 0x600fe88c (22 bytes: 0x600fe88c..0x600fe8a1)
        Address afe88c = toAddr(0x600fe88c);
        Function ffe88c = fm.getFunctionAt(afe88c);
        if (ffe88c == null) {
            createFunction(afe88c, "FUN_600fe88c");
            ffe88c = fm.getFunctionAt(afe88c);
        }
        if (ffe88c != null) {
            ffe88c.setBody(new AddressSet(afe88c, toAddr(0x600fe8a1)));
        }

        // 85. Create missing function 0x600fe8a2 (116 bytes: 0x600fe8a2..0x600fe915)
        Address afe8a2 = toAddr(0x600fe8a2);
        Function ffe8a2 = fm.getFunctionAt(afe8a2);
        if (ffe8a2 == null) {
            createFunction(afe8a2, "FUN_600fe8a2");
            ffe8a2 = fm.getFunctionAt(afe8a2);
        }
        if (ffe8a2 != null) {
            ffe8a2.setBody(new AddressSet(afe8a2, toAddr(0x600fe915)));
        }

        // 86. Create missing function 0x60100a60 (82 bytes: 0x60100a60..0x60100ab1)
        Address a100a60 = toAddr(0x60100a60);
        Function f100a60 = fm.getFunctionAt(a100a60);
        if (f100a60 == null) {
            createFunction(a100a60, "FUN_60100a60");
            f100a60 = fm.getFunctionAt(a100a60);
        }
        if (f100a60 != null) {
            f100a60.setBody(new AddressSet(a100a60, toAddr(0x60100ab1)));
        }

        // 87. Fix 0x601013d0 boundary (204 bytes: 0x601013d0..0x6010149b) merging spurious 0x60101468 and 0x60101492
        Address a101468 = toAddr(0x60101468);
        Function f101468 = fm.getFunctionAt(a101468);
        if (f101468 != null) {
            println("Removing spurious split function at " + a101468);
            fm.removeFunction(a101468);
        }
        Address a101492 = toAddr(0x60101492);
        Function f101492 = fm.getFunctionAt(a101492);
        if (f101492 != null) {
            println("Removing spurious split function at " + a101492);
            fm.removeFunction(a101492);
        }
        Address a1013d0 = toAddr(0x601013d0);
        Function f1013d0 = fm.getFunctionAt(a1013d0);
        if (f1013d0 != null) {
            f1013d0.setBody(new AddressSet(a1013d0, toAddr(0x6010149b)));
        }

        // 88. Fix 0x6010149c boundary (46 bytes: 0x6010149c..0x601014c9) replacing spurious 0x601014a4
        Address a1014a4 = toAddr(0x601014a4);
        Function f1014a4 = fm.getFunctionAt(a1014a4);
        if (f1014a4 != null) {
            println("Removing spurious split function at " + a1014a4);
            fm.removeFunction(a1014a4);
        }
        Address a10149c = toAddr(0x6010149c);
        Function f10149c = fm.getFunctionAt(a10149c);
        if (f10149c == null) {
            createFunction(a10149c, "FUN_6010149c");
            f10149c = fm.getFunctionAt(a10149c);
        }
        if (f10149c != null) {
            f10149c.setBody(new AddressSet(a10149c, toAddr(0x601014c9)));
        }

        // 89. Fix 0x60101c48 cluster (48 bytes: 0x60101c48..0x60101c77)
        Address a101c48 = toAddr(0x60101c48);
        Function f101c48 = fm.getFunctionAt(a101c48);
        if (f101c48 != null) {
            f101c48.setBody(new AddressSet(a101c48, toAddr(0x60101c51)));
        }
        Address a101c52 = toAddr(0x60101c52);
        Function f101c52 = fm.getFunctionAt(a101c52);
        if (f101c52 != null) {
            f101c52.setBody(new AddressSet(a101c52, toAddr(0x60101c55)));
        }
        Address a101c5c = toAddr(0x60101c5c);
        Function f101c5c = fm.getFunctionAt(a101c5c);
        if (f101c5c != null) {
            fm.removeFunction(a101c5c);
        }
        Address a101c56 = toAddr(0x60101c56);
        Function f101c56 = fm.getFunctionAt(a101c56);
        if (f101c56 == null) {
            createFunction(a101c56, "FUN_60101c56");
            f101c56 = fm.getFunctionAt(a101c56);
        }
        if (f101c56 != null) {
            f101c56.setBody(new AddressSet(a101c56, toAddr(0x60101c5f)));
        }
        Address a101c60 = toAddr(0x60101c60);
        Function f101c60 = fm.getFunctionAt(a101c60);
        if (f101c60 != null) {
            f101c60.setBody(new AddressSet(a101c60, toAddr(0x60101c65)));
        }
        Address a101c66 = toAddr(0x60101c66);
        Function f101c66 = fm.getFunctionAt(a101c66);
        if (f101c66 == null) {
            createFunction(a101c66, "FUN_60101c66");
            f101c66 = fm.getFunctionAt(a101c66);
        }
        if (f101c66 != null) {
            f101c66.setBody(new AddressSet(a101c66, toAddr(0x60101c6d)));
        }
        Address a101c6e = toAddr(0x60101c6e);
        Function f101c6e = fm.getFunctionAt(a101c6e);
        if (f101c6e == null) {
            createFunction(a101c6e, "FUN_60101c6e");
            f101c6e = fm.getFunctionAt(a101c6e);
        }
        if (f101c6e != null) {
            f101c6e.setBody(new AddressSet(a101c6e, toAddr(0x60101c77)));
        }

        // 90. Create missing function 0x601020fe (36 bytes: 0x601020fe..0x60102121)
        Address a1020fe = toAddr(0x601020fe);
        Function f1020fe = fm.getFunctionAt(a1020fe);
        if (f1020fe == null) {
            createFunction(a1020fe, "FUN_601020fe");
            f1020fe = fm.getFunctionAt(a1020fe);
        }
        if (f1020fe != null) {
            f1020fe.setBody(new AddressSet(a1020fe, toAddr(0x60102121)));
        }

        // 91. Create missing function 0x6010258e (26 bytes: 0x6010258e..0x601025a7)
        Address a10258e = toAddr(0x6010258e);
        Function f10258e = fm.getFunctionAt(a10258e);
        if (f10258e == null) {
            createFunction(a10258e, "FUN_6010258e");
            f10258e = fm.getFunctionAt(a10258e);
        }
        if (f10258e != null) {
            f10258e.setBody(new AddressSet(a10258e, toAddr(0x601025a7)));
        }

        // 92. Create missing function 0x600d45e4 (4 bytes: 0x600d45e4..0x600d45e7)
        Address a00d45e4 = toAddr(0x600d45e4);
        Function f00d45e4 = fm.getFunctionAt(a00d45e4);
        if (f00d45e4 == null) {
            createFunction(a00d45e4, "thunk_FUN_600d45ba");
            f00d45e4 = fm.getFunctionAt(a00d45e4);
        }
        if (f00d45e4 != null) {
            f00d45e4.setBody(new AddressSet(a00d45e4, toAddr(0x600d45e7)));
        }

        // 93. Fix 0x600d4664 boundary (48 bytes: 0x600d4664..0x600d4693)
        Address a00d4664 = toAddr(0x600d4664);
        Function f00d4664 = fm.getFunctionAt(a00d4664);
        if (f00d4664 != null) {
            f00d4664.setBody(new AddressSet(a00d4664, toAddr(0x600d4693)));
        }

        // 94. Create missing function 0x600d4784 (10 bytes: 0x600d4784..0x600d478d)
        Address a00d4784 = toAddr(0x600d4784);
        Function f00d4784 = fm.getFunctionAt(a00d4784);
        if (f00d4784 == null) {
            createFunction(a00d4784, "FUN_600d4784");
            f00d4784 = fm.getFunctionAt(a00d4784);
        }
        if (f00d4784 != null) {
            f00d4784.setBody(new AddressSet(a00d4784, toAddr(0x600d478d)));
        }

        // 95. Create missing function 0x600d47b8 (8 bytes: 0x600d47b8..0x600d47bf)
        Address a00d47b8 = toAddr(0x600d47b8);
        Function f00d47b8 = fm.getFunctionAt(a00d47b8);
        if (f00d47b8 == null) {
            createFunction(a00d47b8, "FUN_600d47b8");
            f00d47b8 = fm.getFunctionAt(a00d47b8);
        }
        if (f00d47b8 != null) {
            f00d47b8.setBody(new AddressSet(a00d47b8, toAddr(0x600d47bf)));
        }

        // 96. Create missing function 0x600d47c0 (4 bytes: 0x600d47c0..0x600d47c3)
        Address a00d47c0 = toAddr(0x600d47c0);
        Function f00d47c0 = fm.getFunctionAt(a00d47c0);
        if (f00d47c0 == null) {
            createFunction(a00d47c0, "FUN_600d47c0");
            f00d47c0 = fm.getFunctionAt(a00d47c0);
        }
        if (f00d47c0 != null) {
            f00d47c0.setBody(new AddressSet(a00d47c0, toAddr(0x600d47c3)));
        }

        // 97. Create missing function 0x600d4850 (44 bytes: 0x600d4850..0x600d487b)
        Address a00d4850 = toAddr(0x600d4850);
        Function f00d4850 = fm.getFunctionAt(a00d4850);
        if (f00d4850 == null) {
            createFunction(a00d4850, "FUN_600d4850");
            f00d4850 = fm.getFunctionAt(a00d4850);
        }
        if (f00d4850 != null) {
            f00d4850.setBody(new AddressSet(a00d4850, toAddr(0x600d487b)));
        }

        println("FixSpuriousSplits completed successfully.");
    }
}



