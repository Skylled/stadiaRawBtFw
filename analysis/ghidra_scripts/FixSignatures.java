
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.data.IntegerDataType;
import ghidra.program.model.data.PointerDataType;
import ghidra.program.model.data.VoidDataType;
import ghidra.program.model.listing.ParameterImpl;
import ghidra.program.model.symbol.SourceType;

public class FixSignatures extends GhidraScript {
    @Override
    public void run() throws Exception {
        // Fix 0x600ce1e8: int kill(int pid, int sig)
        Function f1e8 = getFunctionAt(toAddr(0x600ce1e8));
        if (f1e8 != null) {
            f1e8.setReturnType(new IntegerDataType(), SourceType.USER_DEFINED);
            f1e8.updateFunction(null, null, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
        }

        // Fix 0x600cdca0: int _kill_r(void *reent, int pid, int sig)
        Function fdca0 = getFunctionAt(toAddr(0x600cdca0));
        if (fdca0 != null) {
            fdca0.setReturnType(new IntegerDataType(), SourceType.USER_DEFINED);
            fdca0.updateFunction(null, null, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
        }

        // Fix 0x601023fa: int _raise_r(void *reent, int sig)
        Function f23fa = getFunctionAt(toAddr(0x601023fa));
        if (f23fa != null) {
            f23fa.setReturnType(new IntegerDataType(), SourceType.USER_DEFINED);
            f23fa.updateFunction(null, null, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
        }

        // Fix 0x600cdc90: int raise(int sig)
        Function fdc90 = getFunctionAt(toAddr(0x600cdc90));
        if (fdc90 != null) {
            fdc90.setReturnType(new IntegerDataType(), SourceType.USER_DEFINED);
            fdc90.updateFunction(null, null, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
        }

        // Fix 0x600cefde: int i2c_bus_busy_check(void *ctx)
        Function fcefde = getFunctionAt(toAddr(0x600cefde));
        if (fcefde != null) {
            fcefde.setReturnType(new IntegerDataType(), SourceType.USER_DEFINED);
            fcefde.updateFunction(null, null, Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
        }
        println("Signatures updated.");
    }
}

