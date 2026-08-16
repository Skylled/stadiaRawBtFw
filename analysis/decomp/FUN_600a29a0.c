// 600a29a0  FUN_600a29a0  size=258 bytes
// --- callers ---
//   600a2884 FUN_600a2884
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a25f8 FUN_600a25f8
//   600b1f5c FUN_600b1f5c
//   600b1e58 FUN_600b1e58
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600a2f3c FUN_600a2f3c


void FUN_600a29a0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  byte *pbVar4;
  undefined4 uVar5;
  
  pbVar4 = (byte *)(param_1 + 0x608);
  if ((*(byte *)(param_1 + 0x61e) & 4) == 0) {
    bVar3 = *(byte *)(param_1 + 0x60a);
    if (0x1d < bVar3) {
      bVar3 = 0x1e;
    }
    *(byte *)(param_1 + 0x60a) = bVar3;
    uVar5 = DAT_600a2aa8;
    if ((*(byte *)(param_1 + 0x61e) & 2) != 0) {
      uVar5 = DAT_600a2aa4;
    }
    if ((*(byte *)(param_1 + 0x61e) & 8) == 0) {
      FUN_600a25f8();
      uVar2 = FUN_6006dbac(0x408,DAT_600a2aac,0x7e9);
      *(undefined4 *)(param_1 + 0x60) = uVar2;
      if (*(int *)(param_1 + 0x60) != 0) {
        *(undefined2 *)(param_1 + 0x66) = 0x56;
        thunk_EXT_FUN_0000b5ba(*(undefined4 *)(param_1 + 0x60),0,0x408);
      }
      iVar1 = FUN_600b1e58(uVar5,*(undefined1 *)(param_1 + 0x609),0);
      if (iVar1 == 0) {
        FUN_600a2f3c(3,*pbVar4 & 3);
      }
    }
    else {
      iVar1 = FUN_600b1f5c(*(undefined2 *)(param_1 + 0x618),*(undefined2 *)(param_1 + 0x616),uVar5,
                           *(undefined1 *)(param_1 + 0x609),*(undefined1 *)(param_1 + 0x60a));
      if (iVar1 == 0) {
        FUN_600a2f3c(3,*pbVar4 & 3);
      }
    }
  }
  else {
    FUN_600a2f3c(3,*pbVar4 & 3);
  }
  return;
}


