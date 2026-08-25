// 600f6516  FUN_600f6516  size=278 bytes
// --- callers ---
//   600f41d0 FUN_600f41d0
//   600ad9d8 FUN_600ad9d8
// --- callees ---
//   600ae7f8 FUN_600ae7f8
//   600ae90c FUN_600ae90c
//   600ae4e0 FUN_600ae4e0
//   600adeb4 FUN_600adeb4
//   600f6be6 FUN_600f6be6
//   600ae670 FUN_600ae670
//   600f6206 FUN_600f6206
//   600aee8c FUN_600aee8c
//   600af0b4 FUN_600af0b4
//   600f633e FUN_600f633e


void FUN_600f6516(int param_1,byte param_2,ushort param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_600f6206(param_1);
  if ((iVar1 == 0) && (param_2 != 0x1e)) {
    return;
  }
  if (*(ushort *)(param_1 + 0x1a) <= param_3) {
    if (param_2 == 0x52) {
      return;
    }
    if (param_2 == 0xd2) {
      return;
    }
    if (param_2 == 0x1e) {
      return;
    }
    FUN_600f6be6(param_1,4,param_2,0,0);
    return;
  }
  if (param_2 == 0xe) {
    FUN_600adeb4(param_1,0xe,param_3,param_4);
    return;
  }
  if (param_2 < 0xf) {
    if (param_2 == 6) {
LAB_600f65b6:
      FUN_600ae4e0(param_1,param_2,param_3,param_4);
      return;
    }
    if (param_2 < 7) {
      if (param_2 == 2) {
        FUN_600ae7f8(param_1,param_3,param_4);
        return;
      }
      if (param_2 != 4) {
        return;
      }
      FUN_600ae670(param_1,4,param_3,param_4);
      return;
    }
    if ((param_2 != 10) && (param_2 != 0xc)) {
      if (param_2 != 8) {
        return;
      }
      FUN_600ae90c(param_1,8,param_3,param_4);
      return;
    }
  }
  else {
    if (param_2 == 0x18) {
      FUN_600f633e(param_1,0x18,param_3,param_4);
      return;
    }
    if (param_2 < 0x19) {
      if ((param_2 != 0x12) && (param_2 != 0x16)) {
        if (param_2 != 0x10) {
          return;
        }
        goto LAB_600f65b6;
      }
    }
    else if ((param_2 != 0x52) && (param_2 != 0xd2)) {
      if (param_2 != 0x1e) {
        return;
      }
      FUN_600af0b4(param_1,0x1e);
      return;
    }
  }
  FUN_600aee8c(param_1,param_2,param_3,param_4);
  return;
}


