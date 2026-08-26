// 601020ec  FUN_601020ec  size=18 bytes
// --- callers ---
// --- callees ---
//   600cdbbc FUN_600cdbbc


byte FUN_601020ec(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_600cdbbc();
  return *(byte *)(iVar1 + param_1 + 1) & 8;
}


