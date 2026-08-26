// 600d498c  FUN_600d498c  size=12 bytes
// --- callers ---
// --- callees ---


bool FUN_600d498c(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iStack_c;
  undefined4 uStack_8;
  
  *(undefined4 *)(param_4 + 0x154) = param_3;
  iStack_c = 0;
  uStack_8 = param_3;
  iVar1 = thunk_EXT_FUN_00006c88
                    (*(undefined4 *)(param_4 + 0x148),&iStack_c,param_3,0,param_4 + 0xf8);
  if (iStack_c != 0) {
    *DAT_600cc1f0 = 0x10000000;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  return iVar1 == 1;
}


