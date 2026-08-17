// 6006816c  accessory_detect_ts3a227e__6006816c  size=140 bytes
// src: accessory_detect_ts3a227e.cc
// --- callers ---
//   60074658 timer__60074658
// --- callees ---
//   600d37b8 FUN_600d37b8
//   6010165c FUN_6010165c
//   600d8226 FUN_600d8226
//   60051120 FUN_60051120
//   600d81f8 FUN_600d81f8
//   600d37ac FUN_600d37ac


/* src: accessory_detect_ts3a227e.cc */

undefined1 accessory_detect_ts3a227e__6006816c(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_a5;
  undefined1 auStack_a4 [8];
  undefined1 auStack_9c [144];
  undefined1 local_c;
  
  local_a5 = *(char *)(param_1 + 10);
  if (local_a5 != '\0') {
    return 0;
  }
  uVar1 = FUN_600d81f8(param_1,0,&local_a5,200);
  if ((uVar1 & 0xff) == 0) {
    if (local_a5 != '\x11') {
      FUN_6010165c(0x1e,DAT_600681f8,0x3e,DAT_60068200);
      return 5;
    }
    *(undefined1 *)(param_1 + 10) = 1;
    uVar1 = FUN_600d8226(param_1);
    if ((uVar1 & 0xff) == 0) {
      FUN_6010165c(10,DAT_600681f8,0x46,DAT_60068208);
      return 0;
    }
    FUN_60051120(auStack_a4,DAT_600681f8,0x43,uVar1);
    uVar2 = DAT_60068204;
  }
  else {
    FUN_60051120(auStack_a4,DAT_600681f8,0x3a,uVar1);
    uVar2 = DAT_600681fc;
  }
  FUN_600d37ac(auStack_9c,uVar2);
  FUN_600d37b8(auStack_a4);
  return local_c;
}


