// 60048474  FUN_60048474  size=32 bytes
// --- callers ---
// --- callees ---
//   6004c084 thunk_FUN_601016a2
//   600485c8 FUN_600485c8
//   60048580 FUN_60048580


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_60048474(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    thunk_FUN_601016a2(_DAT_60048498,0x3cb,_DAT_60048494);
  }
  FUN_60048580();
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  FUN_600485c8();
  return uVar1;
}


