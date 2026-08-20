// 600e93ca  FUN_600e93ca  size=74 bytes
// --- callers ---
//   6008d350 FUN_6008d350
//   600eaef4 FUN_600eaef4
//   600e9bc2 FUN_600e9bc2
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88
//   6013cee8 thunk_EXT_FUN_0000af90
//   6008b6a8 bcm__6008b6a8
//   6010209a FUN_6010209a
//   6013cfb0 thunk_EXT_FUN_0000ac52


void FUN_600e93ca(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined1 auStack_a0 [140];
  
  uVar1 = *(uint *)(param_4 + 0x18);
  if ((uVar1 == param_3) && (uVar1 < 0x12)) {
    iVar2 = uVar1 * 4;
    thunk_EXT_FUN_0000af88(auStack_a0,param_2,iVar2);
    thunk_EXT_FUN_0000af90(auStack_a0 + iVar2,0,iVar2);
    iVar2 = bcm__6008b6a8(param_1,uVar1,auStack_a0,uVar1 << 1,param_4);
    if (iVar2 != 0) {
      thunk_EXT_FUN_0000ac52(auStack_a0,uVar1 << 3);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_6010209a();
}


