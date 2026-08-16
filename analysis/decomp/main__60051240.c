// 60051240  main__60051240  size=1032 bytes
// src: main.cc
// src: pattern_player.h
// --- callers ---
// --- callees ---
//   600d4596 led_calibration__600d4596
//   60066070 keys__60066070
//   60065db0 FUN_60065db0
//   60059f98 reboot_reason__60059f98
//   6013d0b0 thunk_EXT_FUN_00001ea4
//   600d7d1c FUN_600d7d1c
//   6005d634 thermal__6005d634
//   6005a6b0 device_info__6005a6b0
//   6005bdac FUN_6005bdac
//   60101b76 FUN_60101b76
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   600d7cc4 FUN_600d7cc4
//   60050c18 FUN_60050c18
//   600ce26a FUN_600ce26a
//   60076400 FUN_60076400
//   60077138 FUN_60077138
//   6013cef8 thunk_EXT_FUN_0000737c
//   600ce25c FUN_600ce25c
//   6010165c FUN_6010165c
//   60065dd8 FUN_60065dd8
//   600510c0 FUN_600510c0
//   60051120 FUN_60051120
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   60071884 FUN_60071884
//   6013cf80 thunk_EXT_FUN_0000714c
//   6007f870 FUN_6007f870
//   6013cf40 thunk_EXT_FUN_00007d10
//   600d6e14 FUN_600d6e14
//   600d5150 FUN_600d5150
//   601016f0 FUN_601016f0
//   6010177a FUN_6010177a
//   60101ba2 FUN_60101ba2
//   6006855c battery_charger_bq25601__6006855c
//   600ce24c FUN_600ce24c
//   600678d4 FUN_600678d4
//   600ce2c6 FUN_600ce2c6
//   6006b02c led_driver_lp5562__6006b02c
//   600670f4 gotham_patterns__600670f4
//   60077140 FUN_60077140
//   60101198 FUN_60101198


/* src: main.cc
   src: pattern_player.h */

void main__60051240(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  undefined1 local_c0 [4];
  uint local_bc;
  byte local_b8;
  uint local_b4;
  int local_b0;
  byte *local_ac;
  int local_a8;
  uint uStack_a4;
  byte local_a0;
  byte local_9f;
  byte local_9e [134];
  
  uVar5 = DAT_60051550;
  FUN_60077138();
  FUN_60077140();
  reboot_reason__60059f98(&local_bc,1);
  uVar11 = local_bc;
  iVar3 = battery_charger_bq25601__6006855c(DAT_60051554);
  if (iVar3 != 0) goto LAB_600512bc;
  if (*(char *)(uVar5 + 0x4362) == '\0') goto LAB_600512bc;
  local_c0[0] = 0x1c;
  cVar1 = thunk_EXT_FUN_00001ea4
                    (*(undefined4 *)(uVar5 + 0x4348),*(undefined1 *)(uVar5 + 0x434c),local_c0,1,
                     &local_b4,2,200);
  if (cVar1 != '\0') goto LAB_600512bc;
  if (2 < (ushort)local_b4) goto LAB_600512bc;
  uVar10 = 0xb5;
  uVar4 = 0x14;
  uVar6 = DAT_60051558;
  do {
    FUN_6010165c(uVar4,DAT_6005155c,uVar10,uVar6);
    thunk_EXT_FUN_0000737c(0x32);
    FUN_600510c0();
LAB_600512bc:
    iVar3 = FUN_600d5150(DAT_60051560);
    if (iVar3 != 0) {
      uVar4 = 0xb9;
      uVar6 = DAT_60051564;
LAB_600512cc:
      FUN_6010165c(0x14,DAT_6005155c,uVar4,uVar6);
switchD_600513e6_caseD_1:
      iVar3 = FUN_6007f870();
      thunk_EXT_FUN_0000b4c2();
      FUN_6010165c(0x14,DAT_6005156c,0x5e,DAT_60051568);
      *(undefined1 *)(iVar3 + 300) = 1;
      thunk_EXT_FUN_00007d10(iVar3);
      goto LAB_600512f6;
    }
    switch(uVar11) {
    case 0:
      iVar3 = FUN_600ce24c(DAT_600515a4);
      if ((iVar3 != 0) || (*(int *)(uVar5 + 0x4328) == 2)) {
        iVar3 = battery_charger_bq25601__6006855c(DAT_60051554);
        if (iVar3 == 0) goto switchD_600513e6_default;
        uVar4 = 0xc4;
        uVar6 = DAT_600515b4;
        goto LAB_600514c6;
      }
      uVar11 = 1000;
      uVar5 = thunk_EXT_FUN_0000714c();
      iVar3 = DAT_6005159c;
      iVar7 = DAT_6005159c + -0x3c;
      uVar5 = ((uVar5 % 1000) * 1000 + 500) / 1000 + (uVar5 / 1000) * 1000;
      uVar12 = 0;
      while( true ) {
        if (0x179 < uVar5) {
          if (uVar12 < 100) {
            FUN_6010165c(10,DAT_6005155c,0xa5,DAT_600515ac);
            FUN_600678d4();
          }
          uVar4 = 0xc1;
          uVar6 = DAT_600515b0;
          goto LAB_600514aa;
        }
        iVar8 = FUN_600ce24c(iVar3);
        if (iVar8 != 0) break;
        iVar8 = FUN_600ce24c(iVar7);
        if (iVar8 != 0) {
          uVar12 = uVar12 + 5;
        }
        uVar5 = 0x17a - uVar5;
        if (4 < uVar5) {
          uVar5 = 5;
        }
        thunk_EXT_FUN_0000737c(uVar5);
        uVar5 = thunk_EXT_FUN_0000714c();
        uVar5 = ((uVar5 % 1000) * 1000 + 500) / 1000 + (uVar5 / 1000) * 1000;
      }
      uVar10 = 0x96;
      uVar6 = DAT_600515a8;
      break;
    case 1:
      goto switchD_600513e6_caseD_1;
    case 2:
    case 3:
    case 5:
      if (local_b8 != 0) {
        uVar4 = 0xd6;
        uVar6 = DAT_600515c8;
        goto LAB_600512cc;
      }
      local_b4 = DAT_60051708;
      local_a0 = local_b8;
      local_b0 = 0xd9;
      local_ac = local_9e;
      local_9f = local_b8;
      local_9e[0] = local_b8;
      local_a8 = 0x80;
      uStack_a4 = (uint)local_b8;
      FUN_60101b76(&local_ac,DAT_6005170c);
      iVar3 = 7;
      uVar6 = FUN_60050c18(uVar11,0,local_ac + uStack_a4,local_a8 - uStack_a4);
      FUN_60101ba2(&local_ac,uVar6);
      FUN_601016f0(0x14,local_b4,local_b0,&local_ac);
      goto LAB_600514d0;
    case 4:
      iVar3 = 5;
      goto LAB_600514d0;
    case 6:
      iVar3 = battery_charger_bq25601__6006855c(DAT_60051554);
      if (iVar3 != 0) {
        uVar4 = 0xce;
        uVar6 = DAT_600515c4;
LAB_600514c6:
        iVar3 = 4;
        FUN_6010165c(0x14,DAT_6005155c,uVar4,uVar6);
LAB_600514d0:
        led_driver_lp5562__6006b02c(DAT_600515b8);
        uVar5 = led_calibration__600d4596();
        if ((uVar5 & 0xff) != 0) {
          FUN_60051120(&local_b4,DAT_6005155c,0xec,uVar5);
          FUN_60101b76(&local_ac,DAT_600515bc);
          FUN_601016f0(0x28,local_b4,local_b0,&local_ac);
        }
        if (iVar3 - 1U < 7) {
          (**(code **)(&DAT_60051510 + (iVar3 - 1U) * 4))();
          return;
        }
        uVar6 = FUN_6007f870();
        uVar4 = gotham_patterns__600670f4(0xb);
        local_b0 = 0;
        local_b4 = DAT_60051718;
        FUN_600ce26a(uVar6,6,uVar4,DAT_60051718,0);
LAB_600512f6:
        uVar5 = thermal__6005d634();
        if ((uVar5 & 0xff) != 0) {
          FUN_60051120(&local_b4,DAT_6005155c,0x11c,uVar5);
          FUN_60101b76(&local_ac,DAT_60051570);
          FUN_601016f0(0x28,local_b4,local_b0,&local_ac);
        }
        uVar4 = *(undefined4 *)(DAT_60051574 + 4);
        uVar6 = thunk_EXT_FUN_0000714c();
        thunk_EXT_FUN_00007a2c(uVar4,1,uVar6,0,10);
        FUN_60071884(DAT_60051550);
        iVar3 = FUN_600d7cc4();
        if (((iVar3 != 0) && (iVar3 = FUN_600ce25c(DAT_60051578), iVar3 != 0)) &&
           (iVar3 = FUN_600ce25c(DAT_6005157c), iVar3 != 0)) {
          iVar3 = FUN_600ce25c(DAT_60051580);
          iVar7 = FUN_600ce25c(DAT_60051584);
          iVar8 = FUN_600ce25c(DAT_60051588);
          iVar9 = FUN_600ce25c(DAT_6005158c);
          if (iVar9 + iVar3 + iVar7 + iVar8 < 2) {
            iVar3 = FUN_600ce25c(DAT_6005171c);
            if (((iVar3 == 0) && (iVar3 = FUN_600ce25c(DAT_60051720), iVar3 == 0)) &&
               (iVar7 = FUN_600ce25c(DAT_60051724), iVar7 != 0)) {
              uVar6 = FUN_6007f870();
              uVar4 = gotham_patterns__600670f4(0x25);
              local_b4 = DAT_60051718;
              local_b0 = iVar3;
              FUN_600ce26a(uVar6,4,uVar4,DAT_60051718,0);
              iVar3 = FUN_600d6e14(0x2b);
              if (iVar3 == 0) {
                cVar1 = keys__60066070(0x2b,&local_bc,1);
              }
              else {
                cVar1 = FUN_600ce2c6(0x2b,&local_bc);
              }
              if (cVar1 == '\0') {
                local_b4 = local_bc & 0xff ^ 1;
                uVar6 = FUN_60065db0(0x2b);
                uVar4 = FUN_60065dd8(0x2b);
                FUN_60101198(uVar6,uVar4,&local_b4,4);
                uVar2 = FUN_600d7d1c();
                DataMemoryBarrier(0x1b);
                *DAT_60051728 = uVar2;
                DataMemoryBarrier(0x1b);
              }
            }
          }
          else {
            FUN_6010165c(0x28,DAT_6005155c,0x7b,DAT_60051590);
          }
        }
        cVar1 = device_info__6005a6b0();
        if (cVar1 != '\0') {
          FUN_6010165c(0x1e,DAT_6005155c,300,DAT_60051594);
        }
        uVar6 = FUN_6005bdac();
        FUN_6010177a(uVar6,DAT_60051598,7);
        iVar3 = FUN_600ce24c(DAT_6005159c);
        if (iVar3 == 0) {
          iVar3 = FUN_60076400();
          *(undefined4 *)(iVar3 + 0x408) = 0;
          *(undefined1 *)(iVar3 + 0x411) = 1;
          *(undefined4 *)(iVar3 + 0x404) = 1000;
        }
        uVar6 = FUN_60076400();
        FUN_6010177a(uVar6,DAT_600515a0,0xd);
        return;
      }
      uVar10 = 0xca;
      uVar6 = DAT_600515c0;
      break;
    case 7:
      uVar4 = 0xdc;
      uVar6 = DAT_60051710;
LAB_600514aa:
      FUN_6010165c(0x14,DAT_6005155c,uVar4,uVar6);
      iVar3 = 3;
      goto LAB_600514d0;
    default:
switchD_600513e6_default:
      FUN_6010165c(0x28,DAT_60051708,0xe1,DAT_60051714);
      iVar3 = 0;
      goto LAB_600514d0;
    }
    uVar4 = 0x1e;
  } while( true );
}


