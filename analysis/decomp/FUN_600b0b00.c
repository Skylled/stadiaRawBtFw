// 600b0b00  FUN_600b0b00  size=170 bytes
// --- callers ---
//   6009cec8 FUN_6009cec8
//   6009df10 FUN_6009df10
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b0b00(byte param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  byte local_19;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x2b,DAT_600b0bac,0xc0);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 0x23;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 8;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 0x20;
    thunk_EXT_FUN_0000b5ba((byte *)(iVar1 + 0xb),0,0x1f);
    if ((param_2 != 0) && (param_1 != 0)) {
      local_19 = param_1;
      if (0x1f < param_1) {
        local_19 = 0x1f;
      }
      *(byte *)(iVar1 + 0xb) = local_19;
      local_14 = (undefined1 *)(iVar1 + 0xc);
      for (iVar3 = 0; iVar3 < (int)(uint)local_19; iVar3 = iVar3 + 1) {
        *local_14 = *(undefined1 *)(iVar3 + param_2);
        local_14 = local_14 + 1;
      }
    }
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


