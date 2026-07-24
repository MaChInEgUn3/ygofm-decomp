import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SourceType;
import ghidra.framework.options.Options;
import ghidra.program.model.listing.Program;

public class FunctionInventory extends GhidraScript {
    @Override
    protected void run() throws Exception {
        Program program = currentProgram;
        Options opts = program.getOptions(Program.PROGRAM_INFO);
        String psyqVer = opts.getString("PsyQ Version", "");

        File outFile = new File("D:/YGOFM/ghidra_project/function_inventory.txt");
        try (PrintWriter pw = new PrintWriter(outFile, "UTF-8")) {
            pw.println("PsyQ Version detected: " + psyqVer);
            pw.println("Image base: " + program.getImageBase());
            pw.println();

            List<Function> libFuncs = new ArrayList<>();
            List<Function> gameFuncs = new ArrayList<>();

            for (Function f : program.getFunctionManager().getFunctions(true)) {
                Symbol sym = program.getSymbolTable().getPrimarySymbol(f.getEntryPoint());
                SourceType src = (sym != null) ? sym.getSource() : SourceType.DEFAULT;
                if (src == SourceType.IMPORTED) {
                    libFuncs.add(f);
                } else {
                    gameFuncs.add(f);
                }
            }

            pw.println("=== Library-matched functions (" + libFuncs.size() + ") ===");
            for (Function f : libFuncs) {
                pw.printf("%s\t%s\tsize=%d%n", f.getEntryPoint(), f.getName(), f.getBody().getNumAddresses());
            }

            pw.println();
            pw.println("=== Game-specific functions (" + gameFuncs.size() + ") ===");
            for (Function f : gameFuncs) {
                pw.printf("%s\t%s\tsize=%d%n", f.getEntryPoint(), f.getName(), f.getBody().getNumAddresses());
            }

            pw.println();
            pw.println("=== Memory blocks ===");
            for (var block : program.getMemory().getBlocks()) {
                pw.printf("%s: %s - %s (size=%d, exec=%b, write=%b, init=%b)%n",
                    block.getName(), block.getStart(), block.getEnd(), block.getSize(),
                    block.isExecute(), block.isWrite(), block.isInitialized());
            }
        }

        println("Function inventory written to " + outFile.getAbsolutePath());
    }
}
