// 600be558  FUN_600be558  size=1472 bytes
// --- callers ---
//   600fa5c6 FUN_600fa5c6
// --- callees ---
//   600fa6bc FUN_600fa6bc
//   600bfe2c FUN_600bfe2c
//   6006dbac FUN_6006dbac
//   6006dcdc FUN_6006dcdc
//   600bfeec FUN_600bfeec
//   600fa73c FUN_600fa73c
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600bf8ec FUN_600bf8ec
//   600bf5a4 FUN_600bf5a4
//   600bd5fc FUN_600bd5fc
//   600bf3b4 FUN_600bf3b4
//   600fa3e8 FUN_600fa3e8
//   600f7b26 FUN_600f7b26


void FUN_600be558(undefined4 param_1,int param_2,undefined2 param_3,undefined2 param_4,byte *param_5
                 ,byte *param_6)

{
  short sVar1;
  byte *pbVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 auStack_bc [68];
  ushort local_78;
  short asStack_76 [32];
  short local_36;
  undefined1 *local_34;
  undefined1 *local_30;
  int local_2c;
  ushort local_28;
  short local_26;
  int local_24;
  int local_20;
  int local_1c;
  char local_17;
  ushort local_16;
  undefined1 *local_14;
  ushort local_e;
  ushort local_c;
  ushort local_a;
  
  local_17 = '\0';
  local_1c = (uint)*param_5 * 0x1000000 +
             (uint)param_5[3] + (uint)param_5[2] * 0x100 + (uint)param_5[1] * 0x10000;
  if (param_6 < param_5 + 4) {
    FUN_600bf5a4(param_2,param_3,2,0);
  }
  else {
    local_a = (ushort)param_5[5] + (ushort)param_5[4] * 0x100;
    if ((int)(*(ushort *)(param_2 + 0x20) - 10) < (int)(uint)local_a) {
      local_a = *(short *)(param_2 + 0x20) - 10;
    }
    pbVar2 = (byte *)FUN_600bf8ec(param_5 + 6,param_4,&local_78);
    if (((pbVar2 == (byte *)0x0) || (local_78 == 0)) || (param_6 < pbVar2)) {
      FUN_600bf5a4(param_2,param_3,3,0);
    }
    else {
      thunk_EXT_FUN_0000b572(auStack_bc,&local_78,0x42);
      local_20 = FUN_600bd5fc(local_1c);
      if (local_20 == 0) {
        FUN_600bf5a4(param_2,param_3,2,0);
      }
      else {
        if (*pbVar2 == 0) {
          if (*(int *)(param_2 + 0x28) == 0) {
            uVar3 = FUN_6006dbac(*(undefined2 *)(param_2 + 0x20),DAT_600be948,399);
            *(undefined4 *)(param_2 + 0x28) = uVar3;
            if (*(int *)(param_2 + 0x28) == 0) {
              return;
            }
          }
          FUN_600fa6bc(param_2);
          local_14 = (undefined1 *)(*(int *)(param_2 + 0x28) + 3);
        }
        else {
          if (*pbVar2 != 2) {
            FUN_600bf5a4(param_2,param_3,5,0);
            return;
          }
          local_e = (ushort)pbVar2[2] + (ushort)pbVar2[1] * 0x100;
          if (local_e != *(short *)(param_2 + 0x2c)) {
            FUN_600bf5a4(param_2,param_3,5,0);
            return;
          }
          if (*(int *)(param_2 + 0x28) == 0) {
            FUN_600bf5a4(param_2,param_3,6,0);
            return;
          }
          local_17 = '\x01';
          local_14 = (undefined1 *)*(int *)(param_2 + 0x28);
          asStack_76[(uint)*(ushort *)(param_2 + 0x30) * 2] = *(short *)(param_2 + 0x32);
        }
        for (local_16 = *(ushort *)(param_2 + 0x30); local_16 < local_78; local_16 = local_16 + 1) {
          local_24 = FUN_600fa3e8(local_20,asStack_76[(uint)local_16 * 2],
                                  asStack_76[(uint)local_16 * 2 + 1]);
          if (local_24 != 0) {
            local_26 = local_a - ((short)local_14 - (short)*(undefined4 *)(param_2 + 0x28));
            if (local_26 < 1) {
              *(ushort *)(param_2 + 0x30) = local_16;
              *(undefined2 *)(param_2 + 0x32) = *(undefined2 *)(local_24 + 8);
              break;
            }
            local_28 = FUN_600bfe2c(local_24);
            if (*(short *)(param_2 + 0x3a) == 0) {
              if ((int)local_26 < (int)(uint)local_28) {
                if (0xff < local_28) {
                  FUN_600bf5a4(param_2,param_3,6,0);
                  return;
                }
                local_14 = (undefined1 *)FUN_600bfeec(local_14,local_24,local_26,param_2 + 0x3a);
                *(ushort *)(param_2 + 0x30) = local_16;
                *(undefined2 *)(param_2 + 0x32) = *(undefined2 *)(local_24 + 8);
                break;
              }
              local_14 = (undefined1 *)FUN_600bf3b4(local_14,local_24);
            }
            else {
              local_14 = (undefined1 *)FUN_600bfeec(local_14,local_24,local_26,param_2 + 0x3a);
              if (local_28 != *(ushort *)(param_2 + 0x3a)) break;
              *(undefined2 *)(param_2 + 0x3a) = 0;
            }
            if (asStack_76[(uint)local_16 * 2] != asStack_76[(uint)local_16 * 2 + 1]) {
              asStack_76[(uint)local_16 * 2] = *(short *)(local_24 + 8) + 1;
              local_16 = local_16 - 1;
            }
          }
        }
        if (local_16 == local_78) {
          *(undefined2 *)(param_2 + 0x30) = 0;
        }
        local_c = (short)local_14 - (short)*(undefined4 *)(param_2 + 0x28);
        local_e = 0;
        if (local_17 == '\0') {
          sVar1 = FUN_600fa73c(local_20,auStack_bc);
          *(short *)(param_2 + 0x24) = sVar1 + 3;
          if (*(ushort *)(param_2 + 0x24) < 0x100) {
            local_e = 1;
            *(undefined1 *)(*(int *)(param_2 + 0x28) + 1) = 0x35;
            *(char *)(*(int *)(param_2 + 0x28) + 2) = (char)*(undefined2 *)(param_2 + 0x24) + -3;
            *(short *)(param_2 + 0x24) = *(short *)(param_2 + 0x24) + -1;
            local_c = local_c - 1;
          }
          else {
            **(undefined1 **)(param_2 + 0x28) = 0x36;
            *(char *)(*(int *)(param_2 + 0x28) + 1) = (char)(*(ushort *)(param_2 + 0x24) - 3 >> 8);
            *(char *)(*(int *)(param_2 + 0x28) + 2) = (char)*(undefined2 *)(param_2 + 0x24) + -3;
          }
        }
        local_2c = FUN_6006dcdc(3,DAT_600beb1c,0x1fa);
        if (local_2c != 0) {
          *(undefined2 *)(local_2c + 4) = 0xd;
          local_30 = (undefined1 *)(local_2c + 0x15);
          *local_30 = 5;
          *(char *)(local_2c + 0x16) = (char)((ushort)param_3 >> 8);
          local_34 = (undefined1 *)(local_2c + 0x18);
          *(char *)(local_2c + 0x17) = (char)param_3;
          *(char *)(local_2c + 0x1a) = (char)(local_c >> 8);
          local_14 = (undefined1 *)(local_2c + 0x1c);
          *(char *)(local_2c + 0x1b) = (char)local_c;
          thunk_EXT_FUN_0000b572(local_14,(uint)local_e + *(int *)(param_2 + 0x28),local_c);
          puVar4 = (undefined1 *)((uint)local_c + (int)local_14);
          *(ushort *)(param_2 + 0x2c) = local_c + *(short *)(param_2 + 0x2c);
          if (*(ushort *)(param_2 + 0x2c) < *(ushort *)(param_2 + 0x24)) {
            local_17 = '\x01';
            *puVar4 = 2;
            puVar4[1] = (char)((ushort)*(undefined2 *)(param_2 + 0x2c) >> 8);
            local_14 = puVar4 + 3;
            puVar4[2] = (char)*(undefined2 *)(param_2 + 0x2c);
          }
          else {
            local_14 = puVar4 + 1;
            *puVar4 = 0;
          }
          local_36 = ((short)local_14 - (short)local_34) + -2;
          puVar4 = local_34 + 1;
          *local_34 = (char)((ushort)local_36 >> 8);
          local_34 = local_34 + 2;
          *puVar4 = (char)local_36;
          *(short *)(local_2c + 2) = (short)local_14 - (short)local_30;
          FUN_600f7b26(*(undefined2 *)(param_2 + 0x22),local_2c);
        }
      }
    }
  }
  return;
}


