// 600ed776  FUN_600ed776  size=30 bytes
// --- callers ---
//   60091ddc FUN_60091ddc
// --- callees ---


undefined4 FUN_600ed776(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x80) {
    return 1;
  }
  if (param_1 < 0x800) {
    return 2;
  }
  if (param_1 < 0x10000) {
    uVar1 = 3;
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


