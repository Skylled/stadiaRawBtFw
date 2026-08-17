// 600bfb4c  FUN_600bfb4c  size=14 bytes
// --- callers ---
//   600fa34e FUN_600fa34e
// --- callees ---


byte * FUN_600bfb4c(byte *param_1,byte param_2,uint *param_3)

{
  byte *local_14;
  
  local_14 = param_1;
  switch(param_2 & 7) {
  case 0:
    *param_3 = 1;
    break;
  case 1:
    *param_3 = 2;
    break;
  case 2:
    *param_3 = 4;
    break;
  case 3:
    *param_3 = 8;
    break;
  case 4:
    *param_3 = 0x10;
    break;
  case 5:
    local_14 = param_1 + 1;
    *param_3 = (uint)*param_1;
    break;
  case 6:
    local_14 = param_1 + 2;
    *param_3 = (uint)(ushort)((ushort)param_1[1] + (ushort)*param_1 * 0x100);
    break;
  case 7:
    local_14 = param_1 + 4;
    *param_3 = (uint)param_1[3] + (uint)param_1[2] * 0x100;
  }
  return local_14;
}


