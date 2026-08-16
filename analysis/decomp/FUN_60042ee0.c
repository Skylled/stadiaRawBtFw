// 60042ee0  FUN_60042ee0  size=322 bytes
// --- callers ---
//   60043028 FUN_60043028
// --- callees ---
//   6004bcde FUN_6004bcde
//   60049096 FUN_60049096


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_60042ee0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  bVar6 = 0;
  bVar5 = 0;
  for (iVar7 = param_1 + 0x24c; uVar1 = _DAT_60043024, iVar7 != param_1 + 0x3a0;
      iVar7 = iVar7 + 0x14) {
    bVar2 = func_0x600494e6(param_1,param_2,iVar7);
    bVar5 = bVar5 | bVar2;
    bVar6 = bVar6 | **(byte **)(iVar7 + 0x10);
  }
  if ((bVar5 != 0) && (*(char *)(param_1 + 0x415) != '\0')) {
    if (bVar6 == 0) {
      uVar3 = func_0x6004c0ac();
      uStack_2c = uVar3;
      FUN_6004bcde();
      uVar4 = 0;
    }
    else {
      uVar3 = func_0x6004c0ac();
      uVar4 = func_0x6004c0d4(0x26);
      uStack_2c = uVar3;
      FUN_6004bcde(uVar3);
    }
    uStack_24 = 0;
    uStack_28 = uVar1;
    func_0x6004bebc(uVar3,0,uVar4,bVar6 != 0,uVar1,0);
    FUN_60049096(&uStack_2c);
  }
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  if ((*(char *)(param_1 + 0x412) != '\0') != (bool)*(char *)(param_1 + 0x23c)) {
    DataMemoryBarrier(0x1b);
    bVar5 = 1;
    DataMemoryBarrier(0x1b);
    *(bool *)(param_1 + 0x23c) = *(char *)(param_1 + 0x412) != '\0';
  }
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  if ((*(char *)(param_1 + 0x413) != '\0') != (bool)*(char *)(param_1 + 0x23d)) {
    DataMemoryBarrier(0x1b);
    bVar5 = 1;
    DataMemoryBarrier(0x1b);
    *(bool *)(param_1 + 0x23d) = *(char *)(param_1 + 0x413) != '\0';
  }
  DataMemoryBarrier(0x1b);
  DataMemoryBarrier(0x1b);
  if ((*(char *)(param_1 + 0x414) != '\0') != (bool)*(char *)(param_1 + 0x23e)) {
    DataMemoryBarrier(0x1b);
    bVar5 = 1;
    DataMemoryBarrier(0x1b);
    *(bool *)(param_1 + 0x23e) = *(char *)(param_1 + 0x414) != '\0';
  }
  return bVar5;
}


