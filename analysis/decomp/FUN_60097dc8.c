// 60097dc8  FUN_60097dc8  size=390 bytes
// --- callers ---
//   6009819c FUN_6009819c
// --- callees ---
//   60097904 FUN_60097904
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600977fc FUN_600977fc
//   600efe4c FUN_600efe4c
//   600a1394 FUN_600a1394
//   6009759c FUN_6009759c
//   60097b20 FUN_60097b20
//   6013cf90 thunk_EXT_FUN_0000b5ba


char FUN_60097dc8(char param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 local_34 [20];
  int local_20;
  char local_19;
  undefined1 *local_18;
  undefined1 *local_14;
  
  if (param_2 == (undefined1 *)0x0) {
    param_2 = (undefined1 *)0x0;
  }
  local_19 = '\x06';
  if (param_1 == '\x02') {
    local_14 = local_34;
    local_18 = param_2;
    thunk_EXT_FUN_0000b5ba(local_34,0,0x14);
    local_20 = FUN_6009759c(local_18);
    if ((local_20 != 0) &&
       (((local_18 == (undefined1 *)0x0 || (local_20 == 0)) || (*(int *)(local_20 + 8) != 0)))) {
      if (local_18 == (undefined1 *)0x0) {
        FUN_600977fc(2,0,5);
        FUN_60097904(2,0);
        FUN_600efe4c(2,0);
        FUN_60097b20(2,2,0);
        FUN_60097b20(2,8,0);
      }
      puVar1 = local_14 + 1;
      *local_14 = 5;
      local_14 = puVar1;
      puVar1 = local_14 + 1;
      *local_14 = 2;
      local_14 = puVar1;
      if (local_18 == (undefined1 *)0x0) {
        for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
          puVar1 = local_14 + 1;
          *local_14 = *(undefined1 *)(DAT_60097f50 + (5 - iVar2));
          local_14 = puVar1;
        }
        puVar1 = local_14 + 1;
        *local_14 = 2;
        local_14 = puVar1;
      }
      else {
        for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
          puVar1 = local_14 + 1;
          *local_14 = local_18[6 - iVar2];
          local_14 = puVar1;
        }
        puVar1 = local_14 + 1;
        *local_14 = *local_18;
        local_14 = puVar1;
      }
      puVar1 = local_14 + 1;
      *local_14 = 0;
      local_14 = puVar1;
      puVar1 = local_14 + 1;
      *local_14 = 0;
      local_14 = puVar1;
      puVar1 = local_14 + 1;
      *local_14 = 0;
      local_14 = puVar1;
      puVar1 = local_14 + 1;
      *local_14 = 0;
      local_14 = puVar1;
      puVar1 = local_14 + 1;
      *local_14 = 0;
      local_14 = puVar1;
      local_19 = FUN_600a1394(0xfce9,0xe,local_34,DAT_60097f54);
      if (local_19 != '\x03') {
        if (local_20 != 0) {
          *(undefined4 *)(local_20 + 8) = 0;
        }
        if (local_18 == (undefined1 *)0x0) {
          thunk_EXT_FUN_0000b5ba(DAT_60097f58,0,7);
        }
        else {
          thunk_EXT_FUN_0000b572(DAT_60097f58,local_18,7);
        }
      }
    }
  }
  else {
    local_19 = '\x05';
  }
  return local_19;
}


