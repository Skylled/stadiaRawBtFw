// 60063e24  usb_host_audio_topology__60063e24  size=596 bytes
// src: usb_host_audio_topology.cc
// --- callers ---
//   600d6052 FUN_600d6052
// --- callees ---
//   600d5fc2 FUN_600d5fc2
//   600d5e14 FUN_600d5e14
//   600d19ea FUN_600d19ea
//   600d5cbe FUN_600d5cbe
//   600d5dc4 FUN_600d5dc4
//   60101d4e FUN_60101d4e
//   600d6028 FUN_600d6028
//   60063dec FUN_60063dec
//   600d5fd2 FUN_600d5fd2
//   60063cf4 usb_host_audio_topology__60063cf4
//   60063c58 FUN_60063c58
//   600615bc FUN_600615bc
//   600d5e24 FUN_600d5e24
//   600d5c16 FUN_600d5c16
//   6013d378 thunk_EXT_FUN_0000b532
//   600d4fc4 FUN_600d4fc4
//   60063be8 FUN_60063be8
//   6013d310 thunk_EXT_FUN_0000b52a
//   60101d4a thunk_FUN_60101ccc
//   6010165c FUN_6010165c


/* src: usb_host_audio_topology.cc */

undefined4 usb_host_audio_topology__60063e24(int param_1,int param_2)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  uint uVar12;
  undefined1 *puVar13;
  undefined1 local_34;
  undefined1 local_33;
  ushort local_32;
  int local_30;
  int local_2c [3];
  
  local_30 = 0;
  FUN_600d5dc4(local_2c,param_1,1);
  FUN_600d5fd2(param_1 + 0x60,local_2c);
  FUN_600d5fc2(local_2c);
  if (*(int *)(param_1 + 100) - *(int *)(param_1 + 0x60) <= param_2) {
    return 0xb;
  }
  FUN_600d5dc4(local_2c,param_1,2);
  FUN_600d5fd2(param_1 + 0x6c,local_2c);
  FUN_600d5fc2(local_2c);
  if (*(int *)(param_1 + 0x6c) != *(int *)(param_1 + 0x70)) {
    iVar8 = *(int *)(param_1 + 0x5c);
    uVar12 = (uint)*(byte *)(*(int *)(param_1 + 0x60) + param_2);
    iVar3 = FUN_600d19ea(iVar8 + uVar12 * 0x40,0,&local_30,&local_32);
    if (((iVar3 != 0) || (local_32 == 0)) || (local_30 == 0)) {
      uVar4 = FUN_600615bc(iVar3);
      FUN_6010165c(0x28,DAT_60064078,0x2fd,DAT_6006407c,uVar4,local_32,local_30);
      uVar4 = FUN_600d4fc4(iVar3);
      return uVar4;
    }
    bVar1 = *(byte *)(*(int *)(iVar8 + uVar12 * 0x40 + 0x30) + 7);
    uVar12 = bVar1 & 0xdf;
    *(byte *)(param_1 + 0x79) = bVar1;
    if ((bVar1 & 0xdf) == 0) {
      do {
        while( true ) {
          do {
            uVar4 = DAT_60064088;
            iVar3 = *(int *)(param_1 + 0x54);
            iVar8 = iVar3 + 4;
            if (local_32 - 4 <= uVar12) {
              local_2c[0] = *(int *)(iVar3 + 0xc);
              do {
                iVar3 = local_2c[0];
                if (local_2c[0] == iVar8) {
                  *(undefined1 *)(param_1 + 0x78) = 1;
                  FUN_600d5e24(param_1);
                  return 0;
                }
                iVar6 = local_2c[0] + 0x14;
                iVar9 = FUN_600d5c16(iVar6);
                if ((iVar9 == 0) && (iVar9 = FUN_600d5cbe(iVar6), iVar9 == 0)) {
                  if (*(int *)(iVar3 + 0x28) == *(int *)(iVar3 + 0x2c)) {
                    FUN_6010165c(0x28,DAT_60064078,0x31e,uVar4,*(undefined1 *)(iVar3 + 0x10));
                  }
                  puVar13 = *(undefined1 **)(iVar3 + 0x2c);
                  puVar11 = *(undefined1 **)(iVar3 + 0x28);
                  while (puVar13 != puVar11) {
                    local_34 = *puVar11;
                    iVar9 = FUN_600d6028(*(undefined4 *)(param_1 + 0x54),&local_34);
                    uVar2 = *(undefined1 *)(iVar3 + 0x10);
                    if (*(int *)(param_1 + 0x54) + 4 == iVar9) {
                      FUN_6010165c(0x28,DAT_60064078,0x324,DAT_60064084,local_34,uVar2);
                      return 2;
                    }
                    iVar9 = FUN_60063dec(*(int *)(param_1 + 0x54),&local_34);
                    local_33 = uVar2;
                    FUN_60063c58(iVar9 + 8,&local_33);
                    puVar11 = puVar11 + 1;
                  }
                }
                FUN_600d5e14(local_2c);
              } while( true );
            }
            iVar9 = local_30 + uVar12;
            uVar12 = uVar12 + *(byte *)(local_30 + uVar12) & 0xffff;
          } while ((*(char *)(iVar9 + 1) != '$') ||
                  (iVar6 = FUN_60063be8(*(undefined1 *)(iVar9 + 2),*(undefined1 *)(param_1 + 0x79)),
                  iVar6 == 0));
          iVar7 = thunk_EXT_FUN_0000b532(0x34);
          *(undefined1 *)(iVar7 + 0x10) = *(undefined1 *)(iVar9 + 3);
          usb_host_audio_topology__60063cf4(iVar7 + 0x14,*(undefined1 *)(param_1 + 0x79),iVar9);
          iVar9 = iVar6;
          iVar5 = *(int *)(iVar3 + 8);
          iVar10 = iVar8;
          while (iVar5 != 0) {
            iVar10 = iVar5;
            if (*(byte *)(iVar7 + 0x10) < *(byte *)(iVar5 + 0x10)) {
              iVar9 = iVar6;
              iVar5 = *(int *)(iVar5 + 8);
            }
            else {
              iVar9 = 0;
              iVar5 = *(int *)(iVar5 + 0xc);
            }
          }
          iVar5 = iVar10;
          if (iVar9 != 0) break;
LAB_60063f0a:
          if (*(byte *)(iVar5 + 0x10) < *(byte *)(iVar7 + 0x10)) goto LAB_60063f12;
LAB_60063fb2:
          FUN_600d5fc2(iVar7 + 0x28);
          FUN_600d5fc2(iVar7 + 0x1c);
          thunk_EXT_FUN_0000b52a(iVar7);
        }
        if (*(int *)(iVar3 + 0xc) != iVar10) {
          iVar5 = thunk_FUN_60101ccc(iVar10);
          goto LAB_60063f0a;
        }
LAB_60063f12:
        if (iVar10 == 0) goto LAB_60063fb2;
        if (iVar10 != iVar8) {
          if (*(byte *)(iVar7 + 0x10) < *(byte *)(iVar10 + 0x10)) {
            iVar6 = 1;
          }
          else {
            iVar6 = 0;
          }
        }
        FUN_60101d4e(iVar6,iVar7,iVar10,iVar8);
        *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + 1;
      } while( true );
    }
    FUN_6010165c(0x28,DAT_60064078,0x303,DAT_60064080,(uint)bVar1);
  }
  return 2;
}


