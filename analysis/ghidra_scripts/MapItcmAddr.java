// Map an ITCM address (0x0000xxxx, only valid at runtime after the boot-time
// copy) to the flash address that holds its bytes in this static image, and
// report the function Ghidra has there (if any).
//
// Basis: Reset_Handler (0x60040500) contains a word-at-a-time copy loop
//   memcpy(dst=0x00000000, src=0x6004081c, size=0xbdf8)
// i.e. flash_addr = itcm_addr + 0x6004081c, valid for itcm_addr in [0, 0xbdf8).
// See analysis/bruce-itcm.md for how this was found.
//
// Usage: -postScript MapItcmAddr.java 0x1ea4 0x7a2c 0xb572 ...
//        (accepts either the bare ITCM offset or a thunk_EXT_FUN_0000xxxx-style hex string)
// @category Stadia
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

public class MapItcmAddr extends GhidraScript {
    static final long ITCM_SRC = 0x6004081cL;   // flash source of the copy
    static final long ITCM_SIZE = 0xbdf8L;      // bytes copied (dest 0x0..0xbdf8)
    static final long IMAGE_BASE = 0x60040000L; // -> file offset

    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        for (String raw : getScriptArgs()) {
            String a = raw;
            int idx = a.lastIndexOf('_');
            if (a.startsWith("thunk_EXT_FUN_") || a.startsWith("EXT_FUN_")) {
                a = a.substring(idx + 1); // pull the hex suffix out of a thunk name
            }
            long itcm;
            try { itcm = Long.decode(a.startsWith("0x") ? a : "0x" + a); }
            catch (Exception e) { println("bad addr " + raw); continue; }

            if (itcm < 0 || itcm >= ITCM_SIZE) {
                println(raw + " (itcm 0x" + Long.toHexString(itcm) + ") -> OUTSIDE copied range [0, 0x"
                        + Long.toHexString(ITCM_SIZE) + ")");
                continue;
            }
            long flash = itcm + ITCM_SRC;
            Address fa = toAddr(flash);
            Function f = fm.getFunctionContaining(fa);
            println(String.format("itcm 0x%x -> flash 0x%x (file offset 0x%x)%s",
                    itcm, flash, flash - IMAGE_BASE,
                    f != null ? "  in " + f.getName() + " @" + f.getEntryPoint()
                              : "  (no function defined yet; try Decompile.java on the flash addr)"));
        }
    }
}
