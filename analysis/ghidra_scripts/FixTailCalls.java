
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.FlowOverride;

public class FixTailCalls extends GhidraScript {
    @Override
    public void run() throws Exception {
        Address[] branchAddrs = new Address[] {
            toAddr(0x600cdc96),
            toAddr(0x60102428),
            toAddr(0x6010244a),
            toAddr(0x600cddbe),
            toAddr(0x600d35a4),
            toAddr(0x600da58c),
            toAddr(0x600da592),
            toAddr(0x600db8ec),
            toAddr(0x600dc130),
            toAddr(0x600dc13c),
            toAddr(0x600dc28e),
            toAddr(0x600dc8c0),
            toAddr(0x600dcbb2),
            toAddr(0x600dde06),
            toAddr(0x600de57e),
            toAddr(0x600de6fa),
            toAddr(0x600dead2),
            toAddr(0x600debaa),
            toAddr(0x600dee8a),
            toAddr(0x600df308),
            toAddr(0x600df80c),
            toAddr(0x600df8ba),
            toAddr(0x600df9e6),
            toAddr(0x600dfa5c),
            toAddr(0x600dff4c),
            toAddr(0x600e022c),
            toAddr(0x600e028a),
            toAddr(0x600e0294),
            toAddr(0x600e04ae),
            toAddr(0x600e04ee),
            toAddr(0x600e0510),
            toAddr(0x600e06ae),
            toAddr(0x600e06ea),
            toAddr(0x600e06fc),
            toAddr(0x600e081e),
            toAddr(0x600e0836),
            toAddr(0x600e0928),
            toAddr(0x600e094c),
            toAddr(0x600e09dc),
            toAddr(0x600e0a6a),
            toAddr(0x600e0aae),
            toAddr(0x600e0af4),
            toAddr(0x600e0b12),
            toAddr(0x600e0bea),
            toAddr(0x600e0bf6),
            toAddr(0x600e0c68),
            toAddr(0x600e0c7a),
            toAddr(0x600e0c7e),
            toAddr(0x600e0c90),
            toAddr(0x600e0ca2),
            toAddr(0x600e0d02),
            toAddr(0x600e0d70),
            toAddr(0x600e1c04),
            toAddr(0x600e1cd0),
            toAddr(0x600e22cc),
            toAddr(0x600e6a1c),
            toAddr(0x600e6a42),
            toAddr(0x600e6aee),
            toAddr(0x600e6e18),
            toAddr(0x600e6e22),
            toAddr(0x600e6fbc),
            toAddr(0x600e70d4),
            toAddr(0x600e70de),
            toAddr(0x600e721e),
            toAddr(0x600e725a),
            toAddr(0x600e7270),
            toAddr(0x600e7376),
            toAddr(0x600e7384),
            toAddr(0x600e7550),
            toAddr(0x600e7684),
            toAddr(0x600e7956)
        };
        for (Address a : branchAddrs) {
            Instruction ins = getInstructionAt(a);
            if (ins != null) {
                ins.setFlowOverride(FlowOverride.CALL_RETURN);
                println("Set CALL_RETURN flow override at " + a + " (" + ins + ")");
            } else {
                println("No instruction at " + a);
            }
        }
    }
}
