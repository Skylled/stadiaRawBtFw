// 600d7d1c  FUN_600d7d1c  size=44 bytes
// --- callers ---
//   60051240 main__60051240
//   60074658 timer__60074658
// --- callees ---
//   600d7cc4 FUN_600d7cc4
//   600d72ec FUN_600d72ec


undefined1 FUN_600d7d1c(undefined4 param_1,uint3 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = (uint)param_2;
  uStack_8 = param_3;
  iVar2 = FUN_600d7cc4();
  if ((iVar2 == 0) || (cVar1 = FUN_600d72ec(0x2b,(int)&uStack_c + 3), cVar1 != '\0')) {
    uStack_c._3_1_ = 0;
  }
  else {
  }
  return uStack_c._3_1_;
}


