// 600d81f8  FUN_600d81f8  size=46 bytes
// --- callers ---
//   6006816c accessory_detect_ts3a227e__6006816c
//   600d8274 FUN_600d8274
//   600d8266 FUN_600d8266
//   600d8226 FUN_600d8226
//   600d82d8 FUN_600d82d8
// --- callees ---
//   6013d0b0 thunk_EXT_FUN_00001ea4


void FUN_600d81f8(undefined4 *param_1,undefined1 param_2,undefined1 *param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 local_18 [4];
  undefined1 local_14 [8];
  
  local_18[0] = param_2;
  cVar1 = thunk_EXT_FUN_00001ea4
                    (*param_1,*(undefined1 *)(param_1 + 1),local_18,1,local_14,1,param_4);
  if (cVar1 == '\0') {
    *param_3 = local_14[0];
  }
  return;
}


