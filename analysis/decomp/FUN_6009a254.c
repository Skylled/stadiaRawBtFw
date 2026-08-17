// 6009a254  FUN_6009a254  size=106 bytes
// --- callers ---
//   600c4b7c FUN_600c4b7c
// --- callees ---
//   600aa340 FUN_600aa340
//   600aa3cc FUN_600aa3cc
//   60098ec8 FUN_60098ec8
//   600b4a84 FUN_600b4a84


undefined4 FUN_6009a254(undefined4 param_1,undefined4 param_2)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(DAT_6009a2c0 + 0x78c) == 0) {
    puVar1 = (undefined2 *)FUN_60098ec8(param_1,1);
    if (puVar1 == (undefined2 *)0x0) {
      uVar3 = 7;
    }
    else {
      FUN_600aa340(DAT_6009a2c4,7,3);
      *(undefined4 *)(DAT_6009a2c0 + 0x78c) = param_2;
      iVar2 = FUN_600b4a84(*puVar1);
      if (iVar2 == 0) {
        FUN_600aa3cc(DAT_6009a2c4);
        *(undefined4 *)(DAT_6009a2c0 + 0x78c) = 0;
        uVar3 = 3;
      }
      else {
        uVar3 = 1;
      }
    }
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}


