// 600ebcd4  FUN_600ebcd4  size=100 bytes
// --- callers ---
//   6008df70 FUN_6008df70
// --- callees ---
//   6008df14 FUN_6008df14
//   6013cee8 thunk_EXT_FUN_0000af90


void FUN_600ebcd4(int param_1,undefined4 param_2,code *param_3,int param_4)

{
  byte bVar1;
  int local_2c;
  undefined1 auStack_28 [16];
  
  thunk_EXT_FUN_0000af90(param_1,0,0x120);
  *(code **)(param_1 + 0x118) = param_3;
  thunk_EXT_FUN_0000af90(auStack_28,0,0x10);
  (*param_3)(auStack_28,auStack_28,param_2);
  FUN_6008df14(param_1 + 0x110,param_1 + 0x114,param_1,param_1 + 0x10,&local_2c,auStack_28);
  bVar1 = 0;
  if ((local_2c != 0) && (bVar1 = 0, param_4 != 0)) {
    bVar1 = 1;
  }
  *(byte *)(param_1 + 0x11c) = *(byte *)(param_1 + 0x11c) & 0xfe | bVar1;
  return;
}


