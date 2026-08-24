// 600ee82a  FUN_600ee82a  size=114 bytes
// --- callers ---
//   600ee8f2 FUN_600ee8f2
// --- callees ---


void FUN_600ee82a(int param_1,short *param_2,undefined2 *param_3,char param_4)

{
  undefined4 local_c;
  
  if (param_4 == '\0') {
    local_c = (uint)*(byte *)(param_1 + 0x2d) * 0x1c + *(int *)(param_1 + 0x28);
    *param_2 = *(short *)(local_c + 0x14) + 1;
  }
  else {
    local_c = (uint)*(byte *)(param_1 + 0x2c) * 0x1c + *(int *)(param_1 + 0x28);
    *param_2 = *(short *)(local_c + 0x14);
  }
  *param_3 = *(undefined2 *)(local_c + 0x16);
  return;
}


