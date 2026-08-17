// 6009bb50  FUN_6009bb50  size=92 bytes
// --- callers ---
//   6009bbb0 FUN_6009bbb0
//   600f0f26 FUN_600f0f26
// --- callees ---
//   600aa340 FUN_600aa340
//   600b0974 FUN_600b0974
//   600aa3cc FUN_600aa3cc


void FUN_6009bb50(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_6009bbac;
  if (param_1 != 0) {
    DAT_6009bbac[6] = *(undefined1 *)(param_1 + 4);
    puVar1[5] = *(undefined1 *)(param_1 + 5);
    puVar1[4] = *(undefined1 *)(param_1 + 6);
    FUN_600b0974(puVar1 + 1);
    *puVar1 = 1;
    FUN_600aa3cc(puVar1 + 0x1c);
    FUN_600aa340(puVar1 + 0x1c,0x33,900);
  }
  return;
}


