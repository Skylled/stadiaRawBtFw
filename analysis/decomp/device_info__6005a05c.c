// 6005a05c  device_info__6005a05c  size=66 bytes
// src: device_info.cc
// --- callers ---
//   600cbdc8 xbara__600cbdc8
//   6005a6b0 device_info__6005a6b0
// --- callees ---
//   60065eb8 keys__60065eb8
//   600d37b8 FUN_600d37b8
//   600d37ac FUN_600d37ac
//   60051120 FUN_60051120


/* src: device_info.cc */

undefined1 device_info__6005a05c(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined1 auStack_a4 [8];
  undefined1 auStack_9c [144];
  undefined1 local_c;
  
  if (*(char *)(DAT_6005a0a0 + 0xa8) == '\0') {
    uVar2 = keys__60065eb8(0x3a,DAT_6005a0a0,0x11);
    uVar1 = 0;
    if ((uVar2 & 0xff) != 0) {
      FUN_60051120(auStack_a4,DAT_6005a0a4,0x57,uVar2);
      FUN_600d37ac(auStack_9c,DAT_6005a0a8);
      FUN_600d37b8(auStack_a4);
      uVar1 = local_c;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


