// 600f808c  FUN_600f808c  size=56 bytes
// --- callers ---
//   600f314c FUN_600f314c
// --- callees ---
//   600bcbe0 FUN_600bcbe0


void FUN_600f808c(undefined2 param_1,short param_2)

{
  int iVar1;
  
  iVar1 = FUN_600bcbe0(param_1);
  if ((iVar1 != 0) && (param_2 != 0)) {
    *(short *)(iVar1 + 0x36) = param_2;
  }
  return;
}


