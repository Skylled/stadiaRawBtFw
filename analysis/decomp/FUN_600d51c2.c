// 600d51c2  FUN_600d51c2  size=46 bytes
// --- callers ---
//   6005f8c0 FUN_6005f8c0
//   6005c07c FUN_6005c07c
// --- callees ---
//   600d5122 FUN_600d5122
//   600d512e FUN_600d512e
//   60061c48 FUN_60061c48


uint FUN_600d51c2(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 *puStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  puStack_20 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  FUN_600d5122(&puStack_20);
  uVar1 = FUN_600d512e(*param_1,&puStack_20);
  if ((uVar1 & 0xff) == 0) {
    FUN_60061c48(&puStack_20,param_2,param_3);
  }
  return uVar1;
}


