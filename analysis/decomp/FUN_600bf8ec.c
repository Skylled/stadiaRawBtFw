// 600bf8ec  FUN_600bf8ec  size=576 bytes
// --- callers ---
//   600be558 FUN_600be558
//   600beb20 FUN_600beb20
// --- callees ---


byte * FUN_600bf8ec(byte *param_1,ushort param_2,ushort *param_3)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *local_1c;
  uint local_10;
  uint local_c;
  
  *param_3 = 0;
  local_1c = param_1 + 1;
  bVar1 = *param_1 & 7;
  if (*param_1 >> 3 == 6) {
    if (bVar1 == 6) {
      local_c = (uint)param_1[2] + (uint)*local_1c * 0x100;
      local_1c = param_1 + 3;
    }
    else if (bVar1 == 7) {
      local_c = (uint)*local_1c * 0x1000000 +
                (uint)param_1[4] + (uint)param_1[3] * 0x100 + (uint)param_1[2] * 0x10000;
      local_1c = param_1 + 5;
    }
    else {
      if (bVar1 != 5) {
        return local_1c;
      }
      local_c = (uint)*local_1c;
      local_1c = param_1 + 2;
    }
    if (local_c <= param_2) {
      pbVar2 = local_1c + local_c;
      do {
        if (pbVar2 <= local_1c) {
          return local_1c;
        }
        pbVar3 = local_1c + 1;
        if (*local_1c >> 3 != 1) {
          return pbVar3;
        }
        switch(*local_1c & 7) {
        case 1:
          local_10 = 2;
          local_1c = pbVar3;
          break;
        case 2:
          local_10 = 4;
          local_1c = pbVar3;
          break;
        default:
          return (byte *)0x0;
        case 5:
          local_10 = (uint)*pbVar3;
          local_1c = local_1c + 2;
          break;
        case 6:
          local_10 = (uint)local_1c[2] + (uint)*pbVar3 * 0x100;
          local_1c = local_1c + 3;
          break;
        case 7:
          local_10 = (uint)*pbVar3 * 0x1000000 +
                     (uint)local_1c[4] + (uint)local_1c[3] * 0x100 + (uint)local_1c[2] * 0x10000;
          local_1c = local_1c + 5;
        }
        if (local_10 == 2) {
          param_3[(uint)*param_3 * 2 + 1] = (ushort)local_1c[1] + (ushort)*local_1c * 0x100;
          local_1c = local_1c + 2;
          param_3[(uint)*param_3 * 2 + 2] = param_3[(uint)*param_3 * 2 + 1];
        }
        else {
          if (local_10 != 4) {
            return (byte *)0x0;
          }
          param_3[(uint)*param_3 * 2 + 1] = (ushort)local_1c[1] + (ushort)*local_1c * 0x100;
          param_3[(uint)*param_3 * 2 + 2] = (ushort)local_1c[3] + (ushort)local_1c[2] * 0x100;
          local_1c = local_1c + 4;
        }
        *param_3 = *param_3 + 1;
      } while (*param_3 < 0x10);
      local_1c = (byte *)0x0;
    }
  }
  return local_1c;
}


