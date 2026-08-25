// 600f8bd4  FUN_600f8bd4  size=54 bytes
// --- callers ---
//   600a7634 FUN_600a7634
//   600a5ec8 FUN_600a5ec8
//   600f2ba2 FUN_600f2ba2
//   600a6184 FUN_600a6184
// --- callees ---
//   600bb6dc FUN_600bb6dc
//   600aa340 FUN_600aa340


void FUN_600f8bd4(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_600bb6dc(param_1,1);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x5c) == 0)) {
    FUN_600aa340(iVar1 + 0x44,2,0x78);
  }
  return;
}


