// 6007ea94  audio_player__6007ea94  size=238 bytes
// src: audio_player.cc
// --- callers ---
// --- callees ---
//   6013d3c8 thunk_EXT_FUN_00001680
//   60101b76 FUN_60101b76
//   601016f0 FUN_601016f0
//   6010209a FUN_6010209a


/* src: audio_player.cc */

void audio_player__6007ea94(int param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  code *pcVar8;
  int local_b4;
  undefined4 local_b0;
  int local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [134];
  
  local_b0 = DAT_6007eb84;
  local_ac = 0x99;
  local_a8 = local_9a;
  local_9c = 0;
  local_9b = 0;
  local_9a[0] = 0;
  local_a4 = 0x80;
  uStack_a0 = 0;
  FUN_60101b76(&local_a8,DAT_6007eb88);
  FUN_601016f0(0x14,local_b0,local_ac,&local_a8);
  DataMemoryBarrier(0x1b);
  *(undefined4 *)(param_1 + 0x74) = 0;
  DataMemoryBarrier(0x1b);
  *(undefined4 *)(param_1 + 0x8c) = 0;
  puVar7 = (uint *)(param_1 + 0x70);
  DataMemoryBarrier(0x1b);
  do {
    ExclusiveAccess(puVar7);
    bVar1 = (bool)hasExclusiveAccess(puVar7);
  } while (!bVar1);
  *puVar7 = *puVar7 | 4;
  DataMemoryBarrier(0x1b);
  (**(code **)(**(int **)(param_1 + 0x98) + 8))();
  (**(code **)(**(int **)(param_1 + 0x84) + 0x10))();
  piVar2 = *(int **)(param_1 + 0x84);
  pcVar8 = *(code **)(*piVar2 + 8);
  iVar5 = *(int *)(param_1 + 8);
  if (iVar5 != 0) {
    piVar4 = (int *)(iVar5 + 4);
    iVar6 = *(int *)(iVar5 + 4);
    while (iVar6 != 0) {
      DataMemoryBarrier(0x1b);
      ExclusiveAccess(piVar4);
      iVar3 = *piVar4;
      bVar1 = false;
      if (iVar3 == iVar6) {
        bVar1 = (bool)hasExclusiveAccess(piVar4);
        if (bVar1) {
          *piVar4 = iVar6 + 1;
        }
        DataMemoryBarrier(0x1b);
      }
      iVar6 = iVar3;
      if (bVar1) {
        local_b0 = *(undefined4 *)(param_1 + 4);
        local_b4 = 0;
        local_ac = iVar5;
        (*pcVar8)(piVar2,&local_b0,piVar4,iVar5,0);
        thunk_EXT_FUN_00001680(&local_ac);
        thunk_EXT_FUN_00001680(&local_b4);
        *(undefined1 *)(param_1 + 0xa0) = 0;
        DataMemoryBarrier(0x1b);
        do {
          ExclusiveAccess(puVar7);
          bVar1 = (bool)hasExclusiveAccess(puVar7);
        } while (!bVar1);
        *puVar7 = *puVar7 | 2;
        DataMemoryBarrier(0x1b);
        return;
      }
    }
  }
  local_b4 = iVar5;
                    /* WARNING: Subroutine does not return */
  FUN_6010209a();
}


