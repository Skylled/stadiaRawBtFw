// 600f068e  FUN_600f068e  size=78 bytes
// --- callers ---
//   600fd276 FUN_600fd276
// --- callees ---
//   600c0698 FUN_600c0698
//   6009ff18 FUN_6009ff18


void FUN_600f068e(undefined4 param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_6009ff18(param_1);
  if (iVar1 != 0) {
    *(ushort *)(iVar1 + 0x2a) = *(ushort *)(iVar1 + 0x2a) | 0x200;
    FUN_600c0698(param_1,param_2 != '\0',param_3);
  }
  return;
}


