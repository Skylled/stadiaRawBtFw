// 6006f660  gotham_16mb_mimxrt10xx_mpu__6006f660  size=132 bytes
// src: gotham_16mb_mimxrt10xx_mpu.cc
// --- callers ---
//   600cb030 mpu__600cb030
// --- callees ---
//   60101b76 FUN_60101b76
//   60101740 FUN_60101740


/* WARNING: Type propagation algorithm not settling */
/* src: gotham_16mb_mimxrt10xx_mpu.cc */

undefined4 gotham_16mb_mimxrt10xx_mpu__6006f660(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int local_b0 [5];
  uint local_9c;
  undefined1 auStack_9a [2];
  int iStack_98;
  int iStack_94;
  int local_90;
  int iStack_8c;
  int iStack_88;
  int iStack_84;
  int local_80;
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  
  if (param_2 == 0) {
    uVar5 = 0;
  }
  else {
    local_b0[0] = *DAT_6006f6e4;
    local_b0[1] = DAT_6006f6e4[1];
    local_b0[2] = DAT_6006f6e4[2];
    local_b0[3] = DAT_6006f6e4[3];
    local_9c = DAT_6006f6e4[5];
    local_b0[4] = DAT_6006f6e4[4];
    iStack_98 = DAT_6006f6e4[6];
    iStack_94 = DAT_6006f6e4[7];
    local_90 = DAT_6006f6e4[8];
    iStack_8c = DAT_6006f6e4[9];
    iStack_88 = DAT_6006f6e4[10];
    iStack_84 = DAT_6006f6e4[0xb];
    local_80 = DAT_6006f6e4[0xc];
    iStack_7c = DAT_6006f6e4[0xd];
    iStack_78 = DAT_6006f6e4[0xe];
    iStack_74 = DAT_6006f6e4[0xf];
    iVar3 = 0;
    do {
      iVar4 = iVar3 + 1;
      piVar2 = (int *)(param_2 + iVar3 * 8);
      iVar1 = local_b0[iVar3 * 2 + 1];
      *piVar2 = local_b0[iVar3 * 2];
      piVar2[1] = iVar1;
      iVar3 = iVar4;
    } while (iVar4 != 8);
    if (param_1[1] == 0) {
      *param_1 = 8;
      param_1[1] = 9;
    }
    uVar5 = 8;
    if (0xf < (uint)param_1[1]) {
      local_b0[0] = DAT_6006f6e8;
      local_b0[1] = 0xbb;
      local_b0[2] = (int)auStack_9a;
      local_b0[3] = 0x80;
      local_b0[4] = 0;
      local_9c = local_9c & 0xff000000;
      FUN_60101b76(local_b0 + 2,DAT_6006f6ec);
      FUN_60101740(local_b0);
    }
  }
  return uVar5;
}


