// 600cefde  FUN_600cefde  size=20 bytes
// --- callers ---
//   600cf0ca FUN_600cf0ca
// --- callees ---


undefined4 FUN_600cefde(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0x14) & 0x3000000) == 0x2000000) {
    uVar1 = 900;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


