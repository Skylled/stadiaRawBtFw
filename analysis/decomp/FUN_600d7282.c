// 600d7282  FUN_600d7282  size=54 bytes
// --- callers ---
//   600d72b8 FUN_600d72b8
//   600d72ec FUN_600d72ec
// --- callees ---
//   601010c8 FUN_601010c8
//   600cb598 key_value_store__600cb598


uint FUN_600d7282(undefined4 param_1,undefined4 param_2,undefined4 param_3,ushort param_4)

{
  uint uVar1;
  undefined4 uStack_14;
  
  uStack_14 = (uint)param_4;
  uVar1 = FUN_601010c8(param_1,param_2,(int)&uStack_14 + 2,0,param_1,param_2,param_3);
  if ((uVar1 & 0xff) == 0) {
    if (uStack_14._2_2_ == 4) {
      uVar1 = key_value_store__600cb598(param_1,param_2,param_3,4,0);
    }
    else {
      uVar1 = 3;
    }
  }
  return uVar1;
}


