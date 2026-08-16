// 600a2ab0  FUN_600a2ab0  size=944 bytes
// --- callers ---
//   600f2120 FUN_600f2120
//   600f213c FUN_600f213c
// --- callees ---
//   6006e154 FUN_6006e154
//   600a2640 FUN_600a2640
//   600a26ec FUN_600a26ec
//   600a2740 FUN_600a2740
//   600b1ef8 FUN_600b1ef8
//   6009e70c FUN_6009e70c


void FUN_600a2ab0(byte *param_1,char param_2)

{
  undefined4 uVar1;
  byte *pbVar2;
  int iVar3;
  byte *local_44;
  undefined1 local_3c;
  undefined1 local_3b;
  byte local_3a [7];
  byte local_33 [4];
  byte local_2f;
  ushort local_2e;
  byte local_2b;
  byte local_2a;
  byte local_29;
  code *local_28;
  int local_24;
  byte local_20;
  byte local_1f;
  char local_1e;
  char local_1d;
  ushort *local_1c;
  undefined4 *local_18;
  byte local_11;
  
  local_1c = (ushort *)0x0;
  local_1d = '\x01';
  local_24 = DAT_600a2d78;
  local_28 = *(code **)(DAT_600a2d78 + 0x38);
  local_1f = 0;
  local_20 = 0;
  if ((*(byte *)(DAT_600a2d78 + 0x61e) & 0xb) != 0) {
    local_2b = *param_1;
    local_44 = param_1 + 1;
    for (local_11 = 0; local_11 < local_2b; local_11 = local_11 + 1) {
      local_1e = '\0';
      pbVar2 = local_33;
      for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
        *pbVar2 = *local_44;
        pbVar2 = pbVar2 + -1;
        local_44 = local_44 + 1;
      }
      local_29 = *local_44;
      local_2a = local_44[1];
      pbVar2 = local_44 + 2;
      if (param_2 == '\0') {
        local_1f = local_44[2];
        pbVar2 = local_44 + 3;
      }
      local_44 = pbVar2;
      pbVar2 = local_3a;
      for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
        *pbVar2 = *local_44;
        pbVar2 = pbVar2 + -1;
        local_44 = local_44 + 1;
      }
      local_2e = (ushort)local_44[1] * 0x100 + (ushort)*local_44;
      pbVar2 = local_44 + 2;
      if (param_2 != '\0') {
        local_20 = local_44[2];
        pbVar2 = local_44 + 3;
      }
      local_44 = pbVar2;
      local_18 = (undefined4 *)FUN_600a26ec(local_3a + 2);
      if ((*(char *)(local_24 + 0x60a) != '\0') &&
         (*(byte *)(local_24 + 0x60a) <= *(byte *)(local_24 + 0x614))) {
        if (local_18 == (undefined4 *)0x0) {
          return;
        }
        if ((local_18 != (undefined4 *)0x0) && ((*(byte *)((int)local_18 + 0x17) & 1) != 0)) {
          return;
        }
      }
      iVar3 = FUN_600a2640(local_3a + 2);
      if (iVar3 == 0) {
LAB_600a2c70:
        if ((*(int *)(DAT_600a2d7c + 0x1114) == 0) ||
           (iVar3 = (**(code **)(DAT_600a2d7c + 0x1114))(local_3a + 2,&local_3c), iVar3 != 0)) {
          if (local_18 == (undefined4 *)0x0) {
            local_18 = (undefined4 *)FUN_600a2740(local_3a + 2);
            local_1d = '\x01';
          }
          else if ((local_18[1] == *(int *)(local_24 + 0x44)) &&
                  ((*(byte *)((int)local_18 + 0x17) & 1) != 0)) {
            local_1d = '\0';
          }
          if (param_2 == '\0') {
            *(undefined1 *)((int)local_18 + 0x16) = 0x7f;
          }
          else {
            *(byte *)((int)local_18 + 0x16) = local_20;
          }
          if (local_1d == '\x01') {
            local_1c = (ushort *)(local_18 + 2);
            *(byte *)((int)local_18 + 0x13) = local_29;
            *(byte *)(local_18 + 5) = local_2a;
            *(byte *)((int)local_18 + 0x15) = local_1f;
            *(undefined1 *)(local_18 + 4) = local_3c;
            *(undefined1 *)((int)local_18 + 0x11) = local_3b;
            *(byte *)((int)local_18 + 0x12) = local_3a[0];
            *local_1c = ~((ushort)~(ushort)(((uint)local_2e << 0x11) >> 0x10) >> 1);
            uVar1 = FUN_6006e154();
            *local_18 = uVar1;
            if (local_18[1] != *(int *)(local_24 + 0x44)) {
              *(char *)(local_24 + 0x614) = *(char *)(local_24 + 0x614) + '\x01';
            }
            *(undefined1 *)(local_1c + 8) = 1;
            if (local_18[1] == *(int *)(local_24 + 0x44)) {
              *(byte *)((int)local_1c + 0xf) = *(byte *)((int)local_1c + 0xf) | 1;
            }
            else {
              *(undefined1 *)((int)local_1c + 0xf) = 1;
              *(undefined1 *)((int)local_18 + 0x2f) = 0;
            }
            local_18[1] = *(undefined4 *)(local_24 + 0x44);
            if (((((*(byte *)(local_24 + 0x61e) & 8) == 0) && (*(char *)(local_24 + 0x60a) != '\0'))
                && (*(char *)(local_24 + 0x614) == *(char *)(local_24 + 0x60a))) &&
               ((((((*(byte *)(local_24 + 0x608) & 0x30) != 0 &&
                   (*(char *)((int)local_1c + 0xf) == '\x03')) &&
                  (*(char *)((int)local_18 + 0x2f) != '\0')) ||
                 ((*(byte *)(local_24 + 0x608) & 0x30) == 0)) &&
                (FUN_600b1ef8(), (*(byte *)(local_24 + 0x608) & 0x30) != 0)))) {
              FUN_6009e70c();
            }
            *(undefined1 *)(local_18 + 7) = 0;
          }
          if ((local_1d != '\0') || (local_1e != '\0')) {
            if (local_28 != (code *)0x0) {
              (*local_28)(local_1c,0);
            }
            if (*(int *)(local_24 + 0x40) != 0) {
              (**(code **)(local_24 + 0x40))(local_18 + 2,1);
            }
          }
        }
      }
      else {
        local_2f = local_20;
        if ((((*(char *)(local_24 + 0x60b) != '\0') && (local_20 != 0)) &&
            (local_18 != (undefined4 *)0x0)) &&
           (((*(char *)((int)local_18 + 0x16) < (char)local_20 ||
             (*(char *)((int)local_18 + 0x16) == '\0')) ||
            ((*(byte *)((int)local_18 + 0x17) & 1) != 0)))) {
          local_1c = (ushort *)(local_18 + 2);
          *(byte *)((int)local_18 + 0x16) = local_20;
          local_1e = '\x01';
          goto LAB_600a2c70;
        }
        if ((param_2 == '\x02') && (local_18 != (undefined4 *)0x0)) {
          local_1c = (ushort *)(local_18 + 2);
          local_1e = '\x01';
          goto LAB_600a2c70;
        }
      }
    }
  }
  return;
}


