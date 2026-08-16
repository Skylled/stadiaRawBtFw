// 60067c3c  gotham__60067c3c  size=196 bytes
// src: gotham.cc
// --- callers ---
// --- callees ---
//   600d37b8 FUN_600d37b8
//   600cc984 FUN_600cc984
//   6013cf80 thunk_EXT_FUN_0000714c
//   600e02f8 FUN_600e02f8
//   600cc8f8 FUN_600cc8f8
//   6010165c FUN_6010165c
//   60101b76 FUN_60101b76
//   600d3ae6 FUN_600d3ae6


/* src: gotham.cc */

undefined4 gotham__60067c3c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [134];
  
  piVar4 = (int *)FUN_600e02f8();
  if (piVar4 == (int *)0x0) {
    FUN_6010165c(0x28,DAT_60067d04,0x32,DAT_60067d00);
  }
  else {
    local_b4 = 0;
    uVar5 = (**(code **)(*piVar4 + 0x10))(piVar4,param_2,param_3,&local_b4);
    puVar3 = DAT_60067d0c;
    pbVar2 = DAT_60067d08;
    if ((uVar5 & 0xff) == 0) {
      return local_b4;
    }
    bVar1 = *DAT_60067d08;
    DataMemoryBarrier(0x1b);
    if (((bVar1 & 1) == 0) && (iVar6 = FUN_600cc8f8(DAT_60067d08), iVar6 != 0)) {
      *puVar3 = bVar1 & 1;
      FUN_600cc984(pbVar2);
    }
    uVar7 = thunk_EXT_FUN_0000714c();
    uVar7 = ((uVar7 % 1000) * 1000 + 500) / 1000 + (uVar7 / 1000) * 1000;
    if (*puVar3 + 5000 <= uVar7) {
      *puVar3 = uVar7;
      local_b0 = DAT_60067d04;
      local_ac = 0x39;
      local_a8 = local_9a;
      local_a4 = 0x80;
      uStack_a0 = 0;
      local_9c = 0;
      local_9b = 0;
      local_9a[0] = 0;
      FUN_60101b76(&local_a8,DAT_60067d10);
      FUN_600d3ae6(&local_a8,uVar5);
      FUN_600d37b8(&local_b0);
    }
  }
  return 0xffffffff;
}


