// 6007e728  audio_player__6007e728  size=84 bytes
// src: audio_player.cc
// --- callers ---
//   60079bf4 FUN_60079bf4
// --- callees ---
//   6010165c FUN_6010165c
//   6013d138 thunk_EXT_FUN_0000645c
//   601017b4 FUN_601017b4


/* src: audio_player.cc */

void audio_player__6007e728(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  uint *puVar5;
  
  DataMemoryBarrier(0x1b);
  puVar5 = (uint *)(param_1 + 0x70);
  do {
    ExclusiveAccess(puVar5);
    bVar1 = (bool)hasExclusiveAccess(puVar5);
  } while (!bVar1);
  *puVar5 = *puVar5 & 0xfffffffe;
  DataMemoryBarrier(0x1b);
  thunk_EXT_FUN_0000645c();
  uVar3 = DAT_6007e780;
  uVar2 = DAT_6007e77c;
  (**(code **)(*(int *)(param_1 + 0xc) + 0xc))(param_1 + 0xc);
  while (cVar4 = FUN_601017b4(param_1 + 0xc,1000), cVar4 != '\0') {
    FUN_6010165c(0x1e,uVar3,0x6d,uVar2);
  }
  return;
}


