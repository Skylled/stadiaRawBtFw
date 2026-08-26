// 600d9198  FUN_600d9198  size=36 bytes
// --- callers ---
//   600fe930 FUN_600fe930
//   600ee9f6 FUN_600ee9f6
// --- callees ---
//   600d90b6 FUN_600d90b6


void FUN_600d9198(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600d90b6(param_1,param_4);
  if (iVar1 == 0) {
    uVar2 = 0x85;
  }
  else {
    uVar2 = 0;
  }
  func_0x6006d8c8(param_1,param_2,uVar2,param_3);
  return;
}


