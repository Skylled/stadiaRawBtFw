// 600ee304  FUN_600ee304  size=58 bytes
// --- callers ---
//   60093d20 FUN_60093d20
//   600936d4 FUN_600936d4
// --- callees ---


undefined4 FUN_600ee304(byte param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 4) {
    uVar1 = 2;
  }
  else if (param_1 == 0x10) {
    uVar1 = 1;
  }
  else if ((param_1 & 0x20) == 0) {
    uVar1 = 3;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


