// 600cbdc8  xbara__600cbdc8  size=1172 bytes
// src: xbara.h
// src: board.cc
// --- callers ---
//   60051168 main__60051168
// --- callees ---
//   6005f610 FUN_6005f610
//   60054580 FUN_60054580
//   60060594 FUN_60060594
//   60071580 board__60071580
//   60060b64 uart__60060b64
//   6005f5d4 FUN_6005f5d4
//   601016a2 FUN_601016a2
//   600d49d8 FUN_600d49d8
//   600cb030 mpu__600cb030
//   60060860 FUN_60060860
//   6005fcc0 FUN_6005fcc0
//   60071624 FUN_60071624
//   6005f9a8 FUN_6005f9a8
//   60060804 srtc__60060804
//   600717d4 FUN_600717d4
//   60071a30 board__60071a30
//   600d4724 FUN_600d4724
//   6006efd4 FUN_6006efd4
//   60060008 FUN_60060008
//   6010165c FUN_6010165c
//   6005a05c device_info__6005a05c
//   6005fe04 io_pin__6005fe04
//   6005f3e0 FUN_6005f3e0
//   600ce24c FUN_600ce24c
//   600cfb82 FUN_600cfb82
//   60054500 FUN_60054500
//   600d9b7c FUN_600d9b7c
//   600d49fc FUN_600d49fc
//   600d4d62 FUN_600d4d62
//   60071538 FUN_60071538
//   60057fe4 FUN_60057fe4
//   600604dc reset__600604dc
//   600718e8 FUN_600718e8
//   60060668 FUN_60060668
//   60061a98 hardware_timer__60061a98
//   60054718 FUN_60054718


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* src: xbara.h
   src: board.cc */

void xbara__600cbdc8(undefined4 param_1)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  uint extraout_r1;
  int *piVar5;
  int extraout_r2;
  undefined4 uVar6;
  undefined4 extraout_r3;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  int iStack_c0;
  uint uStack_bc;
  undefined1 local_b8 [20];
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  undefined1 local_80 [4];
  undefined1 local_7c [88];
  
  *DAT_600cbdd0 = param_1;
  *(uint *)(DAT_600cbdb8 + 0xc) = *(uint *)(DAT_600cbdb8 + 0xc) | 0x1000000;
  puVar1 = DAT_600cbdbc;
  DataSynchronizationBarrier(0xf);
  DAT_600cbdbc[0x3ec] = DAT_600cbdc0;
  uVar8 = DAT_600cbdc4;
  DataSynchronizationBarrier(0xf);
  *puVar1 = *puVar1 & 0xfffffffe;
  puVar1[1] = 0;
  *puVar1 = 1;
  FUN_60057fe4(&DAT_2001bca0);
  FUN_600718e8(0x200064c0);
  FUN_60054500(local_7c);
  iVar3 = FUN_60054580(0x400cc000,local_7c);
  if (iVar3 != 0) {
    FUN_6010165c(0x28,s_board_cc_601232dd,99,s_failed_to_init_trng_60123427);
  }
  iVar15 = uVar8 + 0x374;
  FUN_600cfb82(0x400cc000,local_80,4);
  FUN_60060008(uVar8);
  iVar14 = uVar8 + 0x3b0;
  mpu__600cb030();
  iVar13 = uVar8 + 0x3ec;
  uVar11 = uVar8 + 0x608;
  iVar9 = uVar8 + 0x644;
  iVar12 = uVar8 + 0x554;
  _DAT_400fc078 = _DAT_400fc078 | 0xc;
  FUN_600d9b7c(iVar15);
  FUN_600d9b7c(iVar14);
  FUN_600d9b7c(iVar13);
  local_a4 = uVar8 + 0x428;
  FUN_600d9b7c(local_a4);
  FUN_600d9b7c(uVar11);
  FUN_600d9b7c(iVar9);
  local_a0 = uVar8 + 0x4a0;
  FUN_600d9b7c(local_a0);
  local_9c = uVar8 + 0x464;
  FUN_600d9b7c(local_9c);
  local_98 = uVar8 + 0x4dc;
  FUN_600d9b7c(local_98);
  FUN_600d9b7c(uVar11);
  FUN_600d9b7c(iVar9);
  local_94 = uVar8 + 0x284;
  FUN_600d9b7c(local_94);
  local_90 = uVar8 + 0x2c0;
  FUN_600d9b7c(local_90);
  local_8c = uVar8 + 0x2fc;
  FUN_600d9b7c(local_8c);
  local_88 = uVar8 + 0x338;
  FUN_600d9b7c(local_88);
  local_84 = uVar8 + 0x518;
  FUN_600d9b7c(local_84);
  FUN_600d9b7c(iVar12);
  iVar3 = FUN_600ce24c(0x20006960);
  piVar16 = &iStack_c0;
  if ((((iVar3 == 0) && (iVar3 = FUN_600ce24c(0x20006834), piVar16 = &iStack_c0, iVar3 == 0)) &&
      (iVar3 = FUN_600ce24c(0x200068e8), piVar16 = &iStack_c0, iVar3 == 0)) &&
     ((iVar3 = FUN_600ce24c(0x200069d8), piVar16 = &iStack_c0, iVar3 == 0 &&
      (iVar3 = FUN_600ce24c(0x200068ac), piVar16 = &iStack_c0, iVar3 != 0)))) {
    reset__600604dc();
    piVar16 = (int *)local_b8;
    _DAT_0000004d = 1;
    _Reset = (uVar8 & extraout_r1) + 0x27;
    *(int *)extraout_r2 = extraout_r2;
    *(int *)(extraout_r2 + 0xdd) = extraout_r2 + 0xdd;
    _NMI = iStack_c0;
    uVar11 = uStack_bc & extraout_r1;
    uVar8 = *(uint *)(iStack_c0 + 8);
    _MasterStackPointer = extraout_r3;
    _HardFault = iVar9;
  }
  iVar3 = board__60071a30(uVar8);
  if (iVar3 == 0) {
    FUN_601016a2(DAT_60071f14,200,DAT_60071f10);
  }
  iVar3 = *(int *)(uVar8 + 0x367c);
  if (iVar3 != -1) {
    piVar5 = *(int **)(uVar8 + 0x3674);
    *piVar5 = iVar3;
    piVar5[1] = iVar3;
  }
  iVar3 = *(int *)(uVar8 + 0x3680);
  if (iVar3 != -1) {
    piVar5 = *(int **)(uVar8 + 0x3678);
    *piVar5 = iVar3;
    piVar5[1] = iVar3;
  }
  board__60071580(0,DAT_60071f18);
  uVar4 = uart__60060b64(uVar8 + 0xd70);
  board__60071580(uVar4,DAT_60071f1c);
  uVar4 = FUN_6005fcc0(uVar8 + 0xe48);
  board__60071580(uVar4,DAT_60071f20);
  uVar4 = FUN_6005fcc0(uVar8 + 0xfa8);
  board__60071580(uVar4,DAT_60071f24);
  uVar4 = FUN_6005f5d4(uVar8 + 0x1108);
  board__60071580(uVar4,DAT_60071f28);
  uVar4 = FUN_600d4d62(uVar8 + 0x110c);
  board__60071580(uVar4,DAT_60071f2c);
  uVar4 = FUN_6005f610(uVar8 + 0x1204);
  board__60071580(uVar4,DAT_60071f30);
  uVar4 = FUN_6005f610(uVar8 + 0x1244);
  board__60071580(uVar4,DAT_60071f34);
  FUN_60060594(uVar8 + 0x1284);
  FUN_60060668(uVar8 + 0x1380);
  uVar4 = FUN_600d4724(uVar8 + 0xae0);
  board__60071580(uVar4,DAT_60071f38);
  uVar4 = FUN_600d4724(uVar8 + 0xcdc);
  board__60071580(uVar4,DAT_60071f3c);
  uVar4 = DAT_60071f68;
  if (*(char *)(uVar8 + 0x147c) != '\0') {
    FUN_601016a2(DAT_60071f40,0x17,DAT_60071f44);
    uVar4 = 0;
  }
  FUN_60054718(uVar4);
  FUN_600d49fc(uVar8 + 0x1480);
  FUN_600d49d8(uVar8 + 0x7d4);
  uVar4 = FUN_6005f9a8(uVar8 + 0x36e4);
  board__60071580(uVar4,DAT_60071f48);
  FUN_600d49d8(uVar8 + 0x858);
  FUN_600d49d8(uVar8 + 0x884);
  io_pin__6005fe04(uVar8 + 0x6ac);
  iVar3 = uVar8 + 0x38b8;
  uVar4 = FUN_6005f3e0(uVar8 + 0x3684);
  board__60071580(uVar4,DAT_60071f4c);
  io_pin__6005fe04(uVar8 + 0x99c);
  FUN_6006efd4(uVar8 + 0x38d0);
  io_pin__6005fe04(uVar8 + 0xb3c);
  io_pin__6005fe04(uVar8 + 0xb78);
  io_pin__6005fe04(uVar8 + 0xbb4);
  io_pin__6005fe04(uVar8 + 0xbf0);
  io_pin__6005fe04(uVar8 + 0xc2c);
  io_pin__6005fe04(uVar8 + 0xc68);
  io_pin__6005fe04(uVar8 + 0xca4);
  io_pin__6005fe04(uVar8 + 0xd38);
  FUN_60071624(iVar15,iVar3);
  FUN_60071624(iVar14,iVar3);
  FUN_60071624(iVar13,iVar3);
  FUN_60071624(piVar16[7],iVar3);
  FUN_60071624(piVar16[9],iVar3);
  FUN_60071624(piVar16[8],iVar3);
  FUN_60071624(piVar16[10],iVar3);
  FUN_60071624(piVar16[0xf],iVar3);
  FUN_60071624(iVar12,iVar3);
  FUN_60071624(uVar11,iVar3);
  FUN_60071624(iVar9,iVar3);
  FUN_60071624(uVar8 + 0x590,iVar3);
  FUN_60071624(uVar8 + 0x5cc,iVar3);
  FUN_60071624(piVar16[0xb],iVar3);
  FUN_60071624(piVar16[0xc],iVar3);
  FUN_60071624(piVar16[0xd],iVar3);
  FUN_60071624(piVar16[0xe],iVar3);
  FUN_6006efd4(iVar3);
  iVar3 = DAT_60071f50;
  if (*(char *)(uVar8 + 0x38b4) == '\0') {
    *(undefined4 *)(DAT_60071f50 + 100) = DAT_60071f54;
    *(uint *)(iVar3 + 0x4c) = *(uint *)(iVar3 + 0x4c) & 0xfffffff7;
    *(uint *)(iVar3 + 0x38) = *(uint *)(iVar3 + 0x38) | 0x1000000;
    *(undefined1 *)(uVar8 + 0x38b4) = 1;
  }
  board__60071580(0,DAT_60071f58);
  io_pin__6005fe04(uVar8 + 0xa04);
  io_pin__6005fe04(uVar8 + 0xa30);
  io_pin__6005fe04(uVar8 + 0xa5c);
  iVar3 = DAT_60071f70;
  iVar9 = 0;
  io_pin__6005fe04(uVar8 + 0xa88);
  io_pin__6005fe04(uVar8 + 0xab4);
  do {
    puVar10 = (undefined4 *)(iVar3 + iVar9);
    iVar9 = iVar9 + 0x1c;
    piVar16[4] = 2;
    piVar16[5] = 2;
    uVar4 = puVar10[4];
    uVar6 = puVar10[5];
    uVar7 = puVar10[6];
    *piVar16 = puVar10[3];
    piVar16[1] = uVar4;
    piVar16[2] = uVar6;
    piVar16[3] = uVar7;
    FUN_60071538(piVar16 + 0x11,*puVar10,puVar10[1],puVar10[2]);
    io_pin__6005fe04(piVar16 + 0x11);
  } while (iVar9 != 0x3b8);
  srtc__60060804(uVar8 + 0x6c24);
  FUN_60060860(uVar8 + 0x6c24);
  hardware_timer__60061a98(uVar8 + 0x3888);
  uVar4 = FUN_600717d4(uVar8 + 0x4378);
  board__60071580(uVar4,DAT_60071f5c);
  cVar2 = device_info__6005a05c();
  if (cVar2 == '\0') {
    *(undefined4 *)(DAT_60071f60 + 0x3e6c) = DAT_60071f64;
  }
  else {
    FUN_6010165c(0x1e,DAT_60071f14,0x125,DAT_60071f6c);
  }
  return;
}


