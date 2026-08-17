// 60065a74  ble_info__60065a74  size=260 bytes
// src: ble_info.cc
// --- callers ---
//   600d6d8e FUN_600d6d8e
//   60065b84 ble_info__60065b84
// --- callees ---
//   60065df0 keys__60065df0
//   60065eb8 keys__60065eb8
//   60065a48 FUN_60065a48
//   6010165c FUN_6010165c
//   6004cb28 FUN_6004cb28


/* src: ble_info.cc */

uint ble_info__60065a74(undefined4 param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  ushort uVar5;
  undefined4 uVar6;
  short sVar7;
  undefined4 uVar8;
  short local_5e;
  char *local_5c;
  undefined1 auStack_58 [2];
  char local_56 [18];
  char **local_44 [12];
  
  uVar2 = keys__60065df0(param_1,&local_5e);
  if ((uVar2 & 0xff) == 0) {
    if (local_5e == 0x11) {
      bVar1 = keys__60065eb8(param_1,auStack_58,0x12);
      uVar2 = (uint)bVar1;
      if (uVar2 == 0) {
        iVar3 = FUN_6004cb28(auStack_58);
        if (iVar3 == 0x11) {
          local_5c = local_56;
          iVar3 = 0;
          while( true ) {
            bVar1 = local_5c[-2];
            uVar2 = (uint)bVar1;
            sVar7 = (short)(uVar2 - 0x30);
            if (9 < (uVar2 - 0x30 & 0xff)) {
              if (uVar2 - 0x41 < 6) {
                sVar7 = bVar1 - 0x37;
              }
              else if (uVar2 - 0x61 < 6) {
                sVar7 = bVar1 - 0x57;
              }
              else {
                sVar7 = 0x100;
              }
            }
            bVar1 = local_5c[-1];
            uVar2 = (uint)bVar1;
            if ((uVar2 - 0x30 & 0xff) < 10) {
              uVar5 = (ushort)(uVar2 - 0x30);
            }
            else if (uVar2 - 0x41 < 6) {
              uVar5 = bVar1 - 0x37;
            }
            else if (uVar2 - 0x61 < 6) {
              uVar5 = bVar1 - 0x57;
            }
            else {
              uVar5 = 0x100;
            }
            uVar5 = sVar7 << 4 | uVar5;
            if (0xff < (short)uVar5) {
              local_44[0] = &local_5c;
              local_5c = local_5c + -2;
              uVar4 = FUN_60065a48(local_44);
              uVar6 = 0x22;
              uVar8 = DAT_60065b78;
              goto LAB_60065b40;
            }
            *(char *)(param_2 + iVar3) = (char)uVar5;
            iVar3 = iVar3 + 1;
            if (iVar3 == 6) {
              return 0;
            }
            if (*local_5c != ':') break;
            local_5c = local_5c + 3;
          }
          local_44[0] = &local_5c;
          uVar4 = FUN_60065a48(local_44);
          uVar6 = 0x1f;
          uVar8 = DAT_60065b7c;
LAB_60065b40:
          FUN_6010165c(0x14,DAT_60065b80,uVar6,uVar8,uVar4);
        }
        uVar2 = 3;
      }
    }
    else {
      uVar2 = 9;
    }
  }
  return uVar2;
}


