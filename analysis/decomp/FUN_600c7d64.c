// 600c7d64  FUN_600c7d64  size=336 bytes
// --- callers ---
//   600ffada FUN_600ffada
//   600c7eb8 FUN_600c7eb8
// --- callees ---
//   6006dcdc FUN_6006dcdc


int FUN_600c7d64(ushort param_1,char param_2,undefined2 param_3,undefined2 param_4,ushort param_5,
                int param_6)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char *local_18;
  char *local_14;
  
  iVar1 = FUN_6006dcdc(2,DAT_600c7eb4,0x128);
  if (iVar1 != 0) {
    pcVar2 = (char *)(iVar1 + 0x16);
    *(char *)(iVar1 + 0x15) = param_2;
    *(undefined2 *)(iVar1 + 4) = 0xd;
    *(undefined2 *)(iVar1 + 2) = 1;
    local_14 = pcVar2;
    if (param_2 == '\t') {
      local_14 = (char *)(iVar1 + 0x17);
      *pcVar2 = (char)param_5 + '\x02';
      *(short *)(iVar1 + 2) = *(short *)(iVar1 + 2) + 1;
      local_18 = pcVar2;
    }
    if ((param_2 != '\r') && (param_2 != '\v')) {
      pcVar2 = local_14 + 1;
      *local_14 = (char)param_3;
      local_14 = local_14 + 2;
      *pcVar2 = (char)((ushort)param_3 >> 8);
      *(short *)(iVar1 + 2) = *(short *)(iVar1 + 2) + 2;
    }
    if ((param_2 == '\x16') || (param_2 == '\x17')) {
      pcVar2 = local_14 + 1;
      *local_14 = (char)param_4;
      local_14 = local_14 + 2;
      *pcVar2 = (char)((ushort)param_4 >> 8);
      *(short *)(iVar1 + 2) = *(short *)(iVar1 + 2) + 2;
    }
    if ((param_5 != 0) && (param_6 != 0)) {
      if (((int)((uint)param_1 - (uint)*(ushort *)(iVar1 + 2)) < (int)(uint)param_5) &&
         (param_5 = param_1 - *(short *)(iVar1 + 2), param_2 == '\t')) {
        *local_18 = (char)param_5 + '\x02';
      }
      for (iVar3 = 0; iVar3 < (int)(uint)param_5; iVar3 = iVar3 + 1) {
        *local_14 = *(char *)(iVar3 + param_6);
        local_14 = local_14 + 1;
      }
      *(ushort *)(iVar1 + 2) = param_5 + *(short *)(iVar1 + 2);
    }
  }
  return iVar1;
}


