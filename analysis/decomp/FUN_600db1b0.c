// 600db1b0  FUN_600db1b0  size=62 bytes
// --- callers ---
//   60077750 FUN_60077750
// --- callees ---
//   600d4f98 FUN_600d4f98
//   6013d240 thunk_EXT_FUN_00000f80
//   60101818 FUN_60101818


uint FUN_600db1b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = FUN_600d4f98(param_2,param_1,0x100,param_4,param_4);
  if ((uVar1 & 0xff) == 0) {
    FUN_60101818(param_1 + 0x108);
    *(bool *)(param_1 + 0x104) = *(uint *)(param_1 + 0x100) < 0x100;
    thunk_EXT_FUN_00000f80(param_1,0x100);
  }
  return uVar1;
}


