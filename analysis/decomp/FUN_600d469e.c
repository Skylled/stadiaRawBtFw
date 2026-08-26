// 600d469e  FUN_600d469e  size=48 bytes
// --- callers ---
//   6005f728 FUN_6005f728
// --- callees ---
//   600585f8 FUN_600585f8
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6005e1c0 FUN_6005e1c0


void FUN_600d469e(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 auStack_b4 [2];
  int aiStack_b0 [2];
  undefined1 *puStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined1 uStack_9c;
  undefined1 uStack_9b;
  undefined1 auStack_9a [138];
  
  iVar2 = FUN_6005e1c0(0x1878);
  if (iVar2 != 0) {
    uVar3 = FUN_600585f8();
    thunk_EXT_FUN_0000b572(iVar2,uVar3,0x1878);
    if (0x27f7 < (uint)(DAT_6005e390 + iVar2)) {
      aiStack_b0[0] = DAT_6005e394;
      aiStack_b0[1] = 0x91;
      puStack_a8 = auStack_9a;
      uStack_a4 = 0x80;
      uStack_a0 = 0;
      uStack_9c = 0;
      uStack_9b = 0;
      auStack_9a[0] = 0;
      FUN_60101b76(&puStack_a8,DAT_6005e398);
      FUN_60101740(aiStack_b0);
    }
    *(undefined2 *)(iVar2 + -4) = 0x1878;
    *(undefined1 *)(iVar2 + -8) = 0xd5;
    aiStack_b0[1] = 0x1878;
    *(undefined1 *)(iVar2 + -7) = 0xba;
    *(undefined2 *)(iVar2 + -6) = 1;
    auStack_b4[0] = 0xffff;
    aiStack_b0[0] = iVar2;
    uVar1 = FUN_600cc29c(auStack_b4,iVar2,0x1878);
    *(undefined2 *)(iVar2 + -2) = uVar1;
    return;
  }
  return;
}


