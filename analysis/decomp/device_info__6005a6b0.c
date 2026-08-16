// 6005a6b0  device_info__6005a6b0  size=596 bytes
// src: device_info.cc
// --- callers ---
//   60051240 main__60051240
// --- callees ---
//   6005a4cc device_info__6005a4cc
//   6013d378 thunk_EXT_FUN_0000b532
//   60082814 FUN_60082814
//   600822e8 FUN_600822e8
//   6006615c keys__6006615c
//   600d37b8 FUN_600d37b8
//   60065b84 ble_info__60065b84
//   600d37ac FUN_600d37ac
//   6004cb28 FUN_6004cb28
//   600d3b12 FUN_600d3b12
//   6005a1b0 device_info__6005a1b0
//   600cdcc4 FUN_600cdcc4
//   600d3b24 FUN_600d3b24
//   6004cbf0 device_info__6004cbf0
//   60065eb8 keys__60065eb8
//   60065df0 keys__60065df0
//   6005a05c device_info__6005a05c
//   600d3ae6 FUN_600d3ae6
//   6005a464 dynamic_buffer__6005a464
//   6005a01c FUN_6005a01c
//   600d3b3a FUN_600d3b3a
//   60051120 FUN_60051120
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60101740 FUN_60101740


/* src: device_info.cc */

uint device_info__6005a6b0(void)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  ushort local_ca;
  char *local_c8;
  undefined4 local_c4;
  undefined4 uStack_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  uint local_b4;
  undefined4 local_b0;
  undefined1 auStack_ac [144];
  byte local_1c;
  
  iVar1 = DAT_6005a904;
  if (*(char *)(DAT_6005a904 + 0xa8) == '\0') {
    uVar7 = getProcessStackPointer();
    if ((uVar7 < *(uint *)(*DAT_6005a908 + 0x30)) ||
       (uVar7 - *(uint *)(*DAT_6005a908 + 0x30) < 0x708)) {
      local_b4 = DAT_6005a90c;
      local_b0 = 99;
      FUN_600d3b3a(auStack_ac);
      FUN_600d37ac(auStack_ac,DAT_6005a910);
      FUN_60101740(&local_b4);
    }
    uVar7 = device_info__6005a05c();
    if ((uVar7 & 0xff) != 0) {
      return uVar7;
    }
    uVar7 = keys__60065eb8(0x38,DAT_6005a914,0x15);
    if ((uVar7 & 0xff) == 0) {
      cVar2 = keys__60065eb8(0x37,DAT_6005a91c,0x15,uVar7);
      if (cVar2 == '\0') {
        ble_info__60065b84(&local_b4);
        FUN_600cdcc4(DAT_6005a924,0x15,DAT_6005a928,local_b0._1_1_,local_b0 & 0xff,local_b4 >> 0x18,
                     local_b4 >> 0x10 & 0xff,local_b4 >> 8 & 0xff,local_b4 & 0xff);
        uVar7 = device_info__6005a1b0(DAT_6005a904);
        if ((uVar7 & 0xff) == 0) {
          uVar4 = keys__60065eb8(3,DAT_6005a930,0x25,uVar7);
          uVar7 = DAT_6005a90c;
          if ((uVar4 & 0xff) != 5) {
            if ((uVar4 & 0xff) != 0) {
              local_b4 = DAT_6005a90c;
              local_b0 = 0x83;
              FUN_600d3b3a(auStack_ac);
              FUN_600d37ac(auStack_ac,DAT_6005a940);
              FUN_600d3ae6(auStack_ac,uVar4);
              FUN_600d37b8(&local_b4);
              return uVar4;
            }
LAB_6005a83c:
            local_ca = 0;
            cVar2 = keys__60065df0(4,&local_ca);
            if ((cVar2 == '\0') && (local_ca < 0x81)) {
              local_c4 = DAT_6005a944;
              local_b8 = DAT_6005a948;
              local_bc = DAT_6005a94c;
              dynamic_buffer__6005a464(&local_b4,local_ca + 1,&local_c4);
              cVar2 = keys__60065eb8(4,local_b0,local_ca + 1);
              if (cVar2 == '\0') {
                FUN_600822e8(&local_e0,local_b0,local_ca);
                local_c4 = local_e0;
                uStack_c0 = uStack_dc;
                local_bc = uStack_d8;
                local_b8 = uStack_d4;
                local_c8 = (char *)thunk_EXT_FUN_0000b532(0x20);
                uVar5 = thunk_EXT_FUN_0000b5ba(local_c8,0,0x20);
                iVar6 = FUN_60082814(&local_c4,DAT_6005a950,uVar5);
                if (((iVar6 == 0) || (*local_c8 == '\0')) || (local_c8[0x10] == '\0')) {
                  cVar2 = '\x0f';
                }
                else {
                  uVar5 = *(undefined4 *)(local_c8 + 0xc);
                  *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(local_c8 + 8);
                  *(undefined4 *)(iVar1 + 0x9c) = uVar5;
                  uVar5 = *(undefined4 *)(local_c8 + 0x1c);
                  *(undefined4 *)(iVar1 + 0xa0) = *(undefined4 *)(local_c8 + 0x18);
                  *(undefined4 *)(iVar1 + 0xa4) = uVar5;
                }
                FUN_600d3b12(&local_c8);
              }
              FUN_6005a01c(&local_b4);
              if (cVar2 != '\0') goto LAB_6005a8dc;
            }
            else {
LAB_6005a8dc:
              uVar7 = device_info__6004cbf0(DAT_6005a904);
              if ((uVar7 & 0xff) != 0) {
                FUN_60051120(&local_b4,DAT_6005a90c,0x8a,uVar7);
                uVar5 = DAT_6005a954;
                goto LAB_6005a724;
              }
            }
            *(undefined1 *)(iVar1 + 0xa8) = 1;
            goto LAB_6005a6bc;
          }
          local_b0 = 0x7c;
          local_b4 = DAT_6005a90c;
          FUN_600d3b3a(auStack_ac);
          FUN_600d37ac(auStack_ac,DAT_6005a934);
          FUN_600d3b24(&local_b4);
          cVar2 = device_info__6005a4cc(DAT_6005a904);
          if (cVar2 == '\0') {
            uVar3 = FUN_6004cb28(DAT_6005a930);
            uVar4 = keys__6006615c(3,DAT_6005a930,uVar3);
            if ((uVar4 & 0xff) == 0) goto LAB_6005a83c;
            FUN_60051120(&local_b4,uVar7,0x80,uVar4);
            uVar5 = DAT_6005a93c;
          }
          else {
            FUN_60051120(&local_b4,uVar7,0x7d);
            uVar5 = DAT_6005a938;
          }
        }
        else {
          FUN_60051120(&local_b4,DAT_6005a90c,0x73);
          uVar5 = DAT_6005a92c;
        }
      }
      else {
        FUN_60051120(&local_b4,DAT_6005a90c,0x6c);
        uVar5 = DAT_6005a920;
      }
    }
    else {
      FUN_60051120(&local_b4,DAT_6005a90c,0x68);
      uVar5 = DAT_6005a918;
    }
LAB_6005a724:
    FUN_600d37ac(auStack_ac,uVar5);
    uVar7 = (uint)local_1c;
    FUN_600d37b8(&local_b4);
  }
  else {
LAB_6005a6bc:
    uVar7 = 0;
  }
  return uVar7;
}


