// 600d8c0a  FUN_600d8c0a  size=16 bytes
// --- callers ---
//   600718b8 FUN_600718b8
// --- callees ---
//   600cedd8 FUN_600cedd8


void FUN_600d8c0a(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    FUN_600cedd8(*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar1 + 0x18),0);
    return;
  }
  return;
}


