// 600f7ca0  FUN_600f7ca0  size=74 bytes
// --- callers ---
//   600b9e28 FUN_600b9e28
//   6009eab4 FUN_6009eab4
// --- callees ---
//   600bc994 FUN_600bc994
//   60099c0c FUN_60099c0c
//   60098ec8 FUN_60098ec8
//   600bb6dc FUN_600bb6dc


void FUN_600f7ca0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_600bb6dc(param_1,2);
  iVar2 = FUN_60098ec8(param_1,2);
  if (((iVar1 != 0) && (iVar2 != 0)) && (*(char *)(iVar1 + 1) != '\x04')) {
    FUN_60099c0c(iVar2);
    *(undefined1 *)(iVar1 + 1) = 4;
    FUN_600bc994(iVar1);
  }
  return;
}


