// Decompile functions given as address args; dump C + callers/callees to analysis/decomp/.
// Usage: -postScript Decompile.java 0x6004cdb8 0x600xxxxx ...
// @category Stadia
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

public class Decompile extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outDir = "/Users/kyle/Repos/stadiaRawBtFw/analysis/decomp/";
        new File(outDir).mkdirs();

        DecompInterface dif = new DecompInterface();
        dif.setOptions(new DecompileOptions());
        dif.openProgram(currentProgram);
        FunctionManager fm = currentProgram.getFunctionManager();

        for (String a : args) {
            Address addr;
            try { addr = toAddr(a); } catch (Exception e) { println("bad addr " + a); continue; }
            Function f = fm.getFunctionContaining(addr);
            if (f == null) {
                // undefined region (e.g. dispatch-table callback): define it here.
                try { disassemble(addr); f = createFunction(addr, null); } catch (Exception e) { }
            }
            if (f == null) { println("no function at " + a); continue; }

            DecompileResults res = dif.decompileFunction(f, 120, monitor);
            String c = (res != null && res.decompileCompleted())
                    ? res.getDecompiledFunction().getC()
                    : "// decompile failed: " + (res == null ? "null" : res.getErrorMessage());

            String fname = f.getName().replaceAll("[^A-Za-z0-9_.]", "_");
            PrintWriter pw = new PrintWriter(new FileWriter(outDir + fname + ".c"));
            pw.println("// " + f.getEntryPoint() + "  " + f.getName()
                    + "  size=" + f.getBody().getNumAddresses() + " bytes");
            String cmt = f.getComment();
            if (cmt != null) pw.println("// " + cmt.replace("\n", "\n// "));
            pw.println("// --- callers ---");
            for (Function c2 : f.getCallingFunctions(monitor))
                pw.println("//   " + c2.getEntryPoint() + " " + c2.getName());
            pw.println("// --- callees ---");
            for (Function c2 : f.getCalledFunctions(monitor))
                pw.println("//   " + c2.getEntryPoint() + " " + c2.getName());
            pw.println();
            pw.println(c);
            pw.close();
            println("decompiled " + f.getName() + " -> " + fname + ".c");
        }
        dif.dispose();
    }
}
