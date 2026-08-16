// 60101c48  FUN_60101c48  size=34 bytes
// --- callers ---
//   60080a78 FUN_60080a78
//   600650dc FUN_600650dc
//   6007598c FUN_6007598c
//   6005cd20 FUN_6005cd20
//   60074658 timer__60074658
//   600748ec FUN_600748ec
//   6005d694 FUN_6005d694
//   6007fc98 FUN_6007fc98
//   60063a24 FUN_60063a24
//   600761d4 FUN_600761d4
//   60080278 FUN_60080278
//   600769ec FUN_600769ec
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


