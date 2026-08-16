// 60046c78  FUN_60046c78  size=80 bytes
// --- callers ---
// --- callees ---


/* WARNING: Removing unreachable block (ram,0x60048514) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_60046c78(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((*(uint *)(_DAT_60046c98 + 4) & 0x1ff) == 0) {
    uVar1 = func_0x6004970e();
    return uVar1;
  }
  iVar2 = func_0x6004c27c(*(undefined4 *)(param_1 + 100));
  return (uint)(iVar2 == 1);
}


