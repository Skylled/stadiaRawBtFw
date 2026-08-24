// 600ee142  FUN_600ee142  size=72 bytes
// --- callers ---
// --- callees ---
//   601017fc FUN_601017fc
//   60101832 FUN_60101832
//   6013d268 thunk_EXT_FUN_00006d2c


void FUN_600ee142(int param_1)

{
  code *pcVar1;
  code cVar2;
  code *pcVar3;
  char local_24 [4];
  code *local_20;
  undefined4 uStack_1c;
  
  do {
    while( true ) {
      thunk_EXT_FUN_00006d2c(*(undefined4 *)(param_1 + 0xb0),local_24,0xffffffff);
      pcVar1 = local_20;
      if (local_24[0] == '\0') break;
      (*local_20)(uStack_1c);
    }
    pcVar3 = local_20 + 0xc;
    FUN_601017fc(pcVar3);
    cVar2 = (code)(**(code **)pcVar1)(*(undefined4 *)(pcVar1 + 4));
    pcVar1[0x60] = cVar2;
    DataMemoryBarrier(0x1b);
    pcVar1[8] = (code)0x0;
    DataMemoryBarrier(0x1b);
    FUN_60101832(pcVar3);
  } while( true );
}


