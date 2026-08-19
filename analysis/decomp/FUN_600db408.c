// 600db408  FUN_600db408  size=54 bytes
// --- callers ---
// --- callees ---
//   600d3dd8 FUN_600d3dd8


undefined4 FUN_600db408(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(param_1 + 8) == 3) && (*(char *)(param_1 + 0x10) == '\x06')) {
    FUN_600d3dd8(0,0xc);
    FUN_600d3dd8(0,0);
    uVar1 = 2;
  }
  return uVar1;
}


