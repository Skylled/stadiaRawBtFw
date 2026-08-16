// 600d9ab2  FUN_600d9ab2  size=18 bytes
// --- callers ---
// --- callees ---
//   6013d1b8 thunk_EXT_FUN_00007c58


void FUN_600d9ab2(void)

{
  int iVar1;
  
  iVar1 = thunk_EXT_FUN_00007c58();
                    /* WARNING: Could not recover jumptable at 0x600d9ac2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 8))(*(undefined4 *)(iVar1 + 0xc),iVar1);
  return;
}


