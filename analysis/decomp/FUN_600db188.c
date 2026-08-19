// 600db188  FUN_600db188  size=40 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


uint FUN_600db188(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = 0x100 - *(int *)(param_1 + 0x100);
  if (param_3 <= uVar1) {
    uVar1 = param_3;
  }
  thunk_EXT_FUN_0000b572(*(int *)(param_1 + 0x100) + param_1,param_2,uVar1,param_4,param_4);
  *(uint *)(param_1 + 0x100) = *(int *)(param_1 + 0x100) + uVar1;
  return uVar1;
}


