// 6005f110  FUN_6005f110  size=16 bytes
// --- callers ---
//   6005f164 FUN_6005f164
//   6005f120 FUN_6005f120
// --- callees ---
//   600718b8 FUN_600718b8
//   600d4d2e FUN_600d4d2e


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x6005f128) */
/* WARNING: Removing unreachable block (ram,0x6005f30c) */

void FUN_6005f110(void)

{
  int iVar1;
  
  FUN_600718b8(0x200064c0);
  iVar1 = FUN_600d4d2e();
  *(int *)(iVar1 + 0x4c) = iVar1;
  return;
}


