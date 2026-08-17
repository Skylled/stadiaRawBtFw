// 600bfe2c  FUN_600bfe2c  size=126 bytes
// --- callers ---
//   600be558 FUN_600be558
//   600beb20 FUN_600beb20
//   600fa73c FUN_600fa73c
//   600bfeec FUN_600bfeec
// --- callees ---


short FUN_600bfe2c(uint *param_1)

{
  uint uVar1;
  short local_a;
  
  uVar1 = (uint)*(byte *)((int)param_1 + 10);
  if ((uVar1 == 4) || ((3 < uVar1 && (uVar1 - 6 < 3)))) {
    if (*param_1 < 0x100) {
      local_a = 5;
    }
    else {
      local_a = 6;
    }
    local_a = local_a + (short)*param_1;
  }
  else {
    switch(*param_1) {
    case 1:
    case 2:
    case 4:
    case 8:
    case 0x10:
      local_a = 4;
      break;
    default:
      local_a = 5;
    }
    local_a = local_a + (short)*param_1;
  }
  return local_a;
}


