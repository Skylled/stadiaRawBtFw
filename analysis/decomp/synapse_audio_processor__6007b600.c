// 6007b600  synapse_audio_processor__6007b600  size=132 bytes
// src: synapse_audio_processor.cc
// --- callers ---
// --- callees ---
//   600d37ac FUN_600d37ac
//   6013d228 thunk_EXT_FUN_000078b0
//   600d5252 FUN_600d5252
//   600cc984 FUN_600cc984
//   600cc8f8 FUN_600cc8f8
//   600d53ae FUN_600d53ae
//   6013d170 thunk_EXT_FUN_00002dec
//   600d3b3a FUN_600d3b3a


/* src: synapse_audio_processor.cc */

void synapse_audio_processor__6007b600(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  uint *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [144];
  
  uVar4 = DAT_6007b690;
  puVar3 = DAT_6007b688;
  pbVar2 = DAT_6007b684;
  while( true ) {
    DataMemoryBarrier(0x1b);
    DataMemoryBarrier(0x1b);
    if (*(char *)(param_1 + 0x60) == '\0') break;
    thunk_EXT_FUN_000078b0(1,0xffffffff);
    if (*(int *)(param_1 + 0x70) == 0) {
      bVar1 = *pbVar2;
      DataMemoryBarrier(0x1b);
      if (((bVar1 & 1) == 0) && (iVar5 = FUN_600cc8f8(pbVar2), iVar5 != 0)) {
        *puVar3 = bVar1 & 1;
        FUN_600cc984(pbVar2);
      }
      iVar5 = FUN_600d5252(puVar3,60000);
      if (iVar5 != 0) {
        local_b0 = uVar4;
        local_ac = 0x21c;
        FUN_600d3b3a(auStack_a8);
        FUN_600d37ac(auStack_a8,DAT_6007b68c);
        FUN_600d53ae(&local_b0);
      }
    }
    do {
      iVar5 = thunk_EXT_FUN_00002dec(param_1);
    } while (iVar5 != 0);
  }
  return;
}


