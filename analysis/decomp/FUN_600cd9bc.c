// 600cd9bc  FUN_600cd9bc  size=126 bytes
// --- callers ---
//   600ccfb4 FUN_600ccfb4
// --- callees ---


float FUN_600cd9bc(float param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_cr0;
  undefined4 in_cr7;
  float fVar3;
  
  uVar2 = ((uint)ABS(param_1) >> 0x17) - 0x7f;
  fVar3 = param_1;
  if ((int)uVar2 < 0x17) {
    if ((int)uVar2 < 0) {
      if ((0.0 < param_1 + DAT_600cda40) && (fVar3 = DAT_600cda44, (int)param_1 < 0)) {
        coprocessor_function2(10,0,1,in_cr0,in_cr0,in_cr7);
        return param_1;
      }
    }
    else {
      uVar1 = DAT_600cda3c >> (uVar2 & 0xff);
      if ((((uint)param_1 & uVar1) != 0) && (0.0 < param_1 + DAT_600cda40)) {
        if ((int)param_1 < 0) {
          param_1 = (float)((int)param_1 + (0x800000 >> (uVar2 & 0xff)));
        }
        return (float)((uint)param_1 & ~uVar1);
      }
    }
  }
  else if (0x7f7fffff < (uint)ABS(param_1)) {
    return param_1 + param_1;
  }
  return fVar3;
}


