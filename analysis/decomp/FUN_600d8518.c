// 600d8518  FUN_600d8518  size=70 bytes
// --- callers ---
//   60068b80 battery_gauge_bq2742X__60068b80
//   600d855e FUN_600d855e
// --- callees ---
//   600d8448 FUN_600d8448
//   600d84f2 FUN_600d84f2


uint FUN_600d8518(undefined4 param_1,undefined4 param_2,undefined4 param_3,byte *param_4)

{
  uint uVar1;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  uStack_1c = param_2;
  uStack_18 = param_3;
  uVar1 = FUN_600d8448(param_1,param_2,(int)&uStack_1c + 2,param_4,param_1);
  if ((uVar1 & 0xff) == 0) {
    uVar1 = FUN_600d84f2(param_1,param_2,param_3);
    if ((uVar1 & 0xff) == 0) {
      *param_4 = ~((char)((uint)param_3 >> 8) +
                  (~*param_4 - ((char)((uint)uStack_1c >> 0x10) + (char)((uint)uStack_1c >> 0x18)))
                  + (char)param_3);
      uVar1 = 0;
    }
  }
  return uVar1;
}


