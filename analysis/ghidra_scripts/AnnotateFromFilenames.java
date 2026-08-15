// Attribute functions to source files using leaked __FILE__ strings.
// A LOG/CHECK macro embeds the source filename; the function that references
// that string lives in that source file. Renames FUN_* accordingly, adds a
// "src: <path>" comment, and writes a mapping CSV.
// @category Stadia
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.*;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class AnnotateFromFilenames extends GhidraScript {
    @Override
    public void run() throws Exception {
        Listing listing = currentProgram.getListing();
        FunctionManager fm = currentProgram.getFunctionManager();
        ReferenceManager rm = currentProgram.getReferenceManager();

        Pattern pat = Pattern.compile("([A-Za-z0-9_./\\-]+\\.(?:cc|cpp|c|hpp|h|S))$");

        String outDir = "/Users/kyle/Repos/stadiaRawBtFw/analysis/ghidra/";
        String tag = currentProgram.getName().toLowerCase().contains("gotham") ? "gotham" : "bruce";
        PrintWriter map = new PrintWriter(new FileWriter(outDir + tag + "_srcmap.csv"));
        map.println("address,name,src_file");

        int renamed = 0, commented = 0;
        Map<String, Integer> distinctFiles = new HashMap<>();

        DataIterator di = listing.getDefinedData(true);
        while (di.hasNext()) {
            Data d = di.next();
            Object val = d.getValue();
            if (!(val instanceof String)) continue;
            String s = ((String) val).trim();
            Matcher m = pat.matcher(s);
            if (!m.find()) continue;
            String full = m.group(1);
            String basename = full;
            int sl = basename.lastIndexOf('/');
            if (sl >= 0) basename = basename.substring(sl + 1);
            String stem = basename.replaceAll("\\.(cc|cpp|c|hpp|h|S)$", "").replaceAll("[^A-Za-z0-9_]", "_");
            if (stem.isEmpty()) continue;

            Address strAddr = d.getAddress();
            ReferenceIterator ri = rm.getReferencesTo(strAddr);
            while (ri.hasNext()) {
                Reference r = ri.next();
                Function f = fm.getFunctionContaining(r.getFromAddress());
                if (f == null) continue;
                distinctFiles.put(full, 1);

                String existing = f.getComment();
                String note = "src: " + full;
                if (existing == null) { f.setComment(note); commented++; }
                else if (!existing.contains(full)) { f.setComment(existing + "\n" + note); commented++; }

                if (f.getName().startsWith("FUN_")) {
                    String nm = stem + "__" + Long.toHexString(f.getEntryPoint().getOffset());
                    try {
                        f.setName(nm, SourceType.ANALYSIS);
                        map.println(f.getEntryPoint() + "," + nm + "," + full);
                        renamed++;
                    } catch (Exception e) { /* name collision, skip */ }
                }
            }
        }
        map.close();
        println("AnnotateFromFilenames[" + tag + "]: renamed=" + renamed
                + " comments=" + commented + " distinctSrcFiles=" + distinctFiles.size());
    }
}
