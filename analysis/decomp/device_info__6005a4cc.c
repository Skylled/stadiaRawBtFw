// 6005a4cc  device_info__6005a4cc  size=444 bytes
// src: device_info.cc
// --- callers ---
//   6005a6b0 device_info__6005a6b0
// --- callees ---
//   6013d378 thunk_EXT_FUN_0000b532
//   6013d238 thunk_EXT_FUN_0000b588
//   600d3b02 FUN_600d3b02
//   600d37b8 FUN_600d37b8
//   600d37ac FUN_600d37ac
//   600d3b50 FUN_600d3b50
//   600e0298 FUN_600e0298
//   6005a0ac device_info__6005a0ac
//   60050c18 FUN_60050c18
//   60101ba2 FUN_60101ba2
//   6008cbc4 FUN_6008cbc4
//   600d3b62 FUN_600d3b62
//   600e028e FUN_600e028e
//   60067d14 gotham__60067d14
//   60051120 FUN_60051120
//   6005a13c device_info__6005a13c


/* src: device_info.cc */

uint device_info__6005a4cc(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 *local_bc [2];
  int local_b4;
  int local_b0;
  int local_ac;
  byte local_24;
  
  uVar1 = FUN_6008cbc4();
  local_bc[0] = (undefined4 *)thunk_EXT_FUN_0000b532(0x14);
  uVar4 = DAT_6005a688;
  local_bc[0][1] = 0;
  iVar8 = param_1 + 0x6d;
  *local_bc[0] = uVar4;
  *(undefined1 *)(local_bc[0] + 4) = 1;
  local_bc[0][2] = uVar1;
  local_bc[0][3] = 0;
  gotham__60067d14(&local_c8,local_bc);
  FUN_600d3b50(local_bc);
  local_bc[0] = (undefined4 *)thunk_EXT_FUN_0000b532(8);
  uVar4 = DAT_6005a68c;
  local_bc[0][1] = 0;
  *local_bc[0] = uVar4;
  gotham__60067d14(&local_c4,local_bc);
  FUN_600d3b50(local_bc);
  local_bc[0] = (undefined4 *)thunk_EXT_FUN_0000b532(0x18);
  uVar4 = DAT_6005a690;
  local_bc[0][1] = 0;
  *local_bc[0] = uVar4;
  local_bc[0][4] = &local_d0;
  local_bc[0][5] = 0;
  local_bc[0][2] = 0x25;
  local_bc[0][3] = iVar8;
  gotham__60067d14(&local_c0,local_bc);
  FUN_600d3b50(local_bc);
  uVar1 = local_c4;
  uVar4 = local_c8;
  local_c4 = 0;
  local_c8 = 0;
  uVar1 = FUN_600e0298(uVar4,uVar1);
  uVar4 = local_c0;
  local_bc[0] = (undefined4 *)0x0;
  local_c0 = 0;
  local_cc = FUN_600e0298(uVar1,uVar4);
  FUN_600d3b02(local_bc);
  FUN_600d3b02(&local_c0);
  FUN_600d3b02(&local_c4);
  FUN_600d3b02(&local_c8);
  uVar2 = device_info__6005a0ac(local_cc,DAT_6005a694);
  if (((((uVar2 & 0xff) == 0) &&
       (uVar2 = device_info__6005a0ac(local_cc,DAT_6005a698), (uVar2 & 0xff) == 0)) &&
      (uVar2 = device_info__6005a0ac(local_cc,param_1 + 0x11), (uVar2 & 0xff) == 0)) &&
     ((uVar2 = device_info__6005a0ac(local_cc,DAT_6005a69c), (uVar2 & 0xff) == 0 &&
      (uVar2 = device_info__6005a13c(local_cc), (uVar2 & 0xff) == 0)))) {
    iVar3 = FUN_600e028e(local_cc);
    if (iVar3 == 1) {
      if (local_d0 == 0x20) {
        local_bc[0] = (undefined4 *)*DAT_6005a6ac;
        local_bc[1] = (undefined4 *)DAT_6005a6ac[1];
        local_b4 = DAT_6005a6ac[2];
        local_b0 = DAT_6005a6ac[3];
        local_ac = DAT_6005a6ac[4];
        iVar7 = 4;
        iVar6 = 0x24;
        iVar3 = 0x20;
        do {
          puVar5 = local_bc[iVar7];
          iVar6 = iVar6 - (int)puVar5;
          iVar3 = iVar3 - (int)puVar5;
          thunk_EXT_FUN_0000b588(iVar8 + iVar6,iVar8 + iVar3);
          iVar6 = iVar6 + -1;
          iVar7 = iVar7 + -1;
          *(undefined1 *)(param_1 + iVar6 + 0x6d) = 0x2d;
        } while (iVar7 != 0);
        *(undefined1 *)(param_1 + 0x91) = 0;
        FUN_600d3b62(iVar8,0x25);
        uVar2 = 0;
        goto LAB_6005a58a;
      }
      FUN_60051120(local_bc,DAT_6005a6a0,0xbf,0xd);
      FUN_600d37ac(&local_b4,DAT_6005a6a8);
      uVar4 = FUN_60050c18(local_d0,0,local_ac + local_b4,local_b0 - local_ac);
      FUN_60101ba2(&local_b4,uVar4);
    }
    else {
      FUN_60051120(local_bc,DAT_6005a6a0,0xbc,0xd);
      FUN_600d37ac(&local_b4,DAT_6005a6a4);
    }
    uVar2 = (uint)local_24;
    FUN_600d37b8(local_bc);
  }
LAB_6005a58a:
  FUN_600d3b02(&local_cc);
  return uVar2;
}


