// 600d3e4a  FUN_600d3e4a  size=22 bytes
// --- callers ---
//   600d3e60 FUN_600d3e60
// --- callees ---


void FUN_600d3e4a(undefined4 *param_1,int param_2)

{
  bool bVar1;
  
  bVar1 = *(char *)(param_2 + 0x28) == '\0';
  if (bVar1) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    *param_1 = *(undefined4 *)(param_2 + 0x24);
  }
  *(bool *)(param_1 + 1) = !bVar1;
  return;
}


