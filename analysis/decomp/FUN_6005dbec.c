// 6005dbec  FUN_6005dbec  size=184 bytes
// --- callers ---
//   6005dcc0 FUN_6005dcc0
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600cb598 key_value_store__600cb598
//   60101a64 FUN_60101a64
//   601010c8 FUN_601010c8
//   600cbb14 FUN_600cbb14
//   600ce31c FUN_600ce31c
//   600d4566 FUN_600d4566
//   600cc450 FUN_600cc450


void FUN_6005dbec(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  short *psVar1;
  undefined *puVar2;
  char local_84 [4];
  undefined1 auStack_80 [32];
  byte local_60;
  undefined1 local_5f;
  short local_5c [34];
  
  FUN_60101a64(param_3);
  thunk_EXT_FUN_0000b5ba(auStack_80,0,0x20);
  local_60 = 1;
  local_5f = 3;
  psVar1 = local_5c;
  local_5c[0] = 0;
  local_84[0] = FUN_601010c8(param_1,param_2,psVar1);
  if (local_84[0] == '\0') {
    if (local_5c[0] == 0x22) {
      local_84[0] = key_value_store__600cb598(param_1,param_2,auStack_80,0x22,0);
      goto LAB_6005dc5c;
    }
    local_84[0] = '\x03';
  }
  else {
LAB_6005dc5c:
    if (local_84[0] == '\0') {
      FUN_600d4566(param_3,PTR_s_state_6011edfe_0xf_6005dca8,local_60);
      puVar2 = PTR_s_<UNONWN>_6005dcb4;
      if (local_60 < 5) {
        puVar2 = *(undefined **)(DAT_6005dcb0 + (uint)local_60 * 4);
      }
      FUN_600cc450(param_3,PTR_s_state_str_6005dcac,puVar2);
      FUN_600d4566(param_3,PTR_s_retries_left_6005dcb8,local_5f);
      FUN_600ce31c(auStack_80,0x20,psVar1);
      puVar2 = PTR_s_fingerprint_6005dcbc;
      goto LAB_6005dc42;
    }
  }
  psVar1 = (short *)FUN_600cbb14(local_84);
  puVar2 = PTR_s_load_error_6005dca4;
LAB_6005dc42:
  FUN_600cc450(param_3,puVar2,psVar1);
  return;
}


