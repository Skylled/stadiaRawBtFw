// 600d4d2e  FUN_600d4d2e  size=6 bytes
// --- callers ---
//   6005f8c0 FUN_6005f8c0
//   6005f110 FUN_6005f110
//   6005f728 FUN_6005f728
//   6005be94 FUN_6005be94
// --- callees ---
//   60060368 FUN_60060368


void FUN_600d4d2e(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = FUN_60060368();
  iVar3 = (int)((ulonglong)uVar4 >> 0x20);
  piVar1 = (int *)uVar4;
  uVar2 = FUN_60101b0c(iVar3,iVar3 >> 0x1f,piVar1[2] + *piVar1,piVar1[1] - piVar1[2]);
  FUN_60101ba2(piVar1,uVar2);
                    /* WARNING: Could not recover jumptable at 0x600d4d54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  FUN_600d4d34(piVar1);
  return;
}


