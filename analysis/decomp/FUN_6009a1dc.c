// 6009a1dc  FUN_6009a1dc  size=112 bytes
// --- callers ---
//   600c4b7c FUN_600c4b7c
// --- callees ---
//   600b4b08 FUN_600b4b08
//   600aa340 FUN_600aa340
//   600aa3cc FUN_600aa3cc
//   60098ec8 FUN_60098ec8


undefined4 FUN_6009a1dc(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(DAT_6009a24c + 0x770) == 0) {
    puVar1 = (undefined2 *)FUN_60098ec8(param_1,param_2);
    if (puVar1 == (undefined2 *)0x0) {
      uVar3 = 7;
    }
    else {
      FUN_600aa340(DAT_6009a250,7,3);
      *(undefined4 *)(DAT_6009a24c + 0x770) = param_3;
      iVar2 = FUN_600b4b08(*puVar1);
      if (iVar2 == 0) {
        *(undefined4 *)(DAT_6009a24c + 0x770) = 0;
        FUN_600aa3cc(DAT_6009a250);
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


