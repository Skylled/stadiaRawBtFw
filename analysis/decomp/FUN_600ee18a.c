// 600ee18a  FUN_600ee18a  size=52 bytes
// --- callers ---
// --- callees ---
//   6013d0e8 thunk_EXT_FUN_00006a74


undefined4 FUN_600ee18a(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  
  if (param_2 == 0) {
    uVar1 = 3;
  }
  else {
    uVar1 = 0;
    DataMemoryBarrier(0x1b);
    *(undefined1 *)(param_2 + 8) = 1;
    DataMemoryBarrier(0x1b);
    uStack_14 = param_2 & 0xffffff00;
    uStack_10 = param_2;
    uStack_c = param_4;
    thunk_EXT_FUN_00006a74(*(undefined4 *)(param_1 + 0xb0),&uStack_14,0xffffffff,0,param_1);
  }
  return uVar1;
}


