// 600b842c  FUN_600b842c  size=410 bytes
// --- callers ---
//   600b7db8 FUN_600b7db8
//   600b7cba FUN_600b7cba
// --- callees ---
//   600d9250 FUN_600d9250
//   600f9db4 FUN_600f9db4
//   6006ddd8 FUN_6006ddd8
//   600b9408 FUN_600b9408
//   600d9290 FUN_600d9290
//   600d92fc FUN_600d92fc
//   600b742c FUN_600b742c
//   6006dfa4 FUN_6006dfa4


undefined4 FUN_600b842c(short *param_1,byte param_2)

{
  short *psVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  short *local_c;
  
  if (((*(int *)(param_1 + 0x62) == 0) || ((char)param_1[0x40] == '\0')) ||
     (*(byte *)(param_1 + 0x5a) < *(byte *)(param_1 + 0x40))) {
    if (param_2 == 0xff) {
      local_c = *(short **)(*(int *)(param_1 + 0x96) + 0x80);
      while (local_c != (short *)0x0) {
        if ((local_c[3] == 0) && (*local_c == *param_1)) {
          psVar1 = (short *)FUN_600d92fc(local_c);
          FUN_600d9290(*(int *)(param_1 + 0x96) + 0x80,local_c);
          FUN_6006ddd8(local_c,DAT_600b85e0,0x61a);
          local_c = psVar1;
        }
        else {
          local_c = (short *)FUN_600d92fc(local_c);
        }
      }
      while (*(int *)(param_1 + 0x6e) != 0) {
        uVar3 = FUN_600d9250(param_1 + 0x6e);
        FUN_6006ddd8(uVar3,DAT_600b85e0,0x622);
      }
      local_c = *(short **)(param_1 + 0x62);
    }
    else {
      local_c = *(short **)(param_1 + 0x62);
      while ((local_c != (short *)0x0 &&
             (pbVar4 = (byte *)((uint)*(ushort *)((int)local_c + 4) + (int)local_c + 0xc),
             param_2 !=
             ((byte)((int)(uint)(ushort)((ushort)pbVar4[1] * 0x100 + (ushort)*pbVar4) >> 1) & 0x3f))
             )) {
        local_c = (short *)FUN_600d92fc(local_c);
      }
      if (local_c == (short *)0x0) {
        return 1;
      }
    }
    for (; local_c != (short *)0x0; local_c = (short *)FUN_600d92fc(local_c)) {
      iVar2 = FUN_600b742c(local_c,*(undefined2 *)((int)local_c + 4),
                           *(undefined2 *)((int)local_c + 2),(char)param_1[0x56]);
      if (iVar2 != 0) {
        *(undefined2 *)(iVar2 + 6) = *(undefined2 *)((int)local_c + 6);
        FUN_6006dfa4(param_1 + 0x6e,iVar2);
      }
      if ((param_2 != 0xff) || (iVar2 == 0)) break;
    }
    FUN_600b9408(*(undefined4 *)(param_1 + 0x96),0,0);
    if (param_1[0x66] != 0) {
      *(char *)(param_1 + 0x5a) = (char)param_1[0x5a] + '\x01';
      FUN_600b731c(param_1);
    }
    uVar3 = 1;
  }
  else {
    FUN_600f9db4(param_1);
    uVar3 = 0;
  }
  return uVar3;
}


