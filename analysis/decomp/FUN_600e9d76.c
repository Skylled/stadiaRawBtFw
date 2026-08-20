// 600e9d76  FUN_600e9d76  size=96 bytes
// --- callers ---
//   6008d350 FUN_6008d350
//   600e9dd6 FUN_600e9dd6
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88
//   600e9d5c FUN_600e9d5c
//   6010209a FUN_6010209a


void FUN_600e9d76(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_5c [17];
  
  uVar3 = *(uint *)(param_4 + 0x18);
  if ((uVar3 == param_3) && (uVar3 < 0x12)) {
    thunk_EXT_FUN_0000af88(local_5c,*(undefined4 *)(param_4 + 0x14),uVar3 << 2);
    if (local_5c[0] < 2) {
      for (uVar1 = 1;
          (uVar1 < uVar3 && (uVar2 = local_5c[uVar1], local_5c[uVar1] = uVar2 - 1, uVar2 == 0));
          uVar1 = uVar1 + 1) {
      }
    }
    local_5c[0] = local_5c[0] - 2;
    FUN_600e9d5c(param_1,param_2,uVar3,local_5c,uVar3,param_4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_6010209a();
}


