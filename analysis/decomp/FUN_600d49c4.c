// 600d49c4  FUN_600d49c4  size=14 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_600d49c4(void)

{
  undefined4 uVar1;
  
  uVar1 = DAT_6005fddc;
  *(uint *)(*(int *)(DAT_6005fdd8 + 0x10) + 0x18) =
       *(uint *)(*(int *)(DAT_6005fdd8 + 0x10) + 0x18) & 0xffff;
                    /* WARNING: Could not recover jumptable at 0x6013d3a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_6013d3ac)(uVar1,5);
  return;
}


