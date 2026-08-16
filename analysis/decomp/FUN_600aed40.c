// 600aed40  FUN_600aed40  size=326 bytes
// --- callers ---
//   600aee8c FUN_600aee8c
// --- callees ---
//   600ff9fe FUN_600ff9fe
//   600f5478 FUN_600f5478
//   6006dbac FUN_6006dbac
//   600f6be6 FUN_600f6be6
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f6b4a FUN_600f6b4a
//   6006ddd8 FUN_6006ddd8


void FUN_600aed40(int param_1,undefined4 *param_2,char param_3,undefined2 param_4,undefined4 param_5
                 ,byte *param_6)

{
  short local_24;
  undefined1 local_22;
  undefined1 local_21;
  int local_20;
  int local_1c;
  short local_16;
  short local_14;
  char local_11;
  
  local_16 = *(short *)(param_1 + 0x1a) + 0x15;
  local_1c = 0;
  local_14 = 0;
  local_24 = 0;
  local_1c = FUN_6006dbac(local_16,DAT_600aee88,0x48d);
  if (local_1c == 0) {
    local_11 = -0x80;
  }
  else {
    if (param_3 == '\f') {
      local_14 = (ushort)param_6[1] * 0x100 + (ushort)*param_6;
    }
    thunk_EXT_FUN_0000b5ba(local_1c,0,local_16);
    local_20 = local_1c + 0x16;
    *(char *)(local_1c + 0x15) = param_3 + '\x01';
    *(undefined2 *)(local_1c + 2) = 1;
    local_16 = *(short *)(param_1 + 0x1a) + -1;
    FUN_600f6b4a(param_1 + 0xd,*(undefined1 *)(param_1 + 0x13),&local_21,&local_22);
    local_11 = FUN_600f5478(param_1,*param_2,param_3,param_4,local_14,local_20,&local_24,local_16,
                            local_21,local_22,0);
    *(short *)(local_1c + 2) = local_24 + *(short *)(local_1c + 2);
  }
  if (local_11 == '\0') {
    FUN_600ff9fe(param_1,local_1c);
  }
  else {
    if (local_1c != 0) {
      FUN_6006ddd8(local_1c,DAT_600aee88,0x4b4);
    }
    if ((local_11 != -0x78) && (local_11 != -0x7c)) {
      FUN_600f6be6(param_1,local_11,param_3,param_4,0);
    }
  }
  return;
}


