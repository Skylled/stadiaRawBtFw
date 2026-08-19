// 600de4a4  FUN_600de4a4  size=16 bytes
// --- callers ---
// --- callees ---


void FUN_600de4a4(uint *param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  if (param_3 < 500) {
    uVar1 = *param_1 >> 6;
  }
  else {
    uVar1 = *(uint *)(param_2 + 0x14);
  }
  param_1[1] = uVar1;
  return;
}


