// 600f06dc  FUN_600f06dc  size=74 bytes
// --- callers ---
//   600fd2b4 FUN_600fd2b4
// --- callees ---
//   600c073c FUN_600c073c
//   6009ff18 FUN_6009ff18


void FUN_600f06dc(undefined4 param_1,char param_2)

{
  int iVar1;
  
  iVar1 = FUN_6009ff18(param_1);
  if (iVar1 != 0) {
    *(ushort *)(iVar1 + 0x2a) = *(ushort *)(iVar1 + 0x2a) | 0x200;
    FUN_600c073c(param_1,param_2 != '\0');
  }
  return;
}


