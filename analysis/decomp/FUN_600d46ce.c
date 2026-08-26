// 600d46ce  FUN_600d46ce  size=48 bytes
// --- callers ---
//   6005f728 FUN_6005f728
// --- callees ---
//   6005e1c0 FUN_6005e1c0


void FUN_600d46ce(undefined1 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  undefined2 auStack_b4 [2];
  undefined1 *puStack_b0;
  undefined4 uStack_ac;
  undefined1 *puStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined1 uStack_9c;
  undefined1 uStack_9b;
  undefined1 auStack_9a [138];
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  puVar2 = (undefined1 *)FUN_6005e1c0(0xd);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = param_1;
    *(undefined4 *)(puVar2 + 1) = *param_2;
    *(undefined4 *)(puVar2 + 5) = param_2[1];
    *(undefined4 *)(puVar2 + 9) = param_2[2];
    if ((undefined1 *)0x27f7 < puVar2 + DAT_6005e390) {
      puStack_b0 = DAT_6005e394;
      uStack_ac = 0x91;
      puStack_a8 = auStack_9a;
      uStack_a4 = 0x80;
      uStack_a0 = 0;
      uStack_9c = 0;
      uStack_9b = 0;
      auStack_9a[0] = 0;
      FUN_60101b76(&puStack_a8,DAT_6005e398);
      FUN_60101740(&puStack_b0);
    }
    *(undefined2 *)(puVar2 + -4) = 0xd;
    puVar2[-8] = 0xd5;
    uStack_ac = 0xd;
    puVar2[-7] = 0xba;
    *(undefined2 *)(puVar2 + -6) = 3;
    auStack_b4[0] = 0xffff;
    puStack_b0 = puVar2;
    uVar1 = FUN_600cc29c(auStack_b4,puVar2,0xd);
    *(undefined2 *)(puVar2 + -2) = uVar1;
    return;
  }
  return;
}


