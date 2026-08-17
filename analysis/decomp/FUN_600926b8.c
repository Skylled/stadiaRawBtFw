// 600926b8  FUN_600926b8  size=18 bytes
// --- callers ---
//   60077744 FUN_60077744
//   600d8f9e FUN_600d8f9e
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_600926b8(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iStack_b0;
  uint uStack_ac;
  int iStack_a8;
  undefined1 *puStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined1 uStack_98;
  undefined1 uStack_97;
  undefined1 auStack_96 [130];
  undefined1 uStack_14;
  
  if (*(int *)(DAT_600926cc + 0x58) != 0) {
    if (param_1 == 0) {
      uVar1 = 3;
    }
    else {
      iStack_b0 = 0;
      uStack_ac = uStack_ac & 0xffffff00;
      iStack_a8 = param_1;
      iVar2 = thunk_EXT_FUN_00006bc8(*(undefined4 *)(DAT_600926cc + 0xb0),&uStack_ac,&iStack_b0);
      if (iStack_b0 != 0) {
        *_DAT_6009266c = 0x10000000;
        DataSynchronizationBarrier(0xf);
        InstructionSynchronizationBarrier(0xf);
      }
      if (iVar2 == 1) {
        DataMemoryBarrier(0x1b);
        *(undefined1 *)(param_1 + 8) = 1;
        uVar1 = 0;
        DataMemoryBarrier(0x1b);
      }
      else {
        uStack_ac = _DAT_60092670;
        iStack_b0 = CONCAT31(iStack_b0._1_3_,8);
        iStack_a8 = 0x18;
        puStack_a4 = auStack_96;
        uStack_14 = 8;
        uStack_a0 = 0x80;
        uStack_9c = 0;
        uStack_98 = 0;
        uStack_97 = 0;
        auStack_96[0] = 0;
        uVar3 = FUN_600cbb14(&iStack_b0);
        FUN_60101b76(&puStack_a4,uVar3);
        FUN_60101b76(&puStack_a4,_DAT_60092674);
        FUN_60101b76(&puStack_a4,_DAT_60092678);
        uVar1 = uStack_14;
        FUN_601016f0(0x28,uStack_ac,iStack_a8,&puStack_a4);
      }
    }
    return uVar1;
  }
  return 9;
}


