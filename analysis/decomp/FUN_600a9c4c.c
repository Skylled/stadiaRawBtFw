// 600a9c4c  FUN_600a9c4c  size=444 bytes
// --- callers ---
//   600a9fce FUN_600a9fce
// --- callees ---
//   600f2a2a FUN_600f2a2a
//   600aa340 FUN_600aa340
//   600f2532 FUN_600f2532
//   600d9250 FUN_600d9250
//   600a17c0 FUN_600a17c0
//   600a9234 FUN_600a9234
//   600a96d8 FUN_600a96d8
//   600d9306 FUN_600d9306
//   6006ddd8 FUN_6006ddd8


void FUN_600a9c4c(byte param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 local_1b;
  ushort local_1a;
  byte *local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  
  local_10 = (uint)param_1 * 0x34 + 0xa0 + DAT_600a9e08;
  local_c = 0;
  *(undefined2 *)(local_10 + 0x18) = 1;
  local_14 = FUN_600d9250(local_10 + 0xc);
  if (local_14 == 0) {
    return;
  }
  iVar1 = FUN_600d9306(local_10 + 0xc);
  if (iVar1 == 0) {
    FUN_600aa340(local_10 + 0x1c,param_1 + 0x2c,8);
  }
  local_18 = (byte *)(local_14 + 8 + (uint)*(ushort *)(local_14 + 4));
  local_1a = (ushort)local_18[1] * 0x100 + (ushort)*local_18;
  local_18 = local_18 + 2;
  if (*DAT_600a9e0c != '\0') {
    *DAT_600a9e0c = '\0';
  }
  uVar2 = (uint)local_1a;
  if (uVar2 != 0x801) {
    if (uVar2 < 0x802) {
      if (uVar2 != 0x411) {
        if (uVar2 < 0x412) {
          if (((uVar2 != 0x401) && (uVar2 != 0x405)) && (uVar2 != 0xd)) goto LAB_600a9da0;
        }
        else if (uVar2 != 0x415) {
          if (uVar2 < 0x416) {
            if (uVar2 == 0x413) goto LAB_600a9d8e;
          }
          else if ((uVar2 == 0x419) || (uVar2 == 0x41c)) goto LAB_600a9d8e;
LAB_600a9da0:
          if ((((local_1a & 0xfc00) == 0xfc00) || (local_1a == 0x2018)) || (local_1a == 0x2017)) {
            local_c = *(undefined4 *)(local_14 + 8);
          }
          local_1b = 0x1f;
          FUN_600f2532(local_1a,&local_1b,1,local_c,param_1);
          goto LAB_600a9dde;
        }
      }
    }
    else if (uVar2 != 0xc3f) {
      if (uVar2 < 0xc40) {
        if ((uVar2 < 0x803) || ((0x806 < uVar2 && (uVar2 != 0x80b)))) goto LAB_600a9da0;
      }
      else if (uVar2 != 0x140c) {
        if (uVar2 < 0x140d) {
          if (uVar2 - 0xc6e < 6) goto LAB_600a9d8e;
        }
        else if (uVar2 == 0x2014) goto LAB_600a9d8e;
        goto LAB_600a9da0;
      }
    }
  }
LAB_600a9d8e:
  FUN_600a96d8(local_1a,0x1f,local_18,0,param_1);
LAB_600a9dde:
  FUN_6006ddd8(local_14,DAT_600a9e10,0x9a1);
  FUN_600a17c0(2);
  FUN_600f2a2a();
  FUN_600a9234(param_1,0);
  return;
}


