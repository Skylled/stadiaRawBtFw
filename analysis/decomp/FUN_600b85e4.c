// 600b85e4  FUN_600b85e4  size=666 bytes
// --- callers ---
//   600bcca8 FUN_600bcca8
// --- callees ---
//   600b74d8 FUN_600b74d8
//   600d9250 FUN_600d9250
//   600b742c FUN_600b742c
//   6006dfa4 FUN_6006dfa4


short * FUN_600b85e4(short *param_1,ushort param_2)

{
  int iVar1;
  short *psVar2;
  char *pcVar3;
  bool bVar4;
  bool bVar5;
  ushort local_16;
  short *local_14;
  short local_e;
  bool local_9;
  
  local_9 = false;
  bVar4 = false;
  bVar5 = false;
  local_e = 0;
  local_16 = param_1[0x8c];
  if (*(int *)(param_1 + 0x6e) == 0) {
    if ((0xc < param_2) && ((uint)param_2 < local_16 + 0xc)) {
      local_16 = param_2 - 0xc;
    }
    psVar2 = *(short **)(param_1 + 0x98);
    if (local_16 < (ushort)psVar2[1]) {
      bVar4 = *psVar2 != 0;
      if (!bVar4) {
        local_e = psVar2[1];
      }
      local_9 = !bVar4;
      local_14 = (short *)FUN_600b742c(psVar2,0xf,local_16,(char)param_1[0x56]);
      if (local_14 == (short *)0x0) {
        return (short *)0x0;
      }
      *psVar2 = *param_1;
      *local_14 = *param_1;
      psVar2[1] = psVar2[1] - local_16;
      psVar2[2] = local_16 + psVar2[2];
      local_14[3] = psVar2[3];
    }
    else {
      local_14 = (short *)FUN_600d9250(param_1 + 0x98);
      bVar5 = *local_14 != 0;
      *local_14 = *param_1;
    }
    local_14[2] = local_14[2] + -6;
    local_14[1] = local_14[1] + 6;
    if (local_9) {
      local_14[2] = local_14[2] + -2;
      local_14[1] = local_14[1] + 2;
    }
    pcVar3 = (char *)((int)local_14 + (ushort)local_14[2] + 8);
    *pcVar3 = (char)local_14[1] + -4;
    pcVar3[1] = (char)((ushort)local_14[1] - 4 >> 8);
    pcVar3[2] = (char)param_1[1];
    pcVar3[3] = (char)((ushort)param_1[1] >> 8);
    if (local_9) {
      pcVar3[6] = (char)local_e;
      pcVar3[7] = (char)((ushort)local_e >> 8);
      local_14[3] = local_14[3] | 0x4000;
    }
    else if (bVar4) {
      local_14[3] = (ushort)DAT_600b8880 | local_14[3];
    }
    else if (bVar5) {
      local_14[3] = (ushort)DAT_600b8884 | local_14[3];
    }
    else {
      local_14[3] = local_14[3];
    }
    FUN_600b74d8(param_1,local_14,0);
    if ((char)param_1[0x3f] == '\x03') {
      iVar1 = FUN_600b742c(local_14,4,local_14[1],(char)param_1[0x56]);
      if (iVar1 == 0) {
        if (*(char *)((int)param_1 + 0x11f) != '\x03') {
          local_14[1] = local_14[1] + -2;
        }
        FUN_6006dfa4(param_1 + 0x62,local_14);
        local_14 = (short *)0x0;
      }
      else {
        if (*(char *)((int)param_1 + 0x11f) != '\x03') {
          *(short *)(iVar1 + 2) = *(short *)(iVar1 + 2) + -2;
        }
        *(short *)(iVar1 + 6) = local_14[3];
        FUN_6006dfa4(param_1 + 0x62,iVar1);
      }
    }
  }
  else {
    local_14 = (short *)FUN_600d9250(param_1 + 0x6e);
    FUN_600b74d8(param_1,local_14,1);
    *local_14 = *param_1;
  }
  return local_14;
}


