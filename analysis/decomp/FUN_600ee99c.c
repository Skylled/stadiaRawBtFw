// 600ee99c  FUN_600ee99c  size=42 bytes
// --- callers ---
//   600eeaa6 FUN_600eeaa6
// --- callees ---
//   600ee8f2 FUN_600ee8f2


undefined4 FUN_600ee99c(undefined2 param_1,int param_2)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_2 + 0x30) = 0;
  uVar1 = FUN_600ee8f2(param_1,param_2,4);
  return uVar1;
}


