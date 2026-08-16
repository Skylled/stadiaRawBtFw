// 600b1e58  FUN_600b1e58  size=154 bytes
// --- callers ---
//   600a29a0 FUN_600a29a0
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


undefined4 FUN_600b1e58(int param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x10,DAT_600b1ef4,0x49);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 8;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 1;
    *(undefined1 *)(iVar1 + 9) = 4;
    *(undefined1 *)(iVar1 + 10) = 5;
    local_14 = (undefined1 *)(iVar1 + 0xb);
    for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)((2 - iVar3) + param_1);
      local_14 = local_14 + 1;
    }
    *local_14 = param_2;
    local_14[1] = param_3;
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


