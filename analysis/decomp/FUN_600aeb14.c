// 600aeb14  FUN_600aeb14  size=550 bytes
// --- callers ---
//   600aee8c FUN_600aee8c
// --- callees ---
//   600ad228 FUN_600ad228
//   600f6b4a FUN_600f6b4a
//   600f6158 FUN_600f6158
//   600f6b96 FUN_600f6b96
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f6be6 FUN_600f6be6
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600aeb14(int param_1,byte param_2,undefined2 param_3,byte param_4,short param_5,
                 byte *param_6)

{
  int iVar1;
  undefined1 local_286;
  undefined1 local_285;
  undefined2 local_284;
  short local_282;
  short local_280;
  undefined1 auStack_27e [600];
  undefined1 local_26;
  undefined1 local_25;
  undefined2 local_22;
  int local_20;
  int local_1c;
  byte *local_18;
  char local_11;
  
  local_18 = param_6;
  thunk_EXT_FUN_0000b5ba(&local_284,0,0x260);
  if (param_4 == 0x16) {
    local_25 = 1;
    local_282 = (ushort)local_18[1] * 0x100 + (ushort)*local_18;
    local_18 = local_18 + 2;
    param_5 = param_5 + -2;
LAB_600aebaa:
    if (param_4 == 0xd2) {
      param_5 = param_5 + -0xc;
    }
  }
  else if (param_4 < 0x17) {
    if (param_4 != 0x12) goto LAB_600aec10;
  }
  else if (param_4 != 0x52) {
    if (param_4 != 0xd2) goto LAB_600aec10;
    goto LAB_600aebaa;
  }
  if ((param_4 == 0x12) || (param_4 == 0x16)) {
    local_26 = 1;
  }
  local_280 = param_5;
  local_284 = param_3;
  if ((param_5 != 0) && (local_18 != (byte *)0x0)) {
    thunk_EXT_FUN_0000b572(auStack_27e,local_18,param_5);
  }
LAB_600aec10:
  FUN_600f6b4a(param_1 + 0xd,*(undefined1 *)(param_1 + 0x13),&local_285,&local_286);
  local_11 = FUN_600ad228(*(undefined4 *)((uint)param_2 * 0x28 + DAT_600aed3c + 0xa84),param_4,
                          param_3,local_282,local_18,param_5,local_285,local_286);
  if (local_11 == '\0') {
    local_1c = FUN_600f6158(param_1,param_4,param_3);
    if (local_1c == 0) {
      local_11 = -0x7c;
    }
    else {
      iVar1 = (uint)param_2 * 0x28 + DAT_600aed3c;
      local_20 = iVar1 + 0xa84;
      local_22 = CONCAT11(*(undefined1 *)(param_1 + 0xfb),*(undefined1 *)(iVar1 + 0xaa8));
      FUN_600f6b96(local_22,local_1c,2,&local_284);
      local_11 = -0x78;
    }
  }
  if (((local_11 != -0x78) && (local_11 != -0x7c)) && ((param_4 == 0x16 || (param_4 == 0x12)))) {
    FUN_600f6be6(param_1,local_11,param_4,param_3,0);
  }
  return;
}


