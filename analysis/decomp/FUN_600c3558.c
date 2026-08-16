// 600c3558  FUN_600c3558  size=932 bytes
// --- callers ---
// --- callees ---
//   600fa2b2 FUN_600fa2b2
//   600fa2cc FUN_600fa2cc
//   601024d8 FUN_601024d8
//   600a4010 FUN_600a4010
//   600c54ec FUN_600c54ec
//   6006ddd8 FUN_6006ddd8
//   600fa2e4 FUN_600fa2e4
//   6006dbac FUN_6006dbac
//   600962dc FUN_600962dc
//   600efcc6 FUN_600efcc6
//   600c3c00 FUN_600c3c00


void FUN_600c3558(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  undefined2 local_14c [2];
  undefined2 local_148;
  undefined1 auStack_138 [6];
  undefined1 auStack_132 [248];
  undefined1 local_3a;
  undefined2 local_38;
  undefined2 local_34;
  short local_22;
  undefined2 *local_20;
  int local_1c;
  char local_15;
  int local_14;
  
  local_14 = 0;
  local_15 = 0;
  local_1c = DAT_600c3830[0x51];
  if (((*(short *)(param_1 + 8) == 0) || (*(short *)(param_1 + 8) == -0x10)) ||
     (*(short *)(param_1 + 8) == -0xc)) {
    do {
      local_15 = '\0';
      local_14 = 0;
      local_22 = *(short *)(DAT_600c3834 + (*(byte *)(DAT_600c3830 + 0x4d) - 1) * 2);
      if (*(char *)(DAT_600c3830 + 0x4d) == '\x1f') {
        if ((*(char *)(DAT_600c3830 + 0x52) != '\0') && (local_1c != 0)) {
          local_1c = local_1c +
                     ((uint)*(byte *)((int)DAT_600c3830 + 0x142) -
                     (uint)*(byte *)(DAT_600c3830 + 0x52)) * 0x14;
          local_22 = *(short *)(local_1c + 4);
        }
        do {
          local_14 = FUN_600fa2e4(DAT_600c3830[5],0,local_14);
          if ((local_14 != 0) && (iVar1 = FUN_600fa2cc(local_14,local_14c), iVar1 != 0)) {
            FUN_600efcc6(auStack_138,DAT_600c3838);
            uVar2 = FUN_600c54ec();
            FUN_601024d8(auStack_132,uVar2,0xf8);
            local_3a = 0;
            local_38 = local_14c[0];
            local_34 = local_148;
            (*(code *)*DAT_600c3830)(3,auStack_138);
          }
        } while ((*(char *)(DAT_600c3830 + 0x52) == '\0') && (local_14 != 0));
      }
      else if ((*(short *)(param_1 + 8) == -0xc) ||
              (local_14 = FUN_600fa2e4(DAT_600c3830[5],local_22,0), local_14 != 0)) {
        if (local_22 == 0x1200) {
          if ((local_14 != 0) && (iVar1 = FUN_600fa2b2(local_14,0x8001), iVar1 != 0)) {
            local_15 = '\x01';
          }
        }
        else {
          local_15 = '\x01';
        }
        if (local_15 != '\0') {
          DAT_600c3830[4] = DAT_600c3830[4] | 1 << (*(byte *)(DAT_600c3830 + 0x4d) - 1 & 0xff);
        }
      }
      if ((DAT_600c3830[2] != 0x7fffffff) || (DAT_600c3830[3] != 0)) break;
      if ((*(char *)(DAT_600c3830 + 0x4d) == '\x1e') && (*(char *)(DAT_600c3830 + 0x52) != '\0')) {
        *(char *)(DAT_600c3830 + 0x52) = *(char *)(DAT_600c3830 + 0x52) + -1;
      }
      if ((*(char *)(DAT_600c3830 + 0x52) == '\0') || (*(char *)(DAT_600c3830 + 0x4d) != '\x1e')) {
        *(char *)(DAT_600c3830 + 0x4d) = *(char *)(DAT_600c3830 + 0x4d) + '\x01';
      }
    } while (*(byte *)(DAT_600c3830 + 0x4d) < 0x20);
    FUN_6006ddd8(DAT_600c3830[5],DAT_600c383c,0x6f5);
    DAT_600c3830[5] = 0;
    if (DAT_600c3830[3] == 0) {
      FUN_600a4010(DAT_600c3840);
      local_20 = (undefined2 *)FUN_6006dbac(0x140,DAT_600c383c,0x705);
      if (local_20 != (undefined2 *)0x0) {
        *local_20 = 0x207;
        *(undefined1 *)(local_20 + 0x86) = 0;
        *(undefined4 *)(local_20 + 0x84) = DAT_600c3830[4];
        FUN_600efcc6(local_20 + 4,DAT_600c3838);
        puVar3 = local_20 + 7;
        uVar2 = FUN_600c54ec();
        FUN_601024d8(puVar3,uVar2,0xf8);
        *(undefined1 *)(local_20 + 0x83) = 0;
        FUN_600962dc(local_20);
      }
    }
    else {
      FUN_600c3c00(DAT_600c3838);
    }
  }
  else {
    if (((*(short *)(param_1 + 8) == -0xf) || (*(short *)(param_1 + 8) == -9)) ||
       (*(short *)(param_1 + 8) == -10)) {
      *(undefined1 *)(DAT_600c3914 + 0x13c) = 0;
    }
    FUN_6006ddd8(*(undefined4 *)(DAT_600c3914 + 0x14),DAT_600c3918,0x71e);
    *(undefined4 *)(DAT_600c3914 + 0x14) = 0;
    FUN_600a4010(DAT_600c391c);
    local_20 = (undefined2 *)FUN_6006dbac(0x140,DAT_600c3918,0x723);
    if (local_20 != (undefined2 *)0x0) {
      *local_20 = 0x207;
      *(undefined1 *)(local_20 + 0x86) = 1;
      *(undefined4 *)(local_20 + 0x84) = *(undefined4 *)(DAT_600c3914 + 0x10);
      FUN_600efcc6(local_20 + 4,DAT_600c3920);
      puVar3 = local_20 + 7;
      uVar2 = FUN_600c54ec();
      FUN_601024d8(puVar3,uVar2,0xf8);
      *(undefined1 *)(local_20 + 0x83) = 0;
      FUN_600962dc(local_20);
    }
  }
  return;
}


