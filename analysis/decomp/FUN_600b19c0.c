// 600b19c0  FUN_600b19c0  size=198 bytes
// --- callers ---
//   6009f6c0 FUN_6009f6c0
// --- callees ---
//   600a9234 FUN_600a9234
//   6006dbac FUN_6006dbac


undefined4 FUN_600b19c0(undefined1 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *local_14;
  
  iVar1 = FUN_6006dbac(0x32,DAT_600b1a88,0x3f7);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 2) = 0x2a;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x27;
    *(undefined1 *)(iVar1 + 9) = 0x20;
    *(undefined1 *)(iVar1 + 10) = 0x27;
    *(undefined1 *)(iVar1 + 0xb) = param_1;
    local_14 = (undefined1 *)(iVar1 + 0xc);
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)((5 - iVar3) + param_2);
      local_14 = local_14 + 1;
    }
    for (iVar3 = 0; iVar3 < 0x10; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)(iVar3 + param_3);
      local_14 = local_14 + 1;
    }
    for (iVar3 = 0; iVar3 < 0x10; iVar3 = iVar3 + 1) {
      *local_14 = *(undefined1 *)(iVar3 + param_4);
      local_14 = local_14 + 1;
    }
    FUN_600a9234(0,iVar1);
    uVar2 = 1;
  }
  return uVar2;
}


