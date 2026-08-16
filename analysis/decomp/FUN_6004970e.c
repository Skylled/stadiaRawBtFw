// 6004970e  FUN_6004970e  size=164 bytes
// --- callers ---
//   60046c78 FUN_60046c78
// --- callees ---
//   6004bb60 FUN_6004bb60
//   6004c084 thunk_FUN_601016a2
//   600485c8 FUN_600485c8
//   60048580 FUN_60048580
//   6004bb1a FUN_6004bb1a


/* WARNING: Removing unreachable block (ram,0x60048156) */
/* WARNING: Removing unreachable block (ram,0x6004818c) */
/* WARNING: Removing unreachable block (ram,0x600481a2) */
/* WARNING: Removing unreachable block (ram,0x600481c8) */
/* WARNING: Removing unreachable block (ram,0x600481d4) */
/* WARNING: Removing unreachable block (ram,0x600481e0) */
/* WARNING: Removing unreachable block (ram,0x60048190) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_6004970e(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = *(uint *)(param_1 + 0x58);
  uVar3 = (ulonglong)uVar2;
  if (uVar2 == 0) {
    uVar3 = thunk_FUN_601016a2(_DAT_600481f8,0x136b,_DAT_600481f4,0,0);
  }
  FUN_60048580((int)uVar3,(int)(uVar3 >> 0x20));
  *(undefined1 *)(uVar2 + 200) = 2;
                    /* WARNING: Could not recover jumptable at 0x6004816e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)((uint)bRam60048173 * 2 + 0x60048172))();
  return uVar1;
}


