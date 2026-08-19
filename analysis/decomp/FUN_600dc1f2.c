// 600dc1f2  FUN_600dc1f2  size=36 bytes
// --- callers ---
//   600dc38e FUN_600dc38e
// --- callees ---
//   600dc1c0 FUN_600dc1c0


uint * FUN_600dc1f2(uint *param_1,uint param_2,uint param_3)

{
  undefined4 uStack_c;
  
  uStack_c = param_2 & 0xffff;
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_600dc1c0(param_1 + 2,0x1e0,(int)&uStack_c + 2,&uStack_c,param_1);
  return param_1;
}


