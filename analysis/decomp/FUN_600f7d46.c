// 600f7d46  FUN_600f7d46  size=66 bytes
// --- callers ---
//   600f2fda FUN_600f2fda
// --- callees ---
//   600bcbe0 FUN_600bcbe0
//   600b5844 FUN_600b5844


void FUN_600f7d46(undefined2 param_1)

{
  int iVar1;
  
  iVar1 = FUN_600bcbe0(param_1);
  if (iVar1 != 0) {
    *(byte *)(iVar1 + 0x38) = *(byte *)(iVar1 + 0x38) & 0xfb;
    FUN_600b5844(iVar1);
  }
  return;
}


