// 60100c14  FUN_60100c14  size=52 bytes
// --- callers ---
//   600cb460 key_value_store__600cb460
//   600cb598 key_value_store__600cb598
//   60100c48 FUN_60100c48
// --- callees ---
//   600cc29c FUN_600cc29c


void FUN_60100c14(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 ushort param_5)

{
  undefined2 local_1c [2];
  undefined4 local_18;
  uint local_14;
  
  local_1c[0] = 0xffff;
  local_18 = param_2;
  local_14 = param_3;
  FUN_600cc29c(local_1c,param_2,param_3);
  local_14 = (uint)param_5;
  local_18 = param_4;
  FUN_600cc29c(local_1c,param_4,local_14);
  return;
}


