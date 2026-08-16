// 600b3138  FUN_600b3138  size=134 bytes
// --- callers ---
//   600a5880 FUN_600a5880
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b3138(undefined1 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x13,DAT_600b31c0,0x45d);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 0xb;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 99;
    *(undefined1 *)(iVar1 + 9) = 0xc;
    *(undefined1 *)(iVar1 + 10) = 8;
    local_14 = (undefined1 *)(iVar1 + 0xb);
    for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)((7 - iVar3) + param_2);
      local_14 = local_14 + 1;
    }
    FUN_600a9234(param_1,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


