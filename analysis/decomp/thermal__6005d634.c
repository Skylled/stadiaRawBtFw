// 6005d634  thermal__6005d634  size=74 bytes
// src: thermal.cc
// --- callers ---
//   60051240 main__60051240
// --- callees ---
//   600d4308 FUN_600d4308
//   6005d3b4 thermal__6005d3b4
//   6010165c FUN_6010165c
//   6013d2a0 thunk_EXT_FUN_00007a2c


/* src: thermal.cc */

void thermal__6005d634(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_6010165c(0x14,DAT_6005d684,0xfa,DAT_6005d680,param_1,param_2);
  iVar1 = DAT_6005d68c;
  if (*(char *)(DAT_6005d688 + 0x4362) == '\0') {
    uVar2 = 10;
    thunk_EXT_FUN_00007a2c(*(undefined4 *)(DAT_6005d68c + 4),4,15000,0,10);
    FUN_6010165c(0x1e,DAT_6005d684,0xff,DAT_6005d690,uVar2,param_2);
  }
  else {
    thermal__6005d3b4(0);
  }
  FUN_600d4308(*(undefined4 *)(iVar1 + 4));
  return;
}


