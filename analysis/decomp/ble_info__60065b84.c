// 60065b84  ble_info__60065b84  size=206 bytes
// src: ble_info.cc
// --- callers ---
//   60071884 FUN_60071884
//   6005a6b0 device_info__6005a6b0
// --- callees ---
//   6006615c keys__6006615c
//   600d6d8e FUN_600d6d8e
//   60065a74 ble_info__60065a74
//   6010165c FUN_6010165c
//   60059e94 FUN_60059e94


/* src: ble_info.cc */

undefined1 * ble_info__60065b84(undefined1 *param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  byte bVar6;
  undefined4 uVar7;
  undefined4 local_34;
  undefined2 local_30;
  char acStack_2c [17];
  undefined1 local_1b;
  
  local_34 = DAT_60065c54;
  local_30 = 0xd60;
  FUN_600d6d8e(&local_34);
  cVar2 = ble_info__60065a74(0x25,&local_34);
  if (cVar2 != '\0') {
    FUN_6010165c(0x14,DAT_60065c5c,0x5c,DAT_60065c58);
    cVar2 = FUN_60059e94(&local_34,6);
    if (cVar2 == '\0') {
      local_34 = local_34 | 0xc0;
      iVar3 = 0;
      pcVar4 = acStack_2c;
      do {
        bVar6 = *(byte *)((int)&local_34 + iVar3);
        iVar3 = iVar3 + 1;
        pcVar4[2] = ':';
        bVar1 = bVar6 >> 4;
        bVar6 = bVar6 & 0xf;
        if (bVar1 < 10) {
          cVar2 = bVar1 + 0x30;
        }
        else {
          cVar2 = bVar1 + 0x37;
        }
        *pcVar4 = cVar2;
        if (bVar6 < 10) {
          cVar2 = bVar6 + 0x30;
        }
        else {
          cVar2 = bVar6 + 0x37;
        }
        pcVar4[1] = cVar2;
        pcVar4 = pcVar4 + 3;
      } while (iVar3 != 6);
      local_1b = 0;
      cVar2 = keys__6006615c(0x25,acStack_2c,0x11);
      if (cVar2 == '\0') goto LAB_60065c22;
      uVar5 = 0x61;
      uVar7 = DAT_60065c60;
    }
    else {
      uVar5 = 100;
      uVar7 = DAT_60065c64;
    }
    FUN_6010165c(0x28,DAT_60065c5c,uVar5,uVar7);
  }
LAB_60065c22:
  *param_1 = local_30._1_1_;
  param_1[1] = (undefined1)local_30;
  param_1[2] = local_34._3_1_;
  param_1[3] = local_34._2_1_;
  param_1[4] = local_34._1_1_;
  param_1[5] = (undefined1)local_34;
  return param_1;
}


