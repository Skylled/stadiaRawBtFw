// 600c9eac  queue__600c9eac  size=60 bytes
// src: queue.c
// --- callers ---
//   600d1692 FUN_600d1692
// --- callees ---
//   6013d270 thunk_EXT_FUN_00006e5c
//   601016a2 FUN_601016a2
//   600ca9dc FUN_600ca9dc


/* src: queue.c */

int queue__600c9eac(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    FUN_601016a2(DAT_600c9eec,0x27a,DAT_600c9ee8);
  }
  iVar2 = *(int *)(param_1 + 4);
  iVar1 = FUN_600ca9dc();
  if (iVar2 == iVar1) {
    iVar1 = 1;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  else {
    iVar1 = thunk_EXT_FUN_00006e5c(param_1,param_2);
    if (iVar1 != 0) {
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    }
  }
  return iVar1;
}


