// 6009b230  FUN_6009b230  size=92 bytes
// --- callers ---
// --- callees ---


undefined1 FUN_6009b230(int param_1,int param_2)

{
  undefined1 local_9;
  
  local_9 = 0;
  if (*(int *)(DAT_6009b28c + 0x1138) != 0) {
    local_9 = (**(code **)(DAT_6009b28c + 0x1138))(1,param_1 + 0x10,param_2);
  }
  *(byte *)(param_2 + 4) = *(byte *)(param_2 + 4) & 7;
  *(byte *)(param_2 + 5) = *(byte *)(param_2 + 5) & 7;
  return local_9;
}


