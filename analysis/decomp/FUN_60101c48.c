// 60101c48  FUN_60101c48  size=10 bytes
// --- callers ---
//   6007598c FUN_6007598c
//   600819cc FUN_600819cc
//   600650dc FUN_600650dc
//   6005d694 FUN_6005d694
//   6005ee1c FUN_6005ee1c
//   6007fc98 FUN_6007fc98
//   600748ec FUN_600748ec
//   60074658 timer__60074658
//   6005cd20 FUN_6005cd20
//   60063a24 FUN_60063a24
//   60080278 FUN_60080278
//   600769ec FUN_600769ec
//   60080a78 FUN_60080a78
//   600761d4 FUN_600761d4
// --- callees ---


undefined8 FUN_60101c48(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (DAT_600cdb48 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 2;
    param_1 = param_2;
  }
  return CONCAT44(param_1,uVar1);
}


