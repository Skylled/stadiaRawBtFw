// 6009b134  FUN_6009b134  size=248 bytes
// --- callers ---
// --- callees ---


char FUN_6009b134(int param_1,char *param_2)

{
  char local_9;
  
  local_9 = '\0';
  if (*(int *)(DAT_6009b22c + 0x1138) != 0) {
    local_9 = (**(code **)(DAT_6009b22c + 0x1138))(1,param_1 + 0x10,param_2);
  }
  if (local_9 == '\0') {
    param_2[2] = param_2[2] & 0x1d;
    if ((*(ushort *)(param_1 + 0x54) & 0x1000) != 0) {
      param_2[2] = param_2[2] | 4;
    }
    if ((param_2[2] & 1U) == 0) {
      param_2[4] = '\0';
      param_2[5] = '\0';
    }
    if ((*param_2 == '\x03') && (param_2[1] == '\0')) {
      param_2[2] = param_2[2] & 0xfb;
    }
    param_2[4] = param_2[4] & 0xf;
    param_2[5] = param_2[5] & 0xf;
    if ((param_2[2] & 8U) == 0) {
      param_2[2] = param_2[2] & 0xef;
      param_2[4] = param_2[4] & 0xf7;
      param_2[5] = param_2[5] & 0xf7;
    }
  }
  return local_9;
}


