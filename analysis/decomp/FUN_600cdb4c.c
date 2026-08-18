// 600cdb4c  FUN_600cdb4c  size=40 bytes
// --- callers ---
//   6004c700 FUN_6004c700
// --- callees ---
//   60051824 exit__60051824


/* WARNING: Removing unreachable block (ram,0x600cdb54) */

void FUN_600cdb4c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *extraout_r2;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  
  pcVar4 = *(code **)(DAT_60119c88 + 0x28);
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)(DAT_60119c88,param_2,param_3,pcVar4,param_4);
  }
  uVar8 = exit__60051824(param_1);
  uVar3 = (undefined4)uVar8;
  *extraout_r2 = (int)((ulonglong)uVar8 >> 0x20);
  iVar7 = DAT_600cdbac;
  iVar5 = DAT_600cdbb0 - DAT_600cdbac;
  for (iVar6 = 0; iVar2 = DAT_600cdbb8, iVar1 = DAT_600cdbb4, iVar6 != iVar5 >> 2; iVar6 = iVar6 + 1
      ) {
    uVar3 = (**(code **)(iVar7 + iVar6 * 4))(uVar3);
  }
  FUN_6013ced0();
  for (iVar7 = 0; iVar7 != iVar2 - iVar1 >> 2; iVar7 = iVar7 + 1) {
    (**(code **)(iVar1 + iVar7 * 4))();
  }
  return;
}


