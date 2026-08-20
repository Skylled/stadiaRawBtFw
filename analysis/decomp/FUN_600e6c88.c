// 600e6c88  FUN_600e6c88  size=68 bytes
// --- callers ---
//   600e7124 FUN_600e7124
//   600e70ba FUN_600e70ba
//   600e6e26 FUN_600e6e26
//   6008deac FUN_6008deac
//   600e6dfe FUN_600e6dfe
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600e6bea FUN_600e6bea
//   600e6ac2 FUN_600e6ac2


void FUN_600e6c88(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  thunk_EXT_FUN_0000b5ba(param_1,0,0x20);
  for (puVar1 = param_1; puVar1 != param_1 + param_3; puVar1 = puVar1 + 1) {
    FUN_600e6bea(&local_28,param_2);
    param_2 = param_2 + 0x10;
    *puVar1 = local_28;
    puVar1[2] = local_24;
    puVar1[4] = local_20;
    puVar1[6] = local_1c;
  }
  FUN_600e6ac2(param_1);
  return;
}


