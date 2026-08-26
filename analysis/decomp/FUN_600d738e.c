// 600d738e  FUN_600d738e  size=30 bytes
// --- callers ---
//   6005c07c FUN_6005c07c
// --- callees ---
//   600d72ec FUN_600d72ec


uint FUN_600d738e(undefined4 param_1,uint3 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uStack_c;
  
  uStack_c = (uint)param_2;
  cVar1 = FUN_600d72ec(param_1,(int)&uStack_c + 3,param_3,param_4,param_1);
  if (cVar1 == '\0') {
    uStack_c = uStack_c >> 0x18;
  }
  else {
    uStack_c = 0;
  }
  return uStack_c;
}


