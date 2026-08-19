
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
            toAddr(0x600dde06)
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
