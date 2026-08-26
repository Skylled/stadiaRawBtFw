// 600d9202  FUN_600d9202  size=44 bytes
// --- callers ---
//   600ef0f4 FUN_600ef0f4
// --- callees ---
//   6006cf20 FUN_6006cf20


void FUN_600d9202(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5,undefined2 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_6006cf20(param_1,param_3,param_4,param_5);
  if (iVar1 == 0) {
    uVar2 = 0x85;
  }
  else {
    uVar2 = 0;
  }
  func_0x6006d954(param_1,param_2,uVar2,param_6);
  return;
}


