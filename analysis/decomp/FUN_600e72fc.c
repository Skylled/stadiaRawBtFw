// 600e72fc  FUN_600e72fc  size=46 bytes
// --- callers ---
//   600e89f8 FUN_600e89f8
//   6008c5fc bcm__6008c5fc
//   6008b79c bcm__6008b79c
//   600e932c FUN_600e932c
//   6008bf44 bcm__6008bf44
//   600e732a FUN_600e732a
//   6008d120 bcm__6008d120
//   6008b970 bcm__6008b970
//   600e7e9c FUN_600e7e9c
//   6008e264 bcm__6008e264
//   600eaf44 FUN_600eaf44
//   600e778c FUN_600e778c
//   600e957c FUN_600e957c
//   6008c0d8 bcm__6008c0d8
//   600e98c6 FUN_600e98c6
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88
//   6008b43c bcm__6008b43c


undefined4 *
FUN_600e72fc(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_2 != param_1) {
    iVar1 = bcm__6008b43c(param_1,param_2[1],param_3,param_4,param_4);
    if (iVar1 == 0) {
      param_1 = (undefined4 *)0x0;
    }
    else {
      thunk_EXT_FUN_0000af88(*param_1,*param_2,param_2[1] << 2);
      param_1[1] = param_2[1];
      param_1[3] = param_2[3];
    }
  }
  return param_1;
}


