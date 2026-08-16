// 600d4550  FUN_600d4550  size=16 bytes
// --- callers ---
//   60074cc8 FUN_60074cc8
//   600df62c FUN_600df62c
//   60081234 advertiser__60081234
//   6005db20 FUN_6005db20
//   60080fb8 FUN_60080fb8
//   600810bc types__600810bc
//   600d7440 FUN_600d7440
//   60075088 audio_states__60075088
//   60074c2c audio_states__60074c2c
//   60081ab4 gatt_server__60081ab4
//   6007598c FUN_6007598c
//   6007991c http_flash_writer__6007991c
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a


void FUN_600d4550(int *param_1)

{
  if ((int *)*param_1 != param_1 + 2) {
    thunk_EXT_FUN_0000b52a();
    return;
  }
  return;
}


