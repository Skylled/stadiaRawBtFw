// 600ee0bc  FUN_600ee0bc  size=12 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600ee0bc(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 3) {
    *(uint *)(param_1 + 4) = param_2;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}


