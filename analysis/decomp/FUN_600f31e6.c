// 600f31e6  FUN_600f31e6  size=72 bytes
// --- callers ---
// --- callees ---
//   600aa8f0 FUN_600aa8f0


undefined1 FUN_600f31e6(undefined4 param_1,undefined2 *param_2,int param_3)

{
  undefined1 uVar1;
  
  if (*(char *)(param_2 + 2) != '\0') {
    *(undefined2 *)(param_3 + 4) = param_2[1];
  }
  *(undefined2 *)(param_3 + 2) = *param_2;
  uVar1 = FUN_600aa8f0(*param_2,param_3,*(undefined1 *)(param_2 + 2));
  return uVar1;
}


