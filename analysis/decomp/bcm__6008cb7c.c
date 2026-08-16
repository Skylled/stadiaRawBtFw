// 6008cb7c  bcm__6008cb7c  size=66 bytes
// src: bcm.c
// --- callers ---
//   600ea712 FUN_600ea712
//   600ed880 FUN_600ed880
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600e092c FUN_600e092c
//   600e0552 FUN_600e0552


/* src: bcm.c */

undefined4 bcm__6008cb7c(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*param_1 != param_2) {
    iVar2 = param_2;
    iVar1 = FUN_600e092c(*(undefined4 *)(param_2 + 0x1c));
    if (iVar1 == 0) {
      FUN_600e0552(0x1d,0,0x41,DAT_6008cbc0,0xc2,iVar2);
      return 0;
    }
    thunk_EXT_FUN_0000ac5e(param_1[1]);
    *param_1 = param_2;
    param_1[1] = iVar1;
  }
  (**(code **)(*param_1 + 0xc))(param_1);
  return 1;
}


