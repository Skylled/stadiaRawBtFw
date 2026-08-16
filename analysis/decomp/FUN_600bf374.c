// 600bf374  FUN_600bf374  size=60 bytes
// --- callers ---
//   600fa568 FUN_600fa568
//   600fa5a6 FUN_600fa5a6
// --- callees ---
//   6006ddd8 FUN_6006ddd8
//   600aa3cc FUN_600aa3cc


void FUN_600bf374(undefined1 *param_1)

{
  FUN_600aa3cc(param_1 + 8);
  *param_1 = 0;
  if (*(int *)(param_1 + 0x28) != 0) {
    FUN_6006ddd8(*(undefined4 *)(param_1 + 0x28),DAT_600bf3b0,0x97);
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  return;
}


