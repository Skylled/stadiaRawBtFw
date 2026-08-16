// 600bf6a0  FUN_600bf6a0  size=526 bytes
// --- callers ---
//   600beb20 FUN_600beb20
//   600be150 FUN_600be150
// --- callees ---


byte * FUN_600bf6a0(byte *param_1,ushort param_2,ushort *param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte *local_1c;
  uint local_10;
  uint local_c;
  
  *param_3 = 0;
  local_1c = param_1 + 1;
  if (*param_1 >> 3 == 6) {
    switch(*param_1 & 7) {
    case 1:
      local_c = 2;
      break;
    case 2:
      local_c = 4;
      break;
    default:
      return (byte *)0x0;
    case 4:
      local_c = 0x10;
      break;
    case 5:
      local_c = (uint)*local_1c;
      local_1c = param_1 + 2;
      break;
    case 6:
      local_c = (uint)param_1[2] + (uint)*local_1c * 0x100;
      local_1c = param_1 + 3;
      break;
    case 7:
      local_c = (uint)*local_1c * 0x1000000 +
                (uint)param_1[4] + (uint)param_1[3] * 0x100 + (uint)param_1[2] * 0x10000;
      local_1c = param_1 + 5;
    }
    if (local_c < param_2) {
      pbVar1 = local_1c + local_c;
      do {
        if (pbVar1 <= local_1c) {
          if (local_1c != pbVar1) {
            return (byte *)0x0;
          }
          return local_1c;
        }
        pbVar2 = local_1c + 1;
        if (*local_1c >> 3 != 3) {
          return (byte *)0x0;
        }
        switch(*local_1c & 7) {
        case 1:
          local_10 = 2;
          local_1c = pbVar2;
          break;
        case 2:
          local_10 = 4;
          local_1c = pbVar2;
          break;
        default:
          return (byte *)0x0;
        case 4:
          local_10 = 0x10;
          local_1c = pbVar2;
          break;
        case 5:
          local_10 = (uint)*pbVar2;
          local_1c = local_1c + 2;
          break;
        case 6:
          local_10 = (uint)local_1c[2] + (uint)*pbVar2 * 0x100;
          local_1c = local_1c + 3;
          break;
        case 7:
          local_10 = (uint)*pbVar2 * 0x1000000 +
                     (uint)local_1c[4] + (uint)local_1c[3] * 0x100 + (uint)local_1c[2] * 0x10000;
          local_1c = local_1c + 5;
        }
        if (((local_10 != 2) && (local_10 != 4)) && (local_10 != 0x10)) {
          return (byte *)0x0;
        }
        param_3[(uint)*param_3 * 9 + 1] = (ushort)local_10;
        for (iVar3 = 0; iVar3 < (int)local_10; iVar3 = iVar3 + 1) {
          *(byte *)((int)param_3 + iVar3 + (uint)*param_3 * 0x12 + 4) = *local_1c;
          local_1c = local_1c + 1;
        }
        *param_3 = *param_3 + 1;
      } while (*param_3 < 0x10);
    }
  }
  return (byte *)0x0;
}


