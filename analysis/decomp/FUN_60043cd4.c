// 60043cd4  FUN_60043cd4  size=98 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60043cd4(int param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  
  func_0x600439cc();
  func_0x6004c2a4(param_1,param_2);
  iVar2 = *(int *)(param_1 + 0x18d0) + -1;
  *(int *)(param_1 + 0x18d0) = iVar2;
  if (0 < iVar2) {
                    /* WARNING: Could not recover jumptable at 0x6004be9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_DAT_6004bea0)();
    return;
  }
  func_0x6004c394();
  fVar1 = fRam60043d34;
  *(undefined4 *)(param_1 + 0x18d0) = 500;
  *(float *)(param_1 + 0x2310) =
       (*(float *)(param_1 + 0x2314) / fVar1 + *(float *)(param_1 + 0x2310)) * 0.5;
  *(undefined4 *)(param_1 + 0x2314) = 0;
  return;
}


