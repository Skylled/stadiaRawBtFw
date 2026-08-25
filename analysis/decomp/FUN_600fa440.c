// 600fa440  FUN_600fa440  size=296 bytes
// --- callers ---
//   600bdb14 FUN_600bdb14
// --- callees ---


int FUN_600fa440(undefined1 *param_1,ushort param_2,short *param_3)

{
  short sVar1;
  char *pcVar2;
  undefined1 *puVar3;
  short *local_2c;
  undefined1 *local_24;
  ushort local_c;
  ushort local_a;
  
  local_2c = param_3;
  local_24 = param_1;
  for (local_a = 0; local_a < param_2; local_a = local_a + 1) {
    sVar1 = local_2c[1];
    pcVar2 = local_24 + 1;
    *local_24 = 0x35;
    *pcVar2 = ((char)sVar1 + '\x01') * '\x03';
    local_24[2] = 0x19;
    puVar3 = local_24 + 4;
    local_24[3] = (char)((ushort)*local_2c >> 8);
    local_24 = local_24 + 5;
    *puVar3 = (char)*local_2c;
    sVar1 = *local_2c;
    for (local_c = 0; local_c < (ushort)local_2c[1]; local_c = local_c + 1) {
      if (sVar1 == 3) {
        puVar3 = local_24 + 1;
        *local_24 = 8;
        local_24 = local_24 + 2;
        *puVar3 = (char)local_2c[local_c + 2];
        *pcVar2 = *pcVar2 + -1;
      }
      else {
        *local_24 = 9;
        puVar3 = local_24 + 2;
        local_24[1] = (char)((ushort)local_2c[local_c + 2] >> 8);
        local_24 = local_24 + 3;
        *puVar3 = (char)local_2c[local_c + 2];
      }
    }
    local_2c = local_2c + 4;
  }
  return (int)local_24 - (int)param_1;
}


