// 600f633e  FUN_600f633e  size=210 bytes
// --- callers ---
//   600f6516 FUN_600f6516
// --- callees ---
//   600f6b96 FUN_600f6b96
//   600f6158 FUN_600f6158
//   600f6e04 FUN_600f6e04
//   600f6e96 FUN_600f6e96
//   600f6be6 FUN_600f6be6


void FUN_600f633e(int param_1,undefined1 param_2,undefined4 param_3,byte *param_4)

{
  int iVar1;
  byte local_19;
  undefined2 local_18;
  char local_15;
  undefined4 local_14;
  byte *local_10;
  byte local_9;
  
  local_9 = 0;
  local_14 = 0;
  local_10 = param_4 + 1;
  local_19 = *param_4 & 1;
  iVar1 = FUN_600f6e96(param_1);
  if (iVar1 == 0) {
    local_14 = FUN_600f6158(param_1,param_2,0);
    FUN_600f6e04(param_1);
    for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
      if (*(char *)((uint)local_9 + param_1 + 0x8c) != '\0') {
        local_15 = local_9 + 1;
        local_18 = CONCAT11(*(undefined1 *)(param_1 + 0xfb),local_15);
        FUN_600f6b96(local_18,local_14,3,&local_19);
        *(undefined1 *)((uint)local_9 + param_1 + 0x8c) = 0;
      }
    }
  }
  else {
    FUN_600f6be6(param_1,0x85,0x18,0,0);
  }
  return;
}


