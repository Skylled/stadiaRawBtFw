// 6007fcec  battery_service__6007fcec  size=180 bytes
// src: battery_service.cc
// --- callers ---
//   6007ffd0 battery_service__6007ffd0
// --- callees ---
//   6013cf80 thunk_EXT_FUN_0000714c
//   601016f0 FUN_601016f0
//   600684bc FUN_600684bc
//   600cc8f8 FUN_600cc8f8
//   600d37ac FUN_600d37ac
//   600cc984 FUN_600cc984
//   60101b76 FUN_60101b76
//   600cbb14 FUN_600cbb14


/* src: battery_service.cc */

undefined4 battery_service__6007fcec(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  uint *puVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  byte local_b8 [4];
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [134];
  
  local_b4 = 0;
  bVar4 = FUN_600684bc(*(undefined4 *)(param_1 + 0xd0),&local_b4);
  puVar3 = DAT_6007fda4;
  pbVar2 = DAT_6007fda0;
  if (bVar4 != 0) {
    bVar1 = *DAT_6007fda0;
    DataMemoryBarrier(0x1b);
    if (((bVar1 & 1) == 0) && (iVar5 = FUN_600cc8f8(DAT_6007fda0), iVar5 != 0)) {
      *puVar3 = bVar1 & 1;
      FUN_600cc984(pbVar2);
    }
    uVar6 = thunk_EXT_FUN_0000714c();
    uVar6 = ((uVar6 % 1000) * 1000 + 500) / 1000 + (uVar6 / 1000) * 1000;
    if (*puVar3 + 5000 <= uVar6) {
      *puVar3 = uVar6;
      local_b0 = DAT_6007fda8;
      local_ac = 0x27;
      local_a8 = local_9a;
      local_a4 = 0x80;
      uStack_a0 = 0;
      local_9c = 0;
      local_9b = 0;
      local_9a[0] = 0;
      FUN_600d37ac(&local_a8,DAT_6007fdac);
      local_b8[0] = bVar4;
      uVar7 = FUN_600cbb14(local_b8);
      FUN_60101b76(&local_a8,uVar7);
      FUN_601016f0(0x1e,local_b0,local_ac,&local_a8);
    }
  }
  return local_b4;
}


