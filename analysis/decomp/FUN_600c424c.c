// 600c424c  FUN_600c424c  size=204 bytes
// --- callers ---
// --- callees ---
//   600efcfe FUN_600efcfe
//   600f1800 FUN_600f1800
//   600c4320 FUN_600c4320
//   601024d8 FUN_601024d8
//   6004cb28 FUN_6004cb28


void FUN_600c424c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  ushort local_110 [4];
  ushort local_108;
  undefined1 local_106 [248];
  undefined1 local_e;
  byte local_9;
  
  iVar1 = FUN_600efcfe(DAT_600c4318,param_1);
  if (iVar1 == 0) {
    local_108 = FUN_6004cb28(param_3);
    if (0xf8 < local_108) {
      local_108 = 0xf8;
      local_e = 0;
    }
    FUN_601024d8(local_106,param_3,0xf8);
    local_110[0] = 0;
    FUN_600c4320(local_110);
  }
  else {
    local_9 = FUN_600f1800(DAT_600c4318,DAT_600c431c,1);
    if ((local_9 != 2) && (local_9 != 1)) {
      local_108 = 0;
      local_106[0] = 0;
      local_110[0] = (ushort)local_9;
      FUN_600c4320(local_110);
    }
  }
  return;
}


