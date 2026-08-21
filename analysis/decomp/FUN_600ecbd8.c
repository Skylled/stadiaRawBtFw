// 600ecbd8  FUN_600ecbd8  size=20 bytes
// --- callers ---
//   60090940 FUN_60090940
// --- callees ---
//   600ecb72 FUN_600ecb72
//   600867c8 FUN_600867c8


undefined4 FUN_600ecbd8(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600ecb72();
  if (iVar1 != 0) {
    uVar2 = FUN_600867c8();
    return uVar2;
  }
  return 1;
}


