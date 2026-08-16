// 600ac734  FUN_600ac734  size=614 bytes
// --- callers ---
//   600acf50 FUN_600acf50
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f6ad6 FUN_600f6ad6
//   600ffada FUN_600ffada
//   600f4322 FUN_600f4322
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600ac734(int param_1,char param_2,short param_3,byte *param_4)

{
  int iVar1;
  undefined1 auStack_294 [6];
  short local_28e;
  short local_28c;
  undefined1 *local_288;
  undefined1 auStack_284 [2];
  short local_282;
  short local_27e;
  undefined1 auStack_27b [603];
  undefined2 local_20;
  undefined1 local_1e;
  char local_1d;
  byte *local_1c;
  byte local_15;
  int local_14;
  
  local_1c = param_4;
  thunk_EXT_FUN_0000b5ba(auStack_284,0,0x262);
  if (param_2 == '\x1b') {
    local_1d = '\x06';
  }
  else {
    local_1d = '\a';
  }
  local_282 = (ushort)local_1c[1] * 0x100 + (ushort)*local_1c;
  local_1c = local_1c + 2;
  local_27e = param_3 + -2;
  thunk_EXT_FUN_0000b572(auStack_27b,local_1c,local_27e);
  if (local_282 == 0) {
    if (param_2 == '\x1d') {
      FUN_600ffada(param_1,0,0x1e,0);
    }
  }
  else {
    if (*(int *)(DAT_600ac99c + 0xd4) != 0) {
      local_288 = auStack_27b;
      local_28c = local_282;
      local_28e = local_27e;
      thunk_EXT_FUN_0000b572(auStack_294,param_1 + 0xd,6);
      iVar1 = (**(code **)(DAT_600ac99c + 0xd4))(0xc,auStack_294);
      if (iVar1 == 1) {
        return;
      }
    }
    if (local_1d == '\a') {
      *(undefined1 *)(param_1 + 0x96) = 0;
    }
    local_14 = DAT_600ac9a0;
    for (local_15 = 0; local_15 < 10; local_15 = local_15 + 1) {
      if (((*(char *)(local_14 + 0x2d) != '\0') && (*(int *)(local_14 + 0x18) != 0)) &&
         (local_1d == '\a')) {
        *(char *)(param_1 + 0x96) = *(char *)(param_1 + 0x96) + '\x01';
      }
      local_14 = local_14 + 0x30;
    }
    if (local_1d == '\a') {
      if (*(char *)(param_1 + 0x96) == '\0') {
        FUN_600ffada(param_1,0,0x1e,0);
      }
      else {
        FUN_600f6ad6(param_1);
      }
    }
    local_1e = FUN_600f4322(param_1);
    local_14 = DAT_600ac9a0;
    for (local_15 = 0; local_15 < 10; local_15 = local_15 + 1) {
      if ((*(char *)(local_14 + 0x2d) != '\0') && (*(int *)(local_14 + 0x18) != 0)) {
        local_20 = CONCAT11(*(undefined1 *)(param_1 + 0xfb),*(undefined1 *)(local_14 + 0x2c));
        (**(code **)(local_14 + 0x18))(local_20,local_1d,local_1e,auStack_284);
      }
      local_14 = local_14 + 0x30;
    }
  }
  return;
}


