// 6009f5d0  FUN_6009f5d0  size=54 bytes
// --- callers ---
//   6009f644 FUN_6009f644
// --- callees ---
//   6009f4e4 FUN_6009f4e4
//   60098284 FUN_60098284
//   600b1c7c FUN_600b1c7c


undefined4 FUN_6009f5d0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_6009f4e4();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if ((*(byte *)(DAT_6009f608 + 0x831) & 0x40) == 0) {
      FUN_60098284(0,1);
    }
    else {
      FUN_600b1c7c(0);
    }
    uVar2 = 1;
  }
  return uVar2;
}


