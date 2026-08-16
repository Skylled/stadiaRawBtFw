// 600cbebc  logger__600cbebc  size=216 bytes
// src: logger.cc
// --- callers ---
// --- callees ---
//   6013d0e8 thunk_EXT_FUN_00006a74
//   60101b5a FUN_60101b5a
//   6013d258 thunk_EXT_FUN_0000b50a
//   6013d268 thunk_EXT_FUN_00006d2c
//   600d3618 FUN_600d3618
//   6010162e FUN_6010162e
//   60101bcc FUN_60101bcc
//   6005f8c0 FUN_6005f8c0


/* src: logger.cc */

void logger__600cbebc(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *local_ac;
  undefined4 local_a8;
  undefined2 local_a4;
  undefined1 local_a2;
  undefined1 *local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [130];
  
  thunk_EXT_FUN_00006d2c(*(undefined4 *)(*(int *)(param_1 + 0x1cc) + 0x50),&local_ac,0xffffffff);
  puVar2 = local_ac;
  if (*(char *)(local_ac + 6) == '\b') {
    puVar5 = local_ac + 3;
    FUN_60101b5a(puVar5,local_ac[5] + -3);
    thunk_EXT_FUN_0000b50a(puVar5,DAT_600cbf94,3);
  }
  FUN_6010162e(param_1,puVar2);
  piVar3 = (int *)(param_1 + 0x158);
  DataMemoryBarrier(0x1b);
  do {
    ExclusiveAccess(piVar3);
    iVar4 = *piVar3;
    bVar1 = (bool)hasExclusiveAccess(piVar3);
  } while (!bVar1);
  *piVar3 = 0;
  DataMemoryBarrier(0x1b);
  if (iVar4 != 0) {
    local_a0 = local_92;
    local_94 = 0;
    local_93 = 0;
    local_92[0] = 0;
    local_9c = 0x80;
    uStack_98 = 0;
    local_a2 = 0x1e;
    local_ac = DAT_600cbf9c;
    local_a4 = 0x5b;
    FUN_60101bcc(&local_a0,DAT_600cbf98);
    local_a8 = FUN_600d3618();
    FUN_6010162e(param_1,&local_ac);
  }
  if (*(char *)((int)puVar2 + 10) == '2') {
    FUN_6005f8c0(puVar2[3],*puVar2,*(undefined2 *)(puVar2 + 2));
  }
  if (puVar2 == (undefined4 *)(param_1 + 0x60)) {
    DataMemoryBarrier(0x1b);
    *(undefined1 *)(param_1 + 0xfc) = 0;
    DataMemoryBarrier(0x1b);
  }
  else {
    thunk_EXT_FUN_00006a74(*(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x50),&local_ac,0xffffffff,0)
    ;
  }
  return;
}


