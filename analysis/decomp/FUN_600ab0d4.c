// 600ab0d4  FUN_600ab0d4  size=54 bytes
// --- callers ---
//   600c6a3c FUN_600c6a3c
// --- callees ---
//   600adb54 FUN_600adb54


bool FUN_600ab0d4(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_600ab10c;
  if (param_1 != (undefined4 *)0x0) {
    uVar2 = param_1[1];
    *(undefined4 *)(DAT_600ab10c + 0x1554) = *param_1;
    *(undefined4 *)(iVar1 + 0x1558) = uVar2;
    FUN_600adb54();
  }
  return param_1 != (undefined4 *)0x0;
}


