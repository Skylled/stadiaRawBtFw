// 6005a13c  device_info__6005a13c  size=106 bytes
// src: device_info.cc
// --- callers ---
//   6005a4cc device_info__6005a4cc
// --- callees ---
//   600d37b8 FUN_600d37b8
//   600d37ac FUN_600d37ac
//   60059e94 FUN_60059e94
//   60051120 FUN_60051120
//   6005a0ac device_info__6005a0ac
//   60050c18 FUN_60050c18
//   60101ba2 FUN_60101ba2


/* src: device_info.cc */

uint device_info__6005a13c(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_b0;
  undefined4 uStack_ac;
  byte *local_a4;
  undefined4 local_a0;
  uint uStack_9c;
  byte local_98;
  byte local_97;
  byte local_96 [138];
  byte local_c;
  
  local_98 = FUN_60059e94(&local_b0,8);
  uStack_9c = (uint)local_98;
  if (uStack_9c == 0) {
    local_a4 = local_96;
    local_a0 = 0x20;
    local_97 = local_98;
    local_96[0] = local_98;
    uVar1 = FUN_60050c18(local_b0,uStack_ac);
    FUN_60101ba2(&local_a4,uVar1);
    uVar2 = device_info__6005a0ac(param_1,local_a4);
  }
  else {
    FUN_60051120(&local_a4,DAT_6005a1a8,0xa3,2);
    FUN_600d37ac(&uStack_9c,DAT_6005a1ac);
    uVar2 = (uint)local_c;
    FUN_600d37b8(&local_a4);
  }
  return uVar2;
}


