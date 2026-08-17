// 600c9e6c  queue__600c9e6c  size=54 bytes
// src: queue.c
// --- callers ---
//   600d16ae FUN_600d16ae
// --- callees ---
//   6013d0e8 thunk_EXT_FUN_00006a74
//   601016a2 FUN_601016a2
//   600ca9dc FUN_600ca9dc


/* src: queue.c */

undefined4 queue__600c9e6c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    FUN_601016a2(DAT_600c9ea8,0x243,DAT_600c9ea4,param_4,param_4);
  }
  iVar3 = *(int *)(param_1 + 4);
  iVar1 = FUN_600ca9dc();
  if (iVar3 == iVar1) {
    iVar1 = *(int *)(param_1 + 0xc) + -1;
    *(int *)(param_1 + 0xc) = iVar1;
    if (iVar1 == 0) {
      thunk_EXT_FUN_00006a74(param_1,0,0);
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


