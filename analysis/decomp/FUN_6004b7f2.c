// 6004b7f2  FUN_6004b7f2  size=146 bytes
// --- callers ---
// --- callees ---
//   6004b62e FUN_6004b62e
//   6004b7a4 FUN_6004b7a4


void FUN_6004b7f2(uint *param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  uVar2 = param_1[2];
  uVar1 = param_1[3];
  local_34 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
             uVar2 >> 0x18;
  param_3 = param_3 + param_4;
  local_38 = uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 |
             uVar1 >> 0x18;
  uVar2 = *param_1;
  uVar1 = param_1[1];
  local_2c = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
             uVar2 >> 0x18;
  local_30 = uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 |
             uVar1 >> 0x18;
  for (; 0xf < param_4; param_4 = param_4 - 0x10) {
    FUN_6004b7a4(&local_28,param_3 - param_4);
    local_34 = local_34 ^
               (local_20 << 0x18 | (local_20 >> 8 & 0xff) << 0x10 | (local_20 >> 0x10 & 0xff) << 8 |
               local_20 >> 0x18);
    local_38 = local_38 ^
               (local_1c << 0x18 | (local_1c >> 8 & 0xff) << 0x10 | (local_1c >> 0x10 & 0xff) << 8 |
               local_1c >> 0x18);
    local_30 = local_30 ^
               (local_24 << 0x18 | (local_24 >> 8 & 0xff) << 0x10 | (local_24 >> 0x10 & 0xff) << 8 |
               local_24 >> 0x18);
    local_2c = local_2c ^
               (local_28 << 0x18 | (local_28 >> 8 & 0xff) << 0x10 | (local_28 >> 0x10 & 0xff) << 8 |
               local_28 >> 0x18);
    FUN_6004b62e(&local_38,param_2);
  }
  *param_1 = local_2c << 0x18 | (local_2c >> 8 & 0xff) << 0x10 | (local_2c >> 0x10 & 0xff) << 8 |
             local_2c >> 0x18;
  param_1[1] = local_30 << 0x18 | (local_30 >> 8 & 0xff) << 0x10 | (local_30 >> 0x10 & 0xff) << 8 |
               local_30 >> 0x18;
  param_1[2] = local_34 << 0x18 | (local_34 >> 8 & 0xff) << 0x10 | (local_34 >> 0x10 & 0xff) << 8 |
               local_34 >> 0x18;
  param_1[3] = local_38 << 0x18 | (local_38 >> 8 & 0xff) << 0x10 | (local_38 >> 0x10 & 0xff) << 8 |
               local_38 >> 0x18;
  return;
}


