// 600f5e3c  FUN_600f5e3c  size=162 bytes
// --- callers ---
// --- callees ---
//   600f60ee FUN_600f60ee
//   600afea0 FUN_600afea0
//   600f6132 FUN_600f6132
//   600ad8fc FUN_600ad8fc
//   600f7a34 FUN_600f7a34
//   600af718 FUN_600af718
//   600f610e FUN_600f610e
//   600f20ac FUN_600f20ac
//   600ada6c FUN_600ada6c


void FUN_600f5e3c(undefined2 param_1,short *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_600afea0(param_1);
  if ((iVar1 != 0) && (iVar2 = FUN_600f6132(iVar1), iVar2 == 3)) {
    if (*param_2 == 0) {
      *(byte *)(iVar1 + 0x1d) = *(byte *)(iVar1 + 0x1d) | 2;
      if ((*(byte *)(iVar1 + 0x1d) & 1) != 0) {
        FUN_600f610e(iVar1,4);
        iVar2 = FUN_600af718(iVar1 + 0xd);
        if (iVar2 == 0) {
          iVar2 = FUN_600f20ac(iVar1 + 0xd);
          if (iVar2 != 0) {
            FUN_600ada6c(iVar1 + 0xd);
          }
        }
        else {
          FUN_600f60ee(iVar2);
        }
        FUN_600ad8fc(iVar1);
      }
    }
    else {
      FUN_600f7a34(param_1);
    }
  }
  return;
}


