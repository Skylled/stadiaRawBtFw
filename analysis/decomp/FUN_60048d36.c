// 60048d36  FUN_60048d36  size=34 bytes
// --- callers ---
//   60048d54 FUN_60048d54
// --- callees ---


void FUN_60048d36(int param_1,int param_2)

{
  if (param_2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x6004c29c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_6004c2a0)();
    return;
  }
  if (*(uint *)(param_1 + 0x90) >> 0x1e != 1) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0x7fe3ffff;
  }
  return;
}


