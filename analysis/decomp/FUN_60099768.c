// 60099768  FUN_60099768  size=160 bytes
// --- callers ---
//   600c269c FUN_600c269c
//   600c2d5c FUN_600c2d5c
// --- callees ---
//   600b3028 FUN_600b3028
//   600a1354 FUN_600a1354


void FUN_60099768(ushort param_1)

{
  byte *pbVar1;
  ushort local_12;
  
  pbVar1 = (byte *)FUN_600a1354();
  local_12 = param_1;
  if (((param_1 & 1) != 0) && ((*pbVar1 & 0x20) == 0)) {
    local_12 = param_1 & 0xfffe;
  }
  if (((local_12 & 2) != 0) && ((*pbVar1 & 0x40) == 0)) {
    local_12 = local_12 & 0xfffd;
  }
  if (((local_12 & 4) != 0) && (-1 < (char)*pbVar1)) {
    local_12 = local_12 & 0xfffb;
  }
  if (((local_12 & 8) != 0) && ((pbVar1[1] & 1) == 0)) {
    local_12 = local_12 & 0xfff7;
  }
  *(ushort *)(DAT_60099808 + 0x640) = local_12;
  FUN_600b3028(local_12);
  return;
}


