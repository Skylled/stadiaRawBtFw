// Post-analysis script: dump function list and defined strings to files.
// @category Stadia
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.DataIterator;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DumpMap extends GhidraScript {
    @Override
    public void run() throws Exception {
        String outDir = "/Users/kyle/Repos/stadiaRawBtFw/analysis/ghidra/";
        String tag = "bruce";
        if (currentProgram.getName().toLowerCase().contains("gotham")) tag = "gotham";

        FunctionManager fm = currentProgram.getFunctionManager();
        int fcount = fm.getFunctionCount();

        PrintWriter fw = new PrintWriter(new FileWriter(outDir + tag + "_functions.csv"));
        fw.println("address,name,size_bytes");
        FunctionIterator it = fm.getFunctions(true);
        while (it.hasNext()) {
            Function f = it.next();
            String nm = f.getName().replace(",", " ");
            fw.println(f.getEntryPoint() + "," + nm + "," + f.getBody().getNumAddresses());
        }
        fw.close();

        PrintWriter sw = new PrintWriter(new FileWriter(outDir + tag + "_strings.txt"));
        int scount = 0;
        DataIterator di = currentProgram.getListing().getDefinedData(true);
        while (di.hasNext()) {
            Data d = di.next();
            Object val = d.getValue();
            if (val instanceof String) {
                String v = ((String) val).replace("\n", "\\n").replace("\r", "");
                sw.println(d.getAddress() + "\t" + v);
                scount++;
            }
        }
        sw.close();

        println("DumpMap[" + tag + "]: functions=" + fcount + " strings=" + scount);
        println("DumpMap: imageBase=" + currentProgram.getImageBase()
                + " max=" + currentProgram.getMaxAddress());
    }
}
