// 600de85a  FUN_600de85a  size=94 bytes
// --- callers ---
//   600ddfde FUN_600ddfde
// --- callees ---
//   60101fcc FUN_60101fcc
//   6013d378 thunk_EXT_FUN_0000b532


int * FUN_600de85a(int *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint in_fpscr;
  float fVar4;
  
  fVar4 = (float)VectorUnsignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
  *param_1 = param_2;
  param_1[1] = param_3 + -1;
  uVar2 = param_2 * (param_3 + -1);
  param_1[5] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[2] = (int)(1.0 / fVar4);
  if (uVar2 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    if (0x3fffffff < uVar2) {
      FUN_60101fcc();
    }
    puVar1 = (undefined4 *)thunk_EXT_FUN_0000b532(uVar2 * 4);
  }
  puVar3 = puVar1 + uVar2;
  param_1[3] = (int)puVar1;
  param_1[4] = (int)puVar1;
  param_1[5] = (int)puVar3;
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  param_1[4] = (int)puVar3;
  param_1[6] = 0;
  return param_1;
}


