// 600b45b4  FUN_600b45b4  size=160 bytes
// --- callers ---
//   600a4984 FUN_600a4984
//   600a62cc FUN_600a62cc
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b45b4(int param_1,char param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x11,DAT_600b4654,0xaa3);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 9;
    *(undefined2 *)(iVar1 + 4) = 0;
    if (param_2 == '\0') {
      *(undefined1 *)(iVar1 + 8) = 0x2d;
      *(undefined1 *)(iVar1 + 9) = 4;
    }
    else {
      *(undefined1 *)(iVar1 + 8) = 0x2c;
      *(undefined1 *)(iVar1 + 9) = 4;
    }
    local_14 = (undefined1 *)(iVar1 + 10);
    *local_14 = 6;
    local_14 = (undefined1 *)(iVar1 + 0xb);
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)((5 - iVar3) + param_1);
      local_14 = local_14 + 1;
    }
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


