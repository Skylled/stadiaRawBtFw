// 600caf30  FUN_600caf30  size=52 bytes
// --- callers ---
// --- callees ---
//   600caec8 FUN_600caec8
//   600cae68 FUN_600cae68


void FUN_600caf30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  uint extraout_r3;
  undefined4 uVar3;
  
  uVar2 = (uint)DAT_200277c0;
  if (uVar2 == 0) {
    FUN_600cae68();
    uVar2 = extraout_r3;
  }
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x20);
  }
  FUN_600caec8(param_1,param_2,param_3,uVar2,param_4);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  return;
}


