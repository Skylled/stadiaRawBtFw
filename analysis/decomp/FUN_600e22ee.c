// 600e22ee  FUN_600e22ee  size=20 bytes
// --- callers ---
//   6008deac FUN_6008deac
//   600e6e26 FUN_600e6e26
//   600e7124 FUN_600e7124
// --- callees ---


void FUN_600e22ee(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    *(uint *)(param_1 + iVar1) = *(uint *)(param_2 + iVar1) ^ *(uint *)(param_3 + iVar1);
    iVar1 = iVar1 + 4;
  } while (iVar1 != 0x10);
  return;
}


