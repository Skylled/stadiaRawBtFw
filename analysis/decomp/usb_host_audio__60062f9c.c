// 60062f9c  usb_host_audio__60062f9c  size=450 bytes
// src: usb_host_audio.cc
// --- callers ---
//   6006318c usb_host_audio__6006318c
// --- callees ---
//   600dffe8 FUN_600dffe8
//   6013d0e8 thunk_EXT_FUN_00006a74
//   60055a28 FUN_60055a28
//   6010165c FUN_6010165c
//   6013d158 thunk_EXT_FUN_00001ae4
//   60062c70 usb_host_audio__60062c70
//   6013d268 thunk_EXT_FUN_00006d2c
//   60055a7c FUN_60055a7c
//   600d57ba FUN_600d57ba
//   60062ba4 usb_host_audio__60062ba4


/* src: usb_host_audio.cc */

void usb_host_audio__60062f9c(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 local_2c;
  int local_28;
  int local_24;
  
  iVar3 = FUN_600dffe8(param_1 + 8,0xe);
  uVar2 = DAT_60063188;
  uVar1 = DAT_60063160;
  if ((iVar3 != 0) && ((char)param_2[7] != '\0')) {
LAB_60062fbe:
    uVar6 = DAT_60063164;
    if (*(byte *)(param_2 + 0x9a) < 5) {
      do {
        do {
          if (((uint)param_2[5] <= (uint)(param_2[199] - param_2[200])) ||
             (iVar3 = thunk_EXT_FUN_00006d2c(param_2[0xb1],param_2 + 0xc6,0), iVar3 != 1)) {
            if ((uint)(param_2[199] - param_2[200]) < (uint)param_2[5]) goto LAB_60062fec;
            iVar3 = param_2[0xc6] + param_2[200];
            if ((char)param_2[0x102] != '\0') {
              uVar6 = DAT_60063174;
              if (*param_2 == 0) {
                uVar6 = DAT_60063170;
              }
              thunk_EXT_FUN_00001ae4(0xc,iVar3,4,0,uVar1,0,uVar6);
            }
            iVar5 = param_2[200] + param_2[5];
            param_2[200] = iVar5;
            if ((uint)(param_2[199] - iVar5) < (uint)param_2[5]) {
              local_2c = 1;
              local_24 = param_2[0xc6];
              local_28 = iVar3;
              thunk_EXT_FUN_00006a74(param_2[0xdd],&local_2c,0xffffffff);
              FUN_600d57ba(param_2 + 0xff);
            }
            *(char *)(param_2 + 0x9a) = (char)param_2[0x9a] + '\x01';
            FUN_600d57ba(param_2 + 0x101);
            if (*param_2 == 0) {
              iVar3 = FUN_60055a7c(param_2[8],iVar3,param_2[5],DAT_60063178);
              if (iVar3 == 0) goto LAB_60062fbe;
              uVar4 = 0x4d9;
              uVar6 = DAT_6006317c;
            }
            else {
              iVar3 = FUN_60055a28(param_2[8],iVar3,param_2[5],DAT_60063180,param_1);
              if (iVar3 == 0) goto LAB_60062fbe;
              uVar4 = 0x4e2;
              uVar6 = DAT_60063184;
            }
            FUN_6010165c(0x1e,DAT_60063164,uVar4,uVar6);
            goto LAB_60062fbe;
          }
          if ((uint)param_2[199] < (uint)param_2[5]) {
            FUN_6010165c(0x28,uVar6,0x4b5,uVar2);
          }
          param_2[200] = 0;
        } while ((char)param_2[0x102] == '\0');
        uVar4 = DAT_6006316c;
        if (*param_2 == 0) {
          uVar4 = DAT_60063168;
        }
        thunk_EXT_FUN_00001ae4(0xc,param_2[0xc6],4,0,uVar1,0,uVar4);
      } while( true );
    }
LAB_60062fec:
    piVar7 = param_2 + 8;
    DataMemoryBarrier(0x1b);
    *(undefined1 *)((int)param_2 + 0x269) = 0;
    DataMemoryBarrier(0x1b);
    usb_host_audio__60062ba4(param_1,piVar7,param_2 + 0x26);
    usb_host_audio__60062c70(param_1,piVar7,param_2 + 0x6e);
    usb_host_audio__60062ba4(param_1,piVar7,param_2 + 0x3f);
    usb_host_audio__60062c70(param_1,piVar7,param_2 + 0x84);
    usb_host_audio__60062ba4(param_1,piVar7,param_2 + 0xd);
    usb_host_audio__60062c70(param_1,piVar7,param_2 + 0x58);
  }
  return;
}


