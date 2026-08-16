// 600e6a52  FUN_600e6a52  size=26 bytes
// --- callers ---
//   6004cdb8 FUN_6004cdb8
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88


undefined8 FUN_600e6a52(uint param_1,uint param_2,undefined4 param_3)

{
  uint local_10;
  uint local_c;
  undefined4 uStack_8;
  
  local_10 = param_1;
  local_c = param_2;
  uStack_8 = param_3;
  thunk_EXT_FUN_0000af88(&local_10,param_1,8);
  return CONCAT44(local_10 << 0x18 | (local_10 >> 8 & 0xff) << 0x10 | (local_10 >> 0x10 & 0xff) << 8
                  | local_10 >> 0x18,
                  local_c << 0x18 | (local_c >> 8 & 0xff) << 0x10 | (local_c >> 0x10 & 0xff) << 8 |
                  local_c >> 0x18);
}


