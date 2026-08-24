// 600f033a  FUN_600f033a  size=168 bytes
// --- callers ---
//   60099a1c FUN_60099a1c
//   60099adc FUN_60099adc
//   60099bb8 FUN_60099bb8
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009feb8 FUN_6009feb8
//   600bc7e8 FUN_600bc7e8
//   600f1746 FUN_600f1746
//   600a8494 FUN_600a8494


void FUN_600f033a(undefined2 *param_1,byte param_2)

{
  byte bVar1;
  byte local_d;
  int local_c;
  
  local_c = FUN_6009feb8(*param_1);
  if (local_c == 0) {
    local_c = FUN_600f1746(param_1 + 3);
  }
  *(byte *)(param_1 + 0x93) = param_2;
  *(byte *)(local_c + 0x4f) = param_2;
  for (local_d = 0; (local_d < param_2 && (local_d < 3)); local_d = local_d + 1) {
    thunk_EXT_FUN_0000b572((local_d + 6) * 8 + local_c + 7,param_1 + (local_d + 0x21) * 4 + 3,8);
  }
  bVar1 = *(byte *)(local_c + 0x59);
  FUN_600a8494(param_1,local_c);
  if ((bVar1 & 8) != 0) {
    FUN_600bc7e8(local_c + 0x10);
  }
  return;
}


