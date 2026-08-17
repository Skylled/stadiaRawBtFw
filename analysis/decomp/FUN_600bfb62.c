// 600bfb62  FUN_600bfb62  size=174 bytes
// --- callers ---
//   6013aad0 FUN_6013aad0
// --- callees ---


undefined4 FUN_600bfb62(void)

{
  undefined4 uVar1;
  int in_r3;
  int unaff_r7;
  bool in_ZR;
  bool in_CY;
  
  if (!in_CY || in_ZR) {
                    /* WARNING: Could not recover jumptable at 0x600bfb66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(&switchD_600bfb66::switchdataD_600bfb6c)[in_r3])();
    return uVar1;
  }
  return *(undefined4 *)(unaff_r7 + 0xc);
}


