// 600c78e8  FUN_600c78e8  size=114 bytes
// --- callers ---
//   600ffada FUN_600ffada
//   600c7eb8 FUN_600c7eb8
// --- callees ---
//   6006dcdc FUN_6006dcdc


int FUN_600c78e8(char param_1,byte param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dcdc(2,DAT_600c795c,0x42);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 4) = 0xd;
    *(undefined2 *)(iVar1 + 2) = 1;
    *(char *)(iVar1 + 0x15) = param_1;
    if (param_1 == '\x18') {
      *(byte *)(iVar1 + 0x16) = param_2 & 1;
      *(short *)(iVar1 + 2) = *(short *)(iVar1 + 2) + 1;
    }
  }
  return iVar1;
}


