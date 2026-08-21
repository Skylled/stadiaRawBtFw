// 600ece78  FUN_600ece78  size=42 bytes
// --- callers ---
//   600861c0 pem_lib__600861c0
//   600ecea2 thunk_FUN_600ece78
//   60086b98 FUN_60086b98
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60090f24 buf__60090f24


uint FUN_600ece78(uint *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = buf__60090f24();
  if (iVar1 == 0) {
    param_2 = 0;
  }
  else {
    uVar2 = *param_1;
    if ((uVar2 < param_2) && (param_2 - uVar2 != 0)) {
      thunk_EXT_FUN_0000b5ba(param_1[1] + uVar2,0,param_2 - uVar2,uVar2,param_4);
    }
    *param_1 = param_2;
  }
  return param_2;
}


