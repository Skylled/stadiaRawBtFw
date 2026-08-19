// 600defe0  FUN_600defe0  size=52 bytes
// --- callers ---
//   600800c0 FUN_600800c0
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   600def9c FUN_600def9c
//   6013d3d8 thunk_EXT_FUN_0000b4c2


undefined4 FUN_600defe0(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  thunk_EXT_FUN_0000b4c2(param_1 + 0xbc);
  *(uint *)(param_1 + 0x14c) = *(uint *)(param_1 + 0x14c) & ~(1 << (param_2 & 0xff));
  uVar1 = FUN_600def9c(param_1);
  thunk_EXT_FUN_00007d10(param_1 + 0xbc);
  return uVar1;
}


