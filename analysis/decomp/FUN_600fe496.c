// 600fe496  FUN_600fe496  size=106 bytes
// --- callers ---
// --- callees ---
//   600f3b78 FUN_600f3b78
//   60095d4c FUN_60095d4c
//   60095cd4 FUN_60095cd4
//   600eedee FUN_600eedee


void FUN_600fe496(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  
  sVar1 = FUN_600eedee(*(undefined4 *)(param_1 + 0x10),param_2 + 8,param_2 + 0x24,0);
  if (((sVar1 != 0) && (iVar2 = FUN_600f3b78(*(undefined2 *)(param_2 + 6),sVar1), iVar2 == 0)) &&
     (*(char *)(param_1 + 8) == '\x01')) {
    FUN_60095d4c(0x1d,0xff,param_1 + 2);
    FUN_60095cd4(0x1d,0xff,param_1 + 2);
  }
  return;
}


