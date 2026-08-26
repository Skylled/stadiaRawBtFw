// 600ffd7a  FUN_600ffd7a  size=146 bytes
// --- callers ---
//   600c0ac4 FUN_600c0ac4
// --- callees ---
//   600ffd60 FUN_600ffd60
//   600c80fc FUN_600c80fc
//   600c7fc8 FUN_600c7fc8
//   600ffcfe FUN_600ffcfe


undefined4 FUN_600ffd7a(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 auStack_1c [19];
  byte local_9;
  
  if (*(char *)(param_3 + 0xf0) == '\0') {
    uVar1 = 0xff;
  }
  else {
    FUN_600ffcfe(auStack_1c,param_1,param_3);
    for (local_9 = 1; local_9 < *(byte *)(param_3 + 0xf0); local_9 = local_9 + 1) {
      FUN_600c80fc(auStack_1c);
      FUN_600ffd60(auStack_1c,(uint)local_9 * 0x10 + param_3);
    }
    FUN_600c7fc8(auStack_1c);
    FUN_600ffcfe(param_2,auStack_1c,(uint)local_9 * 0x10 + param_3);
    uVar1 = 0;
  }
  return uVar1;
}


