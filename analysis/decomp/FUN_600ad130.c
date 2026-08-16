// 600ad130  FUN_600ad130  size=244 bytes
// --- callers ---
//   600f4f02 FUN_600f4f02
//   600f552e FUN_600f552e
// --- callees ---


undefined4 FUN_600ad130(int param_1,undefined4 param_2,char param_3,byte param_4,byte param_5)

{
  ushort uVar1;
  uint uVar2;
  ushort local_a;
  
  uVar1 = *(ushort *)(param_1 + 10);
  local_a = uVar1 >> 0xc;
  if (local_a != 0) {
    local_a = local_a + 6;
  }
  if ((uVar1 & 7) == 0) {
    return 2;
  }
  if ((((uVar1 & 2) != 0) && ((param_4 & 0x10) == 0)) && ((param_4 & 4) == 0)) {
    return 5;
  }
  if (((uVar1 & 4) != 0) && ((param_4 & 0x20) == 0)) {
    return 5;
  }
  if (((uVar1 & 6) != 0) && ((param_4 & 4) == 0)) {
    return 0xf;
  }
  if ((((uVar1 & 6) != 0) && ((param_4 & 4) != 0)) && (param_5 < local_a)) {
    return 0xc;
  }
  if (param_3 == '\0') {
    return 0;
  }
  uVar2 = (uint)*(ushort *)(param_1 + 0xe);
  if (uVar2 != 0x2900) {
    if (uVar2 < 0x2901) {
      if (3 < uVar2 - 0x2800) {
        return 0;
      }
    }
    else if (2 < DAT_600ad224 + uVar2) {
      return 0;
    }
  }
  return 0xb;
}


