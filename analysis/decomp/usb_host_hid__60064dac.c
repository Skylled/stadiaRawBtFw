// 60064dac  usb_host_hid__60064dac  size=494 bytes
// src: usb_host_hid.cc
// --- callers ---
//   60062674 usb_host__60062674
//   600626e4 usb_host__600626e4
// --- callees ---
//   600d33b2 FUN_600d33b2
//   600d68ba FUN_600d68ba
//   600d68fe FUN_600d68fe
//   6006525c usb_host_worker__6006525c
//   6010165c FUN_6010165c


/* src: usb_host_hid.cc */

undefined4 usb_host_hid__60064dac(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  uint local_30;
  uint local_2c;
  int iStack_28;
  
  iVar1 = DAT_60064f9c;
  local_30 = param_1;
  local_2c = param_2;
  iStack_28 = param_3;
  if (param_3 == 2) {
    FUN_6010165c(0x14,DAT_60064fbc,0x395,DAT_60064fb8);
    FUN_600d68fe(iVar1,6);
    *(undefined2 *)(iVar1 + 0x100) = 0;
    *(undefined2 *)(iVar1 + 0x102) = 0;
    FUN_600d68ba(iVar1);
  }
  else {
    if (param_3 != 3) {
      if (param_3 != 1) {
        return 0;
      }
      *(undefined4 *)(DAT_60064f9c + 0xf0) = 0;
      *(undefined1 *)(iVar1 + 0x7c) = 0;
      *(undefined4 *)(iVar1 + 0x2ac) = 0;
      *(undefined4 *)(iVar1 + 0x2b0) = 0;
      *(undefined4 *)(iVar1 + 0xf8) = 0;
      *(undefined4 *)(iVar1 + 0xfc) = 0;
      FUN_600d33b2(param_1,10,&local_30);
      FUN_600d33b2(param_1,0xb,&local_2c);
      iVar6 = DAT_60064fa0;
      uVar2 = local_2c & 0xffff;
      uVar4 = local_30 & 0xffff;
      iVar7 = DAT_60064fa0 + 0x20;
      *(undefined2 *)(iVar1 + 0x100) = (undefined2)local_2c;
      *(undefined2 *)(iVar1 + 0x102) = (undefined2)local_30;
      do {
        if ((*(ushort *)(iVar6 + -4) == uVar2) && (*(ushort *)(iVar6 + -2) == uVar4)) {
          if (*(char *)(param_2 + 0x40a) == '\0') {
            return 8;
          }
          if (uVar4 == 0x28e) {
            *(undefined1 *)(iVar1 + 0x7c) = 1;
            *(undefined4 *)(iVar1 + 0x2ac) = DAT_60064fa4;
            uVar5 = 3;
          }
          else {
            *(undefined1 *)(iVar1 + 0x7c) = 1;
            if (uVar4 == 0x719) {
              *(undefined4 *)(iVar1 + 0x2ac) = DAT_60064fa8;
              uVar5 = 0xc;
            }
            else {
              *(undefined4 *)(iVar1 + 0x2ac) = DAT_60064fac;
              uVar5 = 5;
            }
          }
          *(undefined4 *)(iVar1 + 0x2b0) = uVar5;
          *(uint *)(iVar1 + 0xf0) = param_1;
          *(uint *)(iVar1 + 0xf8) = param_2;
          goto LAB_60064e4a;
        }
        bVar8 = iVar6 != iVar7;
        iVar6 = iVar6 + 4;
      } while (bVar8);
      iVar6 = DAT_60064fc0;
      while ((*(ushort *)(iVar6 + -4) != uVar2 || (*(ushort *)(iVar6 + -2) != uVar4))) {
        bVar8 = iVar6 == DAT_60064fc0 + 0x1c;
        iVar6 = iVar6 + 4;
        if (bVar8) {
          return 8;
        }
      }
      uVar3 = 0;
      while( true ) {
        if (*(byte *)(param_2 + 0x40a) <= uVar3) {
          return 8;
        }
        iVar6 = *(int *)(param_2 + uVar3 * 0x40 + 0x30);
        if (((*(char *)(iVar6 + 5) == '\x03') && (*(byte *)(iVar6 + 6) < 2)) &&
           (*(byte *)(iVar6 + 7) < 3)) break;
LAB_60064e88:
        uVar3 = uVar3 + 1;
      }
      if (uVar2 == 0x54c) {
        if (uVar4 != 0x268) goto LAB_60064ed4;
        *(undefined1 *)(iVar1 + 0x7c) = 1;
        *(undefined4 *)(iVar1 + 0x2ac) = DAT_60064fb0;
        uVar5 = 4;
      }
      else {
        if (uVar2 == 0x28de) {
          if (uVar4 == 0x1102) {
            if (uVar3 == 2) goto LAB_60064ed4;
          }
          else if ((uVar4 != 0x1142) || (uVar3 != 0)) goto LAB_60064ed4;
          goto LAB_60064e88;
        }
        if ((uVar2 != 0x57e) || (uVar4 != 0x2009)) goto LAB_60064ed4;
        *(undefined1 *)(iVar1 + 0x7c) = 1;
        *(undefined4 *)(iVar1 + 0x2ac) = DAT_60064fb4;
        uVar5 = 2;
      }
      *(undefined4 *)(iVar1 + 0x2b0) = uVar5;
LAB_60064ed4:
      *(uint *)(iVar1 + 0xf0) = param_1;
      *(uint *)(iVar1 + 0xf8) = uVar3 * 0x40 + param_2;
LAB_60064e4a:
      *(uint *)(iVar1 + 0xfc) = param_2;
      return 0;
    }
    if (*(int *)(DAT_60064f9c + 0xf0) == 0) {
      return 3;
    }
    if (*(int *)(DAT_60064f9c + 0xf8) == 0) {
      return 3;
    }
    if (*(int *)(DAT_60064f9c + 0xfc) == 0) {
      return 3;
    }
    usb_host_worker__6006525c();
    FUN_600d68fe(iVar1,0);
  }
  return 0;
}


