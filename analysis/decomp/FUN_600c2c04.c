// 600c2c04  FUN_600c2c04  size=244 bytes
// --- callers ---
// --- callees ---
//   600efcc6 FUN_600efcc6
//   600f1b34 FUN_600f1b34
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f1ad4 FUN_600f1ad4
//   600f1700 FUN_600f1700


void FUN_600c2c04(int param_1)

{
  undefined1 auStack_128 [6];
  undefined1 auStack_122 [248];
  undefined1 local_2a;
  undefined1 local_17;
  undefined1 local_16;
  int local_10;
  char local_9;
  
  if (*(char *)(param_1 + 0xe) == '\0') {
    local_9 = FUN_600f1b34(param_1 + 8,0,0,0);
  }
  else {
    local_9 = FUN_600f1ad4(param_1 + 8,*(undefined1 *)(param_1 + 0xe),0,0,0);
  }
  if ((*(int *)(DAT_600c2cf8 + 0xe8) != 0) && (local_9 != '\x01')) {
    local_10 = FUN_600f1700(param_1 + 8);
    if (local_10 == 0) {
      local_10 = DAT_600c2cfc;
    }
    thunk_EXT_FUN_0000b5ba(auStack_128,0,0x118);
    FUN_600efcc6(auStack_128,param_1 + 8);
    thunk_EXT_FUN_0000b572(auStack_122,local_10,0xf8);
    local_2a = 0;
    local_16 = 1;
    if (local_9 == '\0') {
      local_17 = 1;
    }
    (**(code **)(DAT_600c2cf8 + 0xe8))(3,auStack_128);
  }
  return;
}


