// 600ac9a4  FUN_600ac9a4  size=1076 bytes
// --- callers ---
//   600acf50 FUN_600acf50
// --- callees ---
//   6006dbac FUN_6006dbac
//   600f43c0 FUN_600f43c0
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f68f0 FUN_600f68f0
//   600ac524 FUN_600ac524
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600af9fc FUN_600af9fc
//   600b00b4 FUN_600b00b4


void FUN_600ac9a4(int param_1,int *param_2,char param_3,ushort param_4,byte *param_5)

{
  short sVar1;
  int iVar2;
  short sVar3;
  byte *pbVar4;
  ushort local_44;
  byte *local_38;
  undefined2 local_34;
  short local_32;
  short local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  byte local_15;
  short local_14;
  byte local_11;
  
  local_11 = 2;
  local_14 = 0;
  if (((param_2[1] != 0) && (*(int *)(param_2[1] + 0x1c) != 0)) ||
     (*(char *)((int)param_2 + 0x31) != '\x01')) {
    local_15 = *param_5;
    local_38 = param_5 + 1;
    if (((int)(*(ushort *)(param_1 + 0x1a) - 2) < (int)(uint)local_15) ||
       ((int)(param_4 - 1) < (int)(uint)local_15)) {
      FUN_600b00b4(param_2,0x85,0);
    }
    else {
      if (param_3 == '\x11') {
        local_11 = 4;
      }
      local_15 = local_15 - local_11;
      local_44 = param_4 - 1;
      while ((ushort)((ushort)local_15 + (ushort)local_11) <= local_44) {
        local_14 = (ushort)local_38[1] * 0x100 + (ushort)*local_38;
        local_38 = local_38 + 2;
        if (local_14 == 0) {
          FUN_600b00b4(param_2,1,0);
          return;
        }
        thunk_EXT_FUN_0000b5ba(&local_34,0,0x1c);
        if (((*(char *)((int)param_2 + 0x31) == '\x01') &&
            (*(char *)((int)param_2 + 0x32) == '\x01')) && (param_3 == '\x11')) {
          local_20 = CONCAT22(local_20._2_2_,local_14);
          sVar3 = (ushort)local_38[1] * 0x100 + (ushort)*local_38;
          local_38 = local_38 + 2;
          if (sVar3 == 0) {
            local_14 = sVar3;
            FUN_600b00b4(param_2,1,0);
            return;
          }
          local_20 = CONCAT22(sVar3,local_14);
          local_14 = sVar3;
          iVar2 = FUN_600af9fc(&local_34,local_15,&local_38);
          if (iVar2 == 0) break;
LAB_600acd4e:
          local_44 = local_44 - ((ushort)local_11 + (ushort)local_15);
          if ((*(char *)((int)param_2 + 0x31) == '\x01') && (*(int *)(param_2[1] + 0x1c) != 0)) {
            (**(code **)(param_2[1] + 0x1c))
                      ((short)param_2[9],*(undefined1 *)((int)param_2 + 0x32),&local_34);
          }
        }
        else {
          if ((*(char *)((int)param_2 + 0x31) == '\x01') &&
             (*(char *)((int)param_2 + 0x32) == '\x03')) {
            sVar3 = (ushort)local_38[1] * 0x100 + (ushort)*local_38;
            local_20 = CONCAT22(sVar3,local_14);
            sVar1 = (ushort)local_38[3] * 0x100 + (ushort)local_38[2];
            local_1c = CONCAT22(local_1c._2_2_,sVar1);
            pbVar4 = local_38 + 4;
            if ((sVar3 == 0) || (sVar1 == 0)) {
              local_38 = pbVar4;
              FUN_600b00b4(param_2,1,0);
              return;
            }
            if (local_15 != 6) {
              if (local_15 == 4) {
                *(short *)(param_2 + 10) = sVar3;
                *(undefined1 *)(param_2 + 0x16) = 1;
                *(short *)(param_2 + 0xe) = local_14 + 1;
                local_38 = pbVar4;
                thunk_EXT_FUN_0000b572(param_2 + 0xf,&local_34,0x1c);
                *(byte *)((int)param_2 + 0x32) = *(byte *)((int)param_2 + 0x32) | 0x90;
                FUN_600f43c0(param_2,0);
                return;
              }
              local_38 = pbVar4;
              FUN_600b00b4(param_2,4,pbVar4);
              return;
            }
            local_30 = (ushort)local_38[5] * 0x100 + (ushort)*pbVar4;
            local_38 = local_38 + 6;
            local_34 = 2;
            goto LAB_600acd4e;
          }
          if ((*(char *)((int)param_2 + 0x31) == '\x02') &&
             (*(char *)((int)param_2 + 0x32) == '\x01')) {
            *(ushort *)(param_2 + 0xb) = local_44 - 2;
            *(short *)(param_2 + 10) = local_14;
            if ((uint)*(ushort *)(param_2 + 0xb) != *(ushort *)(*param_2 + 0x1a) - 4) {
              FUN_600b00b4(param_2,0,local_38);
              return;
            }
            *(undefined1 *)((int)param_2 + 0x32) = 2;
            if (param_2[3] == 0) {
              iVar2 = FUN_6006dbac(600,DAT_600acdd8,0x341);
              param_2[3] = iVar2;
            }
            if ((param_2[3] != 0) && (*(ushort *)(param_2 + 0xb) < 0x259)) {
              thunk_EXT_FUN_0000b572(param_2[3],local_38,(short)param_2[0xb]);
              FUN_600f43c0(param_2,(short)param_2[0xb]);
              return;
            }
            FUN_600b00b4(param_2,0x81,local_38);
            return;
          }
          local_30 = local_14;
          local_34 = CONCAT11(local_34._1_1_,*local_38);
          local_32 = (ushort)local_38[2] * 0x100 + (ushort)local_38[1];
          local_38 = local_38 + 3;
          if (local_32 == 0) {
            FUN_600b00b4(param_2,1,0);
            return;
          }
          iVar2 = FUN_600af9fc(&local_2c,local_15 - 3,&local_38);
          if (iVar2 == 0) {
            FUN_600b00b4(param_2,0,0);
            return;
          }
          iVar2 = FUN_600f68f0(local_2c,uStack_28,uStack_24,local_20,local_1c,param_2[4],param_2[5],
                               param_2[6],param_2[7],param_2[8]);
          if (iVar2 != 0) {
            if (*(char *)((int)param_2 + 0x31) == '\x02') {
              *(short *)(param_2 + 10) = local_32;
              *(byte *)((int)param_2 + 0x32) = *(byte *)((int)param_2 + 0x32) | 0x80;
              FUN_600f43c0(param_2,0);
              return;
            }
            goto LAB_600acd4e;
          }
          local_44 = (local_44 - local_15) - 2;
        }
      }
      if (local_14 == 0) {
        sVar3 = 0;
      }
      else {
        sVar3 = local_14 + 1;
      }
      *(short *)(param_2 + 10) = sVar3;
      if (*(char *)((int)param_2 + 0x31) == '\x01') {
        FUN_600ac524(param_2);
      }
      else {
        FUN_600f43c0(param_2,0);
      }
    }
  }
  return;
}


