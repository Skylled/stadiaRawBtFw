// 60071a30  board__60071a30  size=118 bytes
// src: board.cc
// --- callers ---
//   600cbdc8 xbara__600cbdc8
// --- callees ---
//   6010165c FUN_6010165c
//   600ce24c FUN_600ce24c
//   6005fe04 io_pin__6005fe04


/* src: board.cc */

bool board__60071a30(int param_1)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  
  io_pin__6005fe04(param_1 + 0x8b0);
  io_pin__6005fe04(param_1 + 0x8dc);
  io_pin__6005fe04(param_1 + 0x908);
  bVar1 = FUN_600ce24c(param_1 + 0x8b0);
  cVar2 = FUN_600ce24c(param_1 + 0x8dc);
  cVar3 = FUN_600ce24c(param_1 + 0x908);
  iVar4 = (int)(char)(cVar2 << 1 | cVar3 << 2 | bVar1);
  FUN_6010165c(0x14,DAT_60071aac,0x1e3,DAT_60071aa8,iVar4);
  if (iVar4 != 3) {
    FUN_6010165c(0x28,DAT_60071aac,0x1e7,DAT_60071ab0,3,iVar4);
  }
  return iVar4 == 3;
}


