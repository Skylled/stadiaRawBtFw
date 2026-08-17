// 60098b70  FUN_60098b70  size=80 bytes
// --- callers ---
// --- callees ---
//   60098a24 FUN_60098a24


undefined4 FUN_60098b70(undefined4 param_1,ushort param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if ((*DAT_60098bc0 == '\x02') || (*DAT_60098bc0 == '\x04')) {
    if (param_2 == 0) {
      uVar2 = 0;
    }
    else {
      pcVar1 = DAT_60098bc0;
      pcVar1[0x10] = '\0';
      pcVar1[0x11] = '\0';
      pcVar1[0x12] = '\0';
      pcVar1[0x13] = '\0';
      *(undefined4 *)(DAT_60098bc0 + 0xc) = param_1;
      *(uint *)(DAT_60098bc0 + 8) = (uint)param_2;
      *DAT_60098bc0 = '\x03';
      FUN_60098a24();
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


