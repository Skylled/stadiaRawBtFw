// 6009e1b4  FUN_6009e1b4  size=288 bytes
// --- callers ---
//   6009e4d0 FUN_6009e4d0
// --- callees ---
//   6009dfd8 FUN_6009dfd8
//   600f147c FUN_600f147c


undefined1 FUN_6009e1b4(int param_1,undefined1 param_2,char param_3,byte *param_4,char param_5)

{
  undefined1 *puVar1;
  undefined1 auStack_29 [8];
  byte local_21;
  byte *local_20;
  byte local_19;
  int local_18;
  int local_14;
  int local_10;
  undefined1 local_9;
  
  local_9 = 1;
  local_10 = param_1 + 8;
  local_14 = DAT_6009e2d4;
  local_18 = DAT_6009e2d8;
  local_19 = *param_4;
  param_4 = param_4 + 1;
  if (local_19 < 0x20) {
    FUN_6009dfd8(local_10,local_19,param_4,param_3);
    local_21 = param_4[local_19];
    local_20 = param_4 + local_19 + 1;
    *(undefined1 *)(local_10 + 0x10) = 2;
    *(undefined1 *)(local_10 + 0x11) = param_2;
    *(byte *)(local_10 + 0xe) = local_21;
    if ((*(char *)(DAT_6009e2dc + 0x8dc) == '\x01') && ((param_3 == '\0' || (param_3 == '\x02')))) {
      if (param_5 != '\0') {
        *(undefined1 *)(param_1 + 0x2f) = 0;
      }
      if ((*(byte *)(DAT_6009e2dc + 0x8d0) & 0x40) == 0) {
        local_9 = 0;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x2f) = 1;
    }
    if (*(int *)(param_1 + 4) == *(int *)(local_14 + 0x44)) {
      *(byte *)(local_10 + 0xf) = *(byte *)(local_10 + 0xf) | 2;
    }
    else {
      *(undefined1 *)(local_10 + 0xf) = 2;
    }
    if (param_3 != '\x04') {
      *(char *)(local_10 + 0x12) = param_3;
    }
    if ((*(char *)(local_18 + 0x34) != '\0') &&
       (puVar1 = (undefined1 *)FUN_600f147c(local_18 + 0x35,1,auStack_29),
       puVar1 != (undefined1 *)0x0)) {
      *(undefined1 *)(local_10 + 0x13) = *puVar1;
    }
  }
  else {
    local_9 = 0;
  }
  return local_9;
}


