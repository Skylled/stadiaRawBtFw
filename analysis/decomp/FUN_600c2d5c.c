// 600c2d5c  FUN_600c2d5c  size=296 bytes
// --- callers ---
//   600c4d18 FUN_600c4d18
// --- callees ---
//   60099768 FUN_60099768
//   600944c0 FUN_600944c0
//   600f0252 FUN_600f0252
//   600942d4 FUN_600942d4


void FUN_600c2d5c(undefined1 param_1,sbyte param_2,byte param_3,int param_4)

{
  int local_c;
  
  local_c = 0;
  if (param_4 != 0) {
    local_c = FUN_600944c0(param_4);
  }
  switch(param_1) {
  case 0x10:
    if (local_c != 0) {
      *(ushort *)(local_c + 6) = (ushort)param_3 | *(ushort *)(local_c + 6);
      FUN_600f0252(local_c,local_c + 6);
    }
    break;
  case 0x11:
    if (local_c != 0) {
      *(ushort *)(local_c + 6) = ~(ushort)param_3 & *(ushort *)(local_c + 6);
      FUN_600f0252(local_c,local_c + 6);
      if ((param_3 & 0xc) != 0) {
        FUN_600942d4(local_c);
      }
    }
    break;
  case 0x12:
    *(uint *)(DAT_600c2e98 + 0x23c) = ~(1 << param_2) & *(uint *)(DAT_600c2e98 + 0x23c);
    if (*(int *)(DAT_600c2e98 + 0x23c) == 0) {
      *(ushort *)(DAT_600c2e98 + 0x240) = *(ushort *)(DAT_600c2e98 + 0x240) | 1;
      FUN_60099768(*(undefined2 *)(DAT_600c2e98 + 0x240));
    }
    break;
  case 0x13:
    *(uint *)(DAT_600c2e98 + 0x23c) = 1 << param_2 | *(uint *)(DAT_600c2e98 + 0x23c);
    *(ushort *)(DAT_600c2e98 + 0x240) = *(ushort *)(DAT_600c2e98 + 0x240) & 0xfffe;
    FUN_60099768(*(undefined2 *)(DAT_600c2e98 + 0x240));
  }
  return;
}


