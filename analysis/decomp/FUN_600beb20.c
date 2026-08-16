// 600beb20  FUN_600beb20  size=1966 bytes
// --- callers ---
//   600fa5c6 FUN_600fa5c6
// --- callees ---
//   6006dcdc FUN_6006dcdc
//   6006dbac FUN_6006dbac
//   600fa6bc FUN_600fa6bc
//   600bf6a0 FUN_600bf6a0
//   600bfeec FUN_600bfeec
//   600f7b26 FUN_600f7b26
//   600fa73c FUN_600fa73c
//   600bf3b4 FUN_600bf3b4
//   600fa6e0 FUN_600fa6e0
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600bf8ec FUN_600bf8ec
//   600bfe2c FUN_600bfe2c
//   600bf5a4 FUN_600bf5a4
//   600bd4bc FUN_600bd4bc
//   600fa3e8 FUN_600fa3e8


void FUN_600beb20(undefined4 param_1,int param_2,undefined2 param_3,undefined2 param_4,
                 undefined4 param_5)

{
  short sVar1;
  byte *pbVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 auStack_1f0 [68];
  ushort local_1ac;
  short local_1aa [33];
  short local_168 [145];
  short local_46;
  undefined1 *local_44;
  undefined1 *local_40;
  int local_3c;
  short local_38;
  ushort local_36;
  int local_34;
  short local_2e;
  undefined1 *local_2c;
  char local_26;
  char local_25;
  int local_24;
  ushort local_1e;
  undefined1 *local_1c;
  ushort local_16;
  ushort local_14;
  ushort local_12;
  
  local_25 = '\0';
  local_26 = '\0';
  pbVar2 = (byte *)FUN_600bf6a0(param_5,param_4,local_168);
  if ((pbVar2 == (byte *)0x0) || (local_168[0] == 0)) {
    FUN_600bf5a4(param_2,param_3,3,0);
  }
  else {
    local_12 = (ushort)pbVar2[1] + (ushort)*pbVar2 * 0x100;
    if ((int)(*(ushort *)(param_2 + 0x20) - 10) < (int)(uint)local_12) {
      local_12 = *(short *)(param_2 + 0x20) - 10;
    }
    pcVar3 = (char *)FUN_600bf8ec(pbVar2 + 2,param_4,&local_1ac);
    if ((pcVar3 == (char *)0x0) || (local_1ac == 0)) {
      FUN_600bf5a4(param_2,param_3,3,0);
    }
    else {
      thunk_EXT_FUN_0000b572(auStack_1f0,&local_1ac,0x42);
      if (*pcVar3 == '\0') {
        if (*(int *)(param_2 + 0x28) == 0) {
          uVar4 = FUN_6006dbac(*(undefined2 *)(param_2 + 0x20),DAT_600bf038,0x284);
          *(undefined4 *)(param_2 + 0x28) = uVar4;
          if (*(int *)(param_2 + 0x28) == 0) {
            return;
          }
        }
        FUN_600fa6bc(param_2);
        local_1c = (undefined1 *)(*(int *)(param_2 + 0x28) + 3);
      }
      else {
        if (*pcVar3 != '\x02') {
          FUN_600bf5a4(param_2,param_3,5,0);
          return;
        }
        local_16 = (ushort)(byte)pcVar3[2] + (ushort)(byte)pcVar3[1] * 0x100;
        if (local_16 != *(short *)(param_2 + 0x2c)) {
          FUN_600bf5a4(param_2,param_3,5,0);
          return;
        }
        if (*(int *)(param_2 + 0x28) == 0) {
          FUN_600bf5a4(param_2,param_3,6,0);
          return;
        }
        local_26 = '\x01';
        local_1c = *(undefined1 **)(param_2 + 0x28);
        local_1aa[(uint)*(ushort *)(param_2 + 0x30) * 2] = *(short *)(param_2 + 0x32);
      }
      for (local_24 = FUN_600bd4bc(*(undefined4 *)(param_2 + 0x34),local_168); local_24 != 0;
          local_24 = FUN_600bd4bc(local_24,local_168)) {
        local_2c = local_1c;
        if (*(char *)(param_2 + 0x38) == '\0') {
          local_2e = local_12 - ((short)local_1c - (short)*(undefined4 *)(param_2 + 0x28));
          if (local_2e < 3) {
            *(undefined2 *)(param_2 + 0x30) = 0;
            *(short *)(param_2 + 0x32) = local_1aa[0];
            break;
          }
          local_1c = local_1c + 3;
        }
        for (local_1e = *(ushort *)(param_2 + 0x30); local_1e < local_1ac; local_1e = local_1e + 1)
        {
          local_34 = FUN_600fa3e8(local_24,local_1aa[(uint)local_1e * 2],
                                  local_1aa[(uint)local_1e * 2 + 1]);
          if (local_34 != 0) {
            local_2e = local_12 - ((short)local_1c - (short)*(undefined4 *)(param_2 + 0x28));
            if (local_2e < 1) {
              *(ushort *)(param_2 + 0x30) = local_1e;
              *(undefined2 *)(param_2 + 0x32) = *(undefined2 *)(local_34 + 8);
              local_25 = '\x01';
              break;
            }
            local_36 = FUN_600bfe2c(local_34);
            if (*(short *)(param_2 + 0x3a) == 0) {
              if ((int)local_2e < (int)(uint)local_36) {
                if (0xff < local_36) {
                  FUN_600bf5a4(param_2,param_3,6,0);
                  return;
                }
                local_1c = (undefined1 *)FUN_600bfeec(local_1c,local_34,local_2e,param_2 + 0x3a);
                *(ushort *)(param_2 + 0x30) = local_1e;
                *(undefined2 *)(param_2 + 0x32) = *(undefined2 *)(local_34 + 8);
                local_25 = '\x01';
                break;
              }
              local_1c = (undefined1 *)FUN_600bf3b4(local_1c,local_34);
            }
            else {
              local_1c = (undefined1 *)FUN_600bfeec(local_1c,local_34,local_2e,param_2 + 0x3a);
              if (local_36 != *(ushort *)(param_2 + 0x3a)) {
                local_25 = '\x01';
                break;
              }
              *(undefined2 *)(param_2 + 0x3a) = 0;
            }
            if (local_1aa[(uint)local_1e * 2] != local_1aa[(uint)local_1e * 2 + 1]) {
              local_1aa[(uint)local_1e * 2] = *(short *)(local_34 + 8) + 1;
              local_1e = local_1e - 1;
            }
          }
        }
        if (*(char *)(param_2 + 0x38) == '\0') {
          local_38 = FUN_600fa73c(local_24,auStack_1f0);
          if (local_38 == 0) {
            local_1c = local_2c;
          }
          else {
            *local_2c = 0x36;
            puVar5 = local_2c + 2;
            local_2c[1] = (char)((ushort)local_38 >> 8);
            local_2c = local_2c + 3;
            *puVar5 = (char)local_38;
            if (local_25 != '\0') {
              *(undefined1 *)(param_2 + 0x38) = 1;
            }
          }
        }
        if (local_25 != '\0') break;
        thunk_EXT_FUN_0000b572(&local_1ac,auStack_1f0,0x42);
        *(undefined2 *)(param_2 + 0x30) = 0;
        *(int *)(param_2 + 0x34) = local_24;
        *(undefined1 *)(param_2 + 0x38) = 0;
      }
      local_14 = (short)local_1c - (short)*(undefined4 *)(param_2 + 0x28);
      local_16 = 0;
      if (local_26 == '\0') {
        sVar1 = FUN_600fa6e0(local_168,auStack_1f0);
        *(short *)(param_2 + 0x24) = sVar1 + 3;
        if (*(ushort *)(param_2 + 0x24) < 0x100) {
          local_16 = 1;
          *(undefined1 *)(*(int *)(param_2 + 0x28) + 1) = 0x35;
          *(char *)(*(int *)(param_2 + 0x28) + 2) = (char)*(undefined2 *)(param_2 + 0x24) + -3;
          *(short *)(param_2 + 0x24) = *(short *)(param_2 + 0x24) + -1;
          local_14 = local_14 - 1;
        }
        else {
          **(undefined1 **)(param_2 + 0x28) = 0x36;
          *(char *)(*(int *)(param_2 + 0x28) + 1) = (char)(*(ushort *)(param_2 + 0x24) - 3 >> 8);
          *(char *)(*(int *)(param_2 + 0x28) + 2) = (char)*(undefined2 *)(param_2 + 0x24) + -3;
        }
      }
      local_3c = FUN_6006dcdc(3,DAT_600bf2d4,0x323);
      if (local_3c != 0) {
        *(undefined2 *)(local_3c + 4) = 0xd;
        local_40 = (undefined1 *)(local_3c + 0x15);
        *local_40 = 7;
        *(char *)(local_3c + 0x16) = (char)((ushort)param_3 >> 8);
        local_44 = (undefined1 *)(local_3c + 0x18);
        *(char *)(local_3c + 0x17) = (char)param_3;
        *(char *)(local_3c + 0x1a) = (char)(local_14 >> 8);
        local_1c = (undefined1 *)(local_3c + 0x1c);
        *(char *)(local_3c + 0x1b) = (char)local_14;
        thunk_EXT_FUN_0000b572(local_1c,(uint)local_16 + *(int *)(param_2 + 0x28),local_14);
        puVar5 = (undefined1 *)((uint)local_14 + (int)local_1c);
        *(ushort *)(param_2 + 0x2c) = local_14 + *(short *)(param_2 + 0x2c);
        if (*(ushort *)(param_2 + 0x2c) < *(ushort *)(param_2 + 0x24)) {
          local_26 = '\x01';
          *puVar5 = 2;
          puVar5[1] = (char)((ushort)*(undefined2 *)(param_2 + 0x2c) >> 8);
          local_1c = puVar5 + 3;
          puVar5[2] = (char)*(undefined2 *)(param_2 + 0x2c);
        }
        else {
          local_1c = puVar5 + 1;
          *puVar5 = 0;
        }
        local_46 = ((short)local_1c - (short)local_44) + -2;
        puVar5 = local_44 + 1;
        *local_44 = (char)((ushort)local_46 >> 8);
        local_44 = local_44 + 2;
        *puVar5 = (char)local_46;
        *(short *)(local_3c + 2) = (short)local_1c - (short)local_40;
        FUN_600f7b26(*(undefined2 *)(param_2 + 0x22),local_3c);
      }
    }
  }
  return;
}


