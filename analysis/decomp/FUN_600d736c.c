// 600d736c  FUN_600d736c  size=34 bytes
// --- callers ---
//   600764fc input_task__600764fc
//   60078b4c get_device_data__60078b4c
// --- callees ---
//   600666f0 keys__600666f0


undefined4 FUN_600d736c(undefined4 param_1,undefined1 *param_2,undefined4 param_3,uint param_4)

{
  undefined1 *local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  uint local_c;
  
  *param_2 = 0;
  local_10 = 0;
  local_c = param_4 & 0xffff0000;
  local_18 = param_2;
  uStack_14 = param_3;
  keys__600666f0(param_1,&local_18);
  return local_10;
}


