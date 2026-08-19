// 600dfc30  FUN_600dfc30  size=38 bytes
// --- callers ---
//   60083080 remote_device_db__60083080
//   6006c340 remote_device_db__6006c340
// --- callees ---
//   600cc29c FUN_600cc29c


void FUN_600dfc30(int param_1,undefined4 param_2)

{
  undefined2 local_14;
  undefined2 uStack_12;
  undefined4 local_10;
  int iStack_c;
  
  iStack_c = *(int *)(param_1 + 0x10) * 0x9d;
  _local_14 = CONCAT22((short)((uint)param_2 >> 0x10),0xffff);
  local_10 = param_2;
  FUN_600cc29c(&local_14,param_2,iStack_c,&stack0xfffffff8,param_1);
  return;
}


