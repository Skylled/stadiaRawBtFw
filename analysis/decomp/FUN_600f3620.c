// 600f3620  FUN_600f3620  size=94 bytes
// --- callers ---
//   600abf08 FUN_600abf08
//   600c6da4 FUN_600c6da4
// --- callees ---
//   600f5446 FUN_600f5446
//   600af3f4 FUN_600af3f4


undefined4 FUN_600f3620(undefined2 param_1,undefined2 param_2,short *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600af3f4(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if ((param_3 == (short *)0x0) || (((*param_3 != 0x10 && (*param_3 != 2)) && (*param_3 != 4)))
          ) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_600f5446(iVar1 + 0x38,param_2,param_3);
  }
  return uVar2;
}


