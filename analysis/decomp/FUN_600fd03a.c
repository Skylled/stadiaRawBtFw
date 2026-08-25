// 600fd03a  FUN_600fd03a  size=136 bytes
// --- callers ---
// --- callees ---
//   600f0252 FUN_600f0252
//   600942d4 FUN_600942d4
//   600944c0 FUN_600944c0


void FUN_600fd03a(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_600944c0(param_1 + 8);
  if (iVar1 != 0) {
    if (*(char *)(param_1 + 0x10) == '\0') {
      *(ushort *)(iVar1 + 6) = ~*(ushort *)(param_1 + 0xe) & *(ushort *)(iVar1 + 6);
      FUN_600f0252(iVar1,iVar1 + 6);
      if ((*(ushort *)(param_1 + 0xe) & 0xc) != 0) {
        FUN_600942d4(iVar1);
      }
    }
    else {
      *(ushort *)(iVar1 + 6) = *(ushort *)(param_1 + 0xe) | *(ushort *)(iVar1 + 6);
      FUN_600f0252(iVar1,iVar1 + 6);
    }
  }
  return;
}


