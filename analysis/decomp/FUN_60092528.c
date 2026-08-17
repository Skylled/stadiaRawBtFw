// 60092528  FUN_60092528  size=78 bytes
// --- callers ---
//   600ee100 FUN_600ee100
// --- callees ---
//   600ee0c8 FUN_600ee0c8
//   601007e6 FUN_601007e6
//   6013d038 thunk_EXT_FUN_00008832


undefined4 FUN_60092528(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int local_14;
  
  *param_1 = 0;
  local_14 = param_2;
  local_14 = thunk_EXT_FUN_00008832(0x10);
  iVar2 = DAT_60092578;
  if (local_14 != 0) {
    *(undefined4 *)(local_14 + 4) = 0;
    if (param_2 == 0) {
      param_2 = iVar2;
    }
    uVar3 = *(uint *)(param_2 + 4);
    *(uint *)(local_14 + 8) = uVar3;
    *(undefined4 *)(local_14 + 0xc) = 0;
    if ((uVar3 & 0xfffffffd) == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 4;
    }
    iVar2 = FUN_601007e6(uVar1);
    if (iVar2 != 0) {
      *(int *)(local_14 + 0xc) = iVar2;
      DataMemoryBarrier(0x1b);
      *param_1 = local_14;
      return 0;
    }
    FUN_600ee0c8(&local_14);
  }
  return 0xc;
}


