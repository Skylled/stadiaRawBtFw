// 60097b20  FUN_60097b20  size=668 bytes
// --- callers ---
//   60097dc8 FUN_60097dc8
//   6009819c FUN_6009819c
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600a1394 FUN_600a1394
//   6009759c FUN_6009759c
//   6013d3a0 thunk_EXT_FUN_0000b572


char FUN_60097b20(char param_1,char param_2,int *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 local_48;
  char local_47;
  undefined1 local_46 [40];
  char local_1e;
  undefined1 local_1d;
  int *local_1c;
  char local_15;
  undefined1 *local_14;
  
  local_14 = &local_48;
  local_15 = '\t';
  local_1e = '\x05';
  thunk_EXT_FUN_0000b5ba(&local_48,0,0x2a);
  local_1c = param_3;
  if (param_2 == '\x02') {
    local_1d = 7;
    if (param_3 == (int *)0x0) {
      local_1c = (int *)0x0;
    }
  }
  else {
    local_1d = 8;
    if (param_3 == (int *)0x0) {
      local_1c = (int *)0x0;
    }
  }
  if ((local_1c != (int *)0x0) || (param_1 == '\x02')) {
    if ((param_1 == '\0') && ((*local_1c != 0 && (iVar2 = FUN_6009759c(*local_1c), iVar2 == 0)))) {
      puVar1 = local_14 + 1;
      *local_14 = 6;
      local_14 = puVar1;
      puVar1 = local_14 + 1;
      *local_14 = 0;
      local_14 = puVar1;
      for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
        puVar1 = local_14 + 1;
        *local_14 = *(undefined1 *)((*local_1c - iVar2) + 6);
        local_14 = puVar1;
      }
      puVar1 = local_14 + 1;
      *local_14 = *(undefined1 *)*local_1c;
      local_14 = puVar1;
      local_1e = FUN_600a1394(0xfce9,9,&local_48,DAT_60097dbc);
      if (local_1e == '\x03') {
        return '\x03';
      }
    }
    local_48 = local_1d;
    local_14 = local_46;
    if ((local_1c == (int *)0x0) || (*local_1c == 0)) {
      for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
        puVar1 = local_14 + 1;
        *local_14 = *(undefined1 *)(DAT_60097dc0 + (5 - iVar2));
        local_14 = puVar1;
      }
      puVar1 = local_14 + 1;
      *local_14 = 2;
      local_14 = puVar1;
    }
    else {
      for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
        puVar1 = local_14 + 1;
        *local_14 = *(undefined1 *)((*local_1c - iVar2) + 6);
        local_14 = puVar1;
      }
      puVar1 = local_14 + 1;
      *local_14 = *(undefined1 *)*local_1c;
      local_14 = puVar1;
    }
    if ((param_1 == '\0') || (param_1 == '\x01')) {
      puVar1 = local_14 + 1;
      *local_14 = (char)local_1c[6];
      local_14 = puVar1;
      local_15 = local_15 + '\x01';
      if ((short)local_1c[1] == 2) {
        puVar1 = local_14 + 1;
        *local_14 = (char)(short)local_1c[2];
        local_14 = puVar1;
        puVar1 = local_14 + 1;
        *local_14 = (char)((ushort)(short)local_1c[2] >> 8);
        local_14 = puVar1;
        local_15 = local_15 + '\x02';
      }
      else if ((short)local_1c[1] == 4) {
        puVar1 = local_14 + 1;
        *local_14 = (char)local_1c[2];
        local_14 = puVar1;
        puVar1 = local_14 + 1;
        *local_14 = (char)((uint)local_1c[2] >> 8);
        local_14 = puVar1;
        puVar1 = local_14 + 1;
        *local_14 = (char)((uint)local_1c[2] >> 0x10);
        local_14 = puVar1;
        puVar1 = local_14 + 1;
        *local_14 = (char)((uint)local_1c[2] >> 0x18);
        local_14 = puVar1;
        local_15 = local_15 + '\x04';
      }
      else {
        if ((short)local_1c[1] != 0x10) {
          return '\x05';
        }
        for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
          puVar1 = local_14 + 1;
          *local_14 = *(undefined1 *)((int)local_1c + iVar2 + 8);
          local_14 = puVar1;
        }
        local_15 = local_15 + '\x10';
      }
    }
    local_47 = param_1;
    local_1e = FUN_600a1394(0xfce9,local_15,&local_48,DAT_60097dbc);
    if (local_1e != '\x03') {
      if ((local_1c == (int *)0x0) || (*local_1c == 0)) {
        thunk_EXT_FUN_0000b5ba(DAT_60097dc4,0,7);
      }
      else {
        thunk_EXT_FUN_0000b572(DAT_60097dc4,*local_1c,7);
      }
    }
  }
  return local_1e;
}


