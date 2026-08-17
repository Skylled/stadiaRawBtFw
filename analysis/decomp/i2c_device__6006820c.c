// 6006820c  i2c_device__6006820c  size=100 bytes
// src: i2c_device.h
// --- callers ---
//   60074658 timer__60074658
// --- callees ---
//   600d37ac FUN_600d37ac
//   600d82c0 FUN_600d82c0
//   60101740 FUN_60101740
//   600d82d8 FUN_600d82d8


/* src: i2c_device.h */

void i2c_device__6006820c(undefined4 param_1,uint param_2)

{
  undefined1 auStack_a8 [5];
  byte local_a3;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 *local_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined1 local_8c;
  undefined1 local_8b;
  undefined1 local_8a [130];
  
  FUN_600d82d8(auStack_a8,param_1,6);
  if ((param_2 & 0xfffffff8) != 0) {
    local_a0 = DAT_60068270;
    local_9c = 0x52;
    local_98 = local_8a;
    local_94 = 0x80;
    uStack_90 = 0;
    local_8c = 0;
    local_8b = 0;
    local_8a[0] = 0;
    FUN_600d37ac(&local_98,DAT_60068274);
    FUN_60101740(&local_a0);
  }
  local_a3 = (byte)(param_2 << 3) & 0x38 | local_a3 & 199;
  FUN_600d82c0(auStack_a8);
  return;
}


