// 60067b50  gotham__60067b50  size=210 bytes
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

int gotham__60067b50(undefined4 param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  uint *puVar2;
  byte *pbVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 local_b0;
  int local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [130];
  
  piVar4 = (int *)FUN_600e02f8();
  if (piVar4 == (int *)0x0) {
    uVar8 = 0x17;
    uVar9 = DAT_60067c24;
  }
  else {
    if (-1 < param_3) {
      local_b0 = param_2;
      local_ac = param_3;
      uVar5 = (**(code **)(*piVar4 + 0xc))(piVar4,param_2,param_3);
      pbVar3 = DAT_60067c38;
      puVar2 = DAT_60067c30;
      if ((uVar5 & 0xff) == 0) {
        return param_3;
      }
      bVar1 = *DAT_60067c38;
      DataMemoryBarrier(0x1b);
      if (((bVar1 & 1) == 0) && (iVar6 = FUN_600cc8f8(DAT_60067c38), iVar6 != 0)) {
        *puVar2 = bVar1 & 1;
        FUN_600cc984(pbVar3);
      }
      uVar7 = thunk_EXT_FUN_0000714c();
      uVar7 = ((uVar7 % 1000) * 1000 + 500) / 1000 + (uVar7 / 1000) * 1000;
      if (uVar7 < *puVar2 + 5000) {
        return -1;
      }
      *puVar2 = uVar7;
      local_b0 = DAT_60067c28;
      local_ac = 0x24;
      local_a8 = local_9a;
      local_a4 = 0x80;
      uStack_a0 = 0;
      local_9c = 0;
      local_9b = 0;
      local_9a[0] = 0;
      FUN_60101b76(&local_a8,DAT_60067c34);
      FUN_600d3ae6(&local_a8,uVar5);
      FUN_600d37b8(&local_b0);
      return -1;
    }
    uVar8 = 0x1c;
    uVar9 = DAT_60067c2c;
  }
  FUN_6010165c(0x28,DAT_60067c28,uVar8,uVar9);
  return -1;
}


