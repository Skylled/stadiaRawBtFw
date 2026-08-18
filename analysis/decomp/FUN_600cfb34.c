// 600cfb34  FUN_600cfb34  size=14 bytes
// --- callers ---
//   600607b8 FUN_600607b8
// --- callees ---


undefined4 FUN_600cfb34(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0x4c) & 1) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


