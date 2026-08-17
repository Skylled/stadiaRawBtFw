// 60059f00  snvs__60059f00  size=138 bytes
// src: snvs.h
// --- callers ---
//   60059f98 reboot_reason__60059f98
//   600d512e FUN_600d512e
// --- callees ---
//   60101b76 FUN_60101b76
//   60101740 FUN_60101740


/* src: snvs.h */

undefined4 snvs__60059f00(char *param_1,uint param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 *local_a0;
  undefined4 local_9c;
  undefined4 *puStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [130];
  
  if (param_3 == (undefined4 *)0x0) {
    local_a8 = DAT_60059f8c;
    local_94 = 0;
    local_a4 = 0x2b;
    local_a0 = local_92;
    local_93 = 0;
    local_92[0] = 0;
    local_9c = 0x80;
    puStack_98 = param_3;
    FUN_60101b76(&local_a0,DAT_60059f90);
    FUN_60101740(&local_a8);
  }
  if (3 < param_2) {
    local_a8 = DAT_60059f8c;
    local_a4 = 0x2c;
    local_a0 = local_92;
    local_9c = 0x80;
    puStack_98 = (undefined4 *)0x0;
    local_94 = 0;
    local_93 = 0;
    local_92[0] = 0;
    FUN_60101b76(&local_a0,DAT_60059f90);
    FUN_60101740(&local_a8);
  }
  if (*param_1 == '\0') {
    uVar1 = 9;
  }
  else {
    uVar1 = 0;
    *param_3 = *(undefined4 *)(DAT_60059f94 + (param_2 + 0x40) * 4);
  }
  return uVar1;
}


