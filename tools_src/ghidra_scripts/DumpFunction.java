import java.io.File;
import java.io.PrintWriter;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.listing.Program;
import ghidra.util.task.ConsoleTaskMonitor;

public class DumpFunction extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("Usage: DumpFunction.java <hex_address> [output_path]");
            return;
        }
        Program program = currentProgram;
        Address addr = program.getAddressFactory().getAddress(args[0]);
        Function f = program.getFunctionManager().getFunctionAt(addr);
        if (f == null) {
            println("No function at " + args[0]);
            return;
        }

        String outPath = args.length >= 2 ? args[1] : ("D:/YGOFM/ghidra_project/dump_" + args[0].replace("0x", "") + ".txt");

        try (PrintWriter pw = new PrintWriter(new File(outPath), "UTF-8")) {
            pw.println("Function: " + f.getName() + " @ " + f.getEntryPoint());
            pw.println("Size: " + f.getBody().getNumAddresses());
            pw.println();
            pw.println("=== Disassembly ===");
            InstructionIterator it = program.getListing().getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction insn = it.next();
                byte[] bytes = insn.getBytes();
                StringBuilder hex = new StringBuilder();
                for (byte b : bytes) hex.append(String.format("%02X ", b));
                pw.printf("%s  %-30s  %s%n", insn.getAddress(), hex.toString(), insn.toString());
            }

            pw.println();
            pw.println("=== Decompiler output ===");
            DecompInterface decomp = new DecompInterface();
            decomp.openProgram(program);
            DecompileResults res = decomp.decompileFunction(f, 60, new ConsoleTaskMonitor());
            if (res != null && res.decompileCompleted()) {
                pw.println(res.getDecompiledFunction().getC());
            } else {
                pw.println("Decompilation failed: " + (res != null ? res.getErrorMessage() : "null result"));
            }
            decomp.dispose();
        }

        println("Dumped to " + outPath);
    }
}
