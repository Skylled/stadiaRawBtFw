// 6005a1b0  device_info__6005a1b0  size=642 bytes
// src: device_info.cc
// --- callers ---
//   6005a6b0 device_info__6005a6b0
// --- callees ---
//   600e0ca6 FUN_600e0ca6
//   601024a4 FUN_601024a4
//   600874dc FUN_600874dc
//   600d3b02 FUN_600d3b02
//   60101bcc FUN_60101bcc
//   600d37b8 FUN_600d37b8
//   6010165c FUN_6010165c
//   600d37ac FUN_600d37ac
//   6004cb28 FUN_6004cb28
//   600cdcc4 FUN_600cdcc4
//   600e0d54 FUN_600e0d54
//   600dfbac FUN_600dfbac
//   60101ba2 FUN_60101ba2
//   60086720 FUN_60086720
//   6010248a FUN_6010248a
//   60051120 FUN_60051120
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600d3b3a FUN_600d3b3a
//   600d7d48 thunk_FUN_600d7cdc


/* src: device_info.cc */

undefined1 device_info__6005a1b0(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  ushort uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined1 uVar10;
  int iVar11;
  int iVar12;
  int local_178;
  undefined1 *local_174;
  undefined4 local_170;
  undefined2 local_16c;
  undefined1 **local_168;
  undefined4 auStack_164 [10];
  undefined1 auStack_13c [128];
  undefined1 *local_bc;
  undefined4 local_b8;
  int local_b4;
  uint local_b0;
  int local_ac;
  undefined1 local_24;
  
  FUN_600dfbac(&local_178);
  if (local_178 == 0) {
    FUN_60051120(&local_bc,DAT_6005a434,0x12f,0xd);
    uVar6 = DAT_6005a438;
  }
  else {
    iVar2 = FUN_60086720(local_178,0,0);
    if (iVar2 != 0) {
      iVar3 = FUN_600e0ca6();
      if (iVar3 == 0) {
        FUN_60051120(&local_bc,DAT_6005a434,0x137,0xd);
        uVar6 = DAT_6005a440;
        goto LAB_6005a22e;
      }
      thunk_EXT_FUN_0000b5ba(auStack_13c,0,0x80);
      iVar3 = FUN_600e0d54(iVar3,0xd,auStack_13c,0x80);
      if (iVar3 < 0) {
        local_bc = DAT_6005a434;
        local_b8 = 0x13c;
        FUN_600d3b3a(&local_b4);
        FUN_600d37ac(&local_b4,DAT_6005a444);
        FUN_600d37b8(&local_bc);
LAB_6005a27a:
        uVar10 = 0xd;
      }
      else {
        puVar4 = (undefined1 *)FUN_6010248a(auStack_13c,0x20);
        if (puVar4 == (undefined1 *)0x0) {
          local_174 = puVar4;
          local_bc = auStack_13c;
          iVar3 = thunk_FUN_600d7cdc();
          puVar9 = DAT_6005a450;
          if (iVar3 != 0) {
            FUN_600cdcc4(&local_b8,0x28,DAT_6005a448,local_bc);
            puVar9 = &local_b8;
          }
          FUN_6010165c(0x28,DAT_6005a434,0x143,DAT_6005a44c,puVar9);
          goto LAB_6005a27a;
        }
        *puVar4 = 0;
        local_174 = puVar4 + 1;
        uVar5 = FUN_6004cb28(auStack_13c);
        if (uVar5 < 0xb) {
          FUN_601024a4(param_1 + 0x3b,auStack_13c);
          iVar3 = FUN_6004cb28(puVar4 + 1);
          if (iVar3 != 0xc) {
            FUN_60051120(&local_bc,DAT_6005a434,0x14f,0xd);
            uVar6 = DAT_6005a458;
            goto LAB_6005a22e;
          }
          iVar3 = 0;
          local_170 = 0;
          local_16c = 0;
          do {
            bVar1 = puVar4[1];
            uVar5 = (uint)bVar1;
            if ((uVar5 - 0x30 & 0xff) < 10) {
              uVar5 = uVar5 - 0x30 & 0xffff;
            }
            else {
              if (uVar5 - 0x41 < 6) {
                uVar7 = bVar1 - 0x37;
              }
              else {
                if (5 < uVar5 - 0x61) {
                  uVar5 = 0x100;
                  goto LAB_6005a338;
                }
                uVar7 = bVar1 - 0x57;
              }
              uVar5 = (uint)uVar7;
            }
LAB_6005a338:
            bVar1 = puVar4[2];
            uVar8 = (uint)bVar1;
            if ((uVar8 - 0x30 & 0xff) < 10) {
              uVar7 = (ushort)(uVar8 - 0x30);
            }
            else if (uVar8 - 0x41 < 6) {
              uVar7 = bVar1 - 0x37;
            }
            else if (uVar8 - 0x61 < 6) {
              uVar7 = bVar1 - 0x57;
            }
            else {
              uVar7 = 0x100;
            }
            uVar7 = uVar7 | (ushort)(uVar5 << 4);
            if (0xff < (short)uVar7) {
              FUN_60051120(&local_bc,DAT_6005a434,0x155,3);
              FUN_600d37ac(&local_b4,DAT_6005a460);
              iVar12 = local_b0 - local_ac;
              iVar11 = local_b4 + local_ac;
              local_168 = &local_174;
              iVar3 = thunk_FUN_600d7cdc();
              puVar9 = DAT_6005a450;
              if (iVar3 != 0) {
                FUN_600cdcc4(auStack_164,0x28,DAT_6005a448,*local_168);
                puVar9 = auStack_164;
              }
              uVar6 = FUN_600cdcc4(iVar11,iVar12,DAT_6005a448,puVar9);
              FUN_60101ba2(&local_b4,uVar6);
              goto LAB_6005a234;
            }
            *(char *)((int)&local_170 + iVar3) = (char)uVar7;
            iVar3 = iVar3 + 1;
            puVar4 = puVar4 + 2;
          } while (iVar3 != 6);
          local_bc = (undefined1 *)(param_1 + 0x5b);
          uVar10 = 0;
          *(undefined1 *)(param_1 + 0x5b) = 0;
          local_b0 = local_b0 & 0xffff0000;
          local_b8 = 0x12;
          local_b4 = 0;
          FUN_60101bcc(&local_bc,DAT_6005a45c,local_170 & 0xff,local_170._1_1_,
                       local_170 >> 0x10 & 0xff,local_170 >> 0x18,(undefined1)local_16c,
                       local_16c._1_1_);
        }
        else {
          FUN_60051120(&local_bc,DAT_6005a434,0x148,0xd);
          uVar6 = DAT_6005a454;
LAB_6005a22e:
          FUN_600d37ac(&local_b4,uVar6);
LAB_6005a234:
          FUN_600d37b8(&local_bc);
          uVar10 = local_24;
        }
      }
      FUN_600874dc(iVar2);
      goto LAB_6005a1e4;
    }
    FUN_60051120(&local_bc,DAT_6005a434,0x133,0xd);
    uVar6 = DAT_6005a43c;
  }
  FUN_600d37ac(&local_b4,uVar6);
  FUN_600d37b8(&local_bc);
  uVar10 = local_24;
LAB_6005a1e4:
  FUN_600d3b02(&local_178);
  return uVar10;
}


