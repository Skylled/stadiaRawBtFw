// 6009baec  FUN_6009baec  size=70 bytes
// --- callers ---
// --- callees ---
//   600b1368 FUN_600b1368
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_6009baec(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (*(short *)(param_1 + 2) == 0x2018)) {
    thunk_EXT_FUN_0000b572(DAT_6009bb34,param_1 + 4,8);
    iVar1 = FUN_600b1368(DAT_6009bb38);
    if (iVar1 == 0) {
      thunk_EXT_FUN_0000b5ba(DAT_6009bb34,0,0x30);
    }
  }
  return;
}


