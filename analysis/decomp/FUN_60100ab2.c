// 60100ab2  FUN_60100ab2  size=26 bytes
// --- callers ---
//   6006bc20 FUN_6006bc20
// --- callees ---
//   6004cb28 FUN_6004cb28


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60100ab2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint extraout_r3;
  undefined4 uVar4;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  
  uVar2 = FUN_6004cb28(param_2);
  uVar3 = (uint)*_DAT_600caf60;
  if (uVar3 == 0) {
    FUN_600cae68();
    uVar3 = extraout_r3;
  }
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x20);
  }
  FUN_600caec8(param_1,param_2,uVar2,uVar3,param_4,unaff_r4,unaff_r5);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  return;
}


