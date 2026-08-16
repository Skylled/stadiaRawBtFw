// 60097f5c  FUN_60097f5c  size=564 bytes
// --- callers ---
//   600987a0 FUN_600987a0
//   600927d8 FUN_600927d8
// --- callees ---
//   600a1394 FUN_600a1394
//   6009759c FUN_6009759c
//   6013cf90 thunk_EXT_FUN_0000b5ba


char FUN_60097f5c(char param_1,undefined1 *param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  char cVar2;
  int iVar3;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b [15];
  int local_1c;
  char local_15;
  undefined1 *local_14;
  
  local_15 = '\x06';
  local_14 = &local_30;
  thunk_EXT_FUN_0000b5ba(&local_30,0,0x14);
  if (*(int *)(DAT_60098190 + 200) != 0) {
    return '\x02';
  }
  if (param_1 == '\0') {
    puVar1 = local_14 + 1;
    *local_14 = 1;
    local_14 = puVar1;
    *(uint *)(DAT_60098190 + 0xc0) = *(uint *)(DAT_60098190 + 0xc0) & 0xfffffffd;
    puVar1 = local_14 + 1;
    *local_14 = (char)*(undefined4 *)(DAT_60098190 + 0xc0);
    local_14 = puVar1;
    puVar1 = local_14 + 1;
    *local_14 = (char)((uint)*(undefined4 *)(DAT_60098190 + 0xc0) >> 8);
    local_14 = puVar1;
    puVar1 = local_14 + 1;
    *local_14 = (char)((uint)*(undefined4 *)(DAT_60098190 + 0xc0) >> 0x10);
    local_14 = puVar1;
    puVar1 = local_14 + 1;
    *local_14 = (char)((uint)*(undefined4 *)(DAT_60098190 + 0xc0) >> 0x18);
    local_14 = puVar1;
  }
  else {
    local_1c = FUN_6009759c(param_2);
    if (local_1c == 0) {
      return local_15;
    }
    if ((local_1c != 0) && (*(int *)(local_1c + 8) == 0)) {
      return local_15;
    }
    puVar1 = local_14 + 1;
    *local_14 = 5;
    local_14 = puVar1;
    puVar1 = local_14 + 1;
    *local_14 = 0;
    local_14 = puVar1;
    if (param_2 == (undefined1 *)0x0) {
      for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
        puVar1 = local_14 + 1;
        *local_14 = *(undefined1 *)(DAT_60098194 + (5 - iVar3));
        local_14 = puVar1;
      }
      puVar1 = local_14 + 1;
      *local_14 = 2;
      local_14 = puVar1;
    }
    else {
      for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
        puVar1 = local_14 + 1;
        *local_14 = param_2[6 - iVar3];
        local_14 = puVar1;
      }
      puVar1 = local_14 + 1;
      *local_14 = *param_2;
      local_14 = puVar1;
    }
    puVar1 = local_14 + 1;
    *local_14 = (char)*(undefined4 *)(local_1c + 8);
    local_14 = puVar1;
    puVar1 = local_14 + 1;
    *local_14 = (char)((uint)*(undefined4 *)(local_1c + 8) >> 8);
    local_14 = puVar1;
    puVar1 = local_14 + 1;
    *local_14 = (char)((uint)*(undefined4 *)(local_1c + 8) >> 0x10);
    local_14 = puVar1;
    puVar1 = local_14 + 1;
    *local_14 = (char)((uint)*(undefined4 *)(local_1c + 8) >> 0x18);
    local_14 = puVar1;
    puVar1 = local_14 + 1;
    *local_14 = 0;
    local_14 = puVar1;
    local_15 = FUN_600a1394(0xfce9,0xe,&local_30,DAT_60098198);
    if (local_15 == '\x03') {
      return '\x03';
    }
    local_30 = 1;
    *(uint *)(DAT_60098190 + 0xc0) = *(uint *)(DAT_60098190 + 0xc0) | 2;
    local_2f = (undefined1)*(undefined4 *)(DAT_60098190 + 0xc0);
    local_2e = (undefined1)((uint)*(undefined4 *)(DAT_60098190 + 0xc0) >> 8);
    local_2d = (undefined1)((uint)*(undefined4 *)(DAT_60098190 + 0xc0) >> 0x10);
    local_14 = local_2b;
    local_2c = (undefined1)((uint)*(undefined4 *)(DAT_60098190 + 0xc0) >> 0x18);
  }
  cVar2 = FUN_600a1394(0xfce9,5,&local_30,DAT_60098198);
  if (cVar2 == '\x01') {
    *(undefined1 *)(DAT_60098190 + 1) = 0x11;
    *(undefined4 *)(DAT_60098190 + 200) = param_3;
  }
  return cVar2;
}


