// 600ee9c6  FUN_600ee9c6  size=48 bytes
// --- callers ---
//   600eead0 FUN_600eead0
//   600eeb42 FUN_600eeb42
// --- callees ---
//   600ee8f2 FUN_600ee8f2
//   600eeb42 FUN_600eeb42


void FUN_600ee9c6(undefined2 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_600ee8f2(param_1,param_2,5);
  if (iVar1 != 0) {
    FUN_600eeb42(param_1,param_2);
  }
  return;
}


