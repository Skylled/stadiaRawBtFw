// 600c7c68  FUN_600c7c68  size=166 bytes
// --- callers ---
//   600ffada FUN_600ffada
// --- callees ---
//   6006dbac FUN_6006dbac


int FUN_600c7c68(char param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x1a,DAT_600c7d10,0xe8);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 4) = 0xd;
    *(char *)(iVar1 + 0x15) = param_1;
    *(undefined2 *)(iVar1 + 2) = 1;
    *(char *)(iVar1 + 0x16) = (char)param_2;
    *(char *)(iVar1 + 0x17) = (char)((ushort)param_2 >> 8);
    *(short *)(iVar1 + 2) = *(short *)(iVar1 + 2) + 2;
    if (param_1 == '\f') {
      *(char *)(iVar1 + 0x18) = (char)param_3;
      *(char *)(iVar1 + 0x19) = (char)((ushort)param_3 >> 8);
      *(short *)(iVar1 + 2) = *(short *)(iVar1 + 2) + 2;
    }
  }
  return iVar1;
}


