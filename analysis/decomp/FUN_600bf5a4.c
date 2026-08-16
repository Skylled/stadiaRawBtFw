// 600bf5a4  FUN_600bf5a4  size=246 bytes
// --- callers ---
//   600fa5c6 FUN_600fa5c6
//   600be150 FUN_600be150
//   600beb20 FUN_600beb20
//   600be558 FUN_600be558
// --- callees ---
//   600f7b26 FUN_600f7b26
//   6006dcdc FUN_6006dcdc
//   6004cb28 FUN_6004cb28


void FUN_600bf5a4(int param_1,undefined2 param_2,undefined2 param_3,int param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *local_14;
  
  iVar2 = FUN_6006dcdc(3,DAT_600bf69c,0x13a);
  if (iVar2 != 0) {
    *(undefined2 *)(iVar2 + 4) = 0xd;
    *(undefined1 *)(iVar2 + 0x15) = 1;
    *(char *)(iVar2 + 0x16) = (char)((ushort)param_2 >> 8);
    *(char *)(iVar2 + 0x17) = (char)param_2;
    *(char *)(iVar2 + 0x1a) = (char)((ushort)param_3 >> 8);
    local_14 = (undefined1 *)(iVar2 + 0x1c);
    *(char *)(iVar2 + 0x1b) = (char)param_3;
    if (param_4 != 0) {
      for (iVar4 = 0; iVar3 = FUN_6004cb28(param_4), iVar4 < iVar3; iVar4 = iVar4 + 1) {
        *local_14 = *(undefined1 *)(iVar4 + param_4);
        local_14 = local_14 + 1;
      }
    }
    sVar1 = ((short)local_14 - (short)(undefined1 *)(iVar2 + 0x18)) + -2;
    *(undefined1 *)(iVar2 + 0x18) = (char)((ushort)sVar1 >> 8);
    *(char *)(iVar2 + 0x19) = (char)sVar1;
    *(short *)(iVar2 + 2) = (short)local_14 - (short)(undefined1 *)(iVar2 + 0x15);
    FUN_600f7b26(*(undefined2 *)(param_1 + 0x22),iVar2);
  }
  return;
}


