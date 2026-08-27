// 600cafcc  FUN_600cafcc  size=28 bytes
// --- callers ---
//   600cb030 mpu__600cb030
// --- callees ---


undefined4 FUN_600cafcc(uint param_1)

{
  int iVar1;
  
  iVar1 = DAT_600cafe8;
  if (0xf < param_1) {
    return 3;
  }
  *(uint *)(DAT_600cafe8 + 8) = param_1;
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffffffe;
  return 0;
}


