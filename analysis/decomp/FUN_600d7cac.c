// 600d7cac  FUN_600d7cac  size=24 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600d7cac(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(uint *)(param_1 + 4)) {
    FUN_600d7c4e(param_1 + 0xc);
    uVar1 = *(undefined4 *)(param_1 + 8);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


