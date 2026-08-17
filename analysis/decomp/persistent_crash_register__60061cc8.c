// 60061cc8  persistent_crash_register__60061cc8  size=100 bytes
// src: persistent_crash_register.cc
// --- callers ---
//   6005f8c0 FUN_6005f8c0
// --- callees ---
//   6010112c FUN_6010112c
//   60101198 FUN_60101198
//   6010165c FUN_6010165c
//   60061c48 FUN_60061c48
//   600d512e FUN_600d512e
//   600d5122 FUN_600d5122


/* src: persistent_crash_register.cc */

uint persistent_crash_register__60061cc8(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined1 auStack_84 [16];
  undefined1 auStack_74 [104];
  
  FUN_600d5122(auStack_84);
  uVar1 = FUN_600d512e(*param_1,auStack_84);
  if ((uVar1 & 0xff) == 0) {
    uVar1 = FUN_60061c48(auStack_84,auStack_74,100);
    if (uVar1 < 100) {
      if (uVar1 == 0) {
        uVar1 = FUN_6010112c(param_2,DAT_60061d34);
        if (((uVar1 & 0xff) != 0) && ((uVar1 & 0xff) != 5)) {
          return uVar1;
        }
        return 0;
      }
    }
    else {
      FUN_6010165c(0x1e,DAT_60061d30,0x6a,DAT_60061d2c);
    }
    uVar1 = FUN_60101198(param_2,DAT_60061d34,auStack_74,uVar1 + 1 & 0xffff);
  }
  return uVar1;
}


