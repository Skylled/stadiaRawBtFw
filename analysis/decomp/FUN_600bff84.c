// 600bff84  FUN_600bff84  size=94 bytes
// --- callers ---
//   600fb848 FUN_600fb848
// --- callees ---


void FUN_600bff84(int param_1,undefined4 param_2)

{
  byte bVar1;
  byte local_9;
  
  if (*(char *)(param_1 + 0x26) == '\x01') {
    bVar1 = *(byte *)(param_1 + 0x1b5);
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x1b4);
  }
  local_9 = 0;
  while( true ) {
    if (3 < local_9) {
      return;
    }
    if (((int)(uint)bVar1 >> local_9 & 1U) != 0) break;
    local_9 = local_9 + 1;
  }
  (**(code **)(DAT_600bffe4 + (uint)local_9 * 4))(param_1,param_2);
  return;
}


