// 600d2140  FUN_600d2140  size=76 bytes
// --- callers ---
//   600563b8 FUN_600563b8
// --- callees ---
//   600d15e4 thunk_EXT_FUN_000080d8
//   600d332a FUN_600d332a
//   600569e4 FUN_600569e4
//   600d3256 FUN_600d3256


undefined4 FUN_600d2140(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 3;
  }
  else {
    if (param_2 == 0) {
      FUN_600569e4();
    }
    else {
      if (*(int *)(param_2 + 0x14) != 0) {
        FUN_600d332a(*(undefined4 *)(param_2 + 4),*(int *)(param_2 + 0x14),0,param_4,param_4);
        FUN_600d3256(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 0x14));
        *(undefined4 *)(param_2 + 0x14) = 0;
      }
      if ((*(int *)(param_2 + 0x10) != 0) && (*(int *)(param_2 + 0x1c) != 0)) {
        FUN_600d332a(*(undefined4 *)(param_2 + 4));
      }
      FUN_600569e4(param_1,*(undefined4 *)(param_2 + 0xc));
      thunk_EXT_FUN_000080d8(param_2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


