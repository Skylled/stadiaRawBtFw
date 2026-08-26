// 600d855e  FUN_600d855e  size=216 bytes
// --- callers ---
//   600d87c0 FUN_600d87c0
// --- callees ---
//   600d8518 FUN_600d8518
//   600d83e0 FUN_600d83e0
//   60068ae0 battery_gauge_bq2742X__60068ae0


void FUN_600d855e(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  
  uVar2 = param_1;
  uStack_c = param_2;
  cVar1 = FUN_600d83e0(param_1,0x44,0,(int)&uStack_c + 3,param_1);
  if (cVar1 == '\0') {
    cVar1 = FUN_600d8518(param_1,9,0x898,(int)&uStack_c + 3);
    if (cVar1 == '\0') {
      cVar1 = battery_gauge_bq2742X__60068ae0(param_1,uStack_c._3_1_,0x44);
      if ((((cVar1 == '\0') &&
           (cVar1 = FUN_600d83e0(param_1,0x50,0,(int)&uStack_c + 3,uVar2), cVar1 == '\0')) &&
          (cVar1 = FUN_600d8518(param_1,0xb,0x3c,(int)&uStack_c + 3), cVar1 == '\0')) &&
         (cVar1 = FUN_600d8518(param_1,0x18,100,(int)&uStack_c + 3), cVar1 == '\0')) {
        cVar1 = FUN_600d8518(param_1,0x1a,18000,(int)&uStack_c + 3);
        if (((cVar1 == '\0') &&
            (cVar1 = battery_gauge_bq2742X__60068ae0(param_1,uStack_c._3_1_,0x50), cVar1 == '\0'))
           && ((cVar1 = FUN_600d83e0(param_1,0x50,1,(int)&uStack_c + 3), cVar1 == '\0' &&
               (cVar1 = FUN_600d8518(param_1,1,0x19,(int)&uStack_c + 3), cVar1 == '\0')))) {
          battery_gauge_bq2742X__60068ae0(param_1,uStack_c._3_1_,0x50,1);
        }
      }
    }
  }
  return;
}


