// 60042d3c  FUN_60042d3c  size=6 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60042d3c(int param_1,int param_2)

{
  if (*(char *)(param_1 + 0x390) != '\0') {
    FUN_60042300(0xe,*(undefined4 *)(param_1 + 0x1a8),4,0,_DAT_60042d30,0,_DAT_60042d2c);
  }
  if (*(int *)(param_1 + 0x1e0) == param_2) {
    if ((*(uint *)(_DAT_60042d34 + 4) & 0x1ff) != 0) {
                    /* WARNING: Could not recover jumptable at 0x6004bec4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*_DAT_6004bec8)(*(undefined4 *)(_DAT_60042d38 + 0x78),1);
      return;
    }
    FUN_60042c9c(1);
  }
  return;
}


