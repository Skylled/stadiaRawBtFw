// 6004b7b4  FUN_6004b7b4  size=62 bytes
// --- callers ---
// --- callees ---
//   6004b62e FUN_6004b62e


void FUN_6004b7b4(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  uVar2 = param_1[2];
  uVar1 = param_1[3];
  local_14 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
             uVar2 >> 0x18;
  local_18 = uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 |
             uVar1 >> 0x18;
  uVar2 = *param_1;
  uVar1 = param_1[1];
  local_c = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
            uVar2 >> 0x18;
  local_10 = uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 |
             uVar1 >> 0x18;
  FUN_6004b62e(&local_18);
  *param_1 = local_c << 0x18 | (local_c >> 8 & 0xff) << 0x10 | (local_c >> 0x10 & 0xff) << 8 |
             local_c >> 0x18;
  param_1[1] = local_10 << 0x18 | (local_10 >> 8 & 0xff) << 0x10 | (local_10 >> 0x10 & 0xff) << 8 |
               local_10 >> 0x18;
  param_1[2] = local_14 << 0x18 | (local_14 >> 8 & 0xff) << 0x10 | (local_14 >> 0x10 & 0xff) << 8 |
               local_14 >> 0x18;
  param_1[3] = local_18 << 0x18 | (local_18 >> 8 & 0xff) << 0x10 | (local_18 >> 0x10 & 0xff) << 8 |
               local_18 >> 0x18;
  return;
}


