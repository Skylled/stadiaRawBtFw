// 6006e790  gki_ft__6006e790  size=68 bytes
// src: gki_ft.c
// --- callers ---
//   6006e214 FUN_6006e214
//   6006dcdc FUN_6006dcdc
//   6006de78 FUN_6006de78
//   6006dfa4 FUN_6006dfa4
//   6006ddd8 FUN_6006ddd8
//   6006dbac FUN_6006dbac
//   6006e008 FUN_6006e008
// --- callees ---
//   6010165c FUN_6010165c
//   6006be9c FUN_6006be9c
//   6006e594 FUN_6006e594


/* src: gki_ft.c */

void gki_ft__6006e790(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_6006e7d8;
  uVar2 = DAT_6006e7d4;
  FUN_6006be9c(DAT_6006e7d4,DAT_6006e7d8);
  FUN_6006be9c(uVar2,DAT_6006e7dc,param_1,param_2);
  FUN_6006be9c(uVar2,uVar1);
  uVar2 = FUN_6006e594();
  FUN_6010165c(0x28,DAT_6006e7e4,0x263,DAT_6006e7e0,uVar2,param_1,param_2);
  return;
}


