// 600c3f04  FUN_600c3f04  size=346 bytes
// --- callers ---
//   600c3150 FUN_600c3150
//   600c3520 FUN_600c3520
//   600c3e84 FUN_600c3e84
//   600fd110 FUN_600fd110
// --- callees ---
//   600efcc6 FUN_600efcc6
//   600f0836 FUN_600f0836
//   601024d8 FUN_601024d8
//   600962dc FUN_600962dc
//   600c3c00 FUN_600c3c00
//   600f045e FUN_600f045e
//   6006dbac FUN_6006dbac
//   600c33f0 FUN_600c33f0
//   600c5ef4 FUN_600c5ef4


void FUN_600c3f04(undefined4 param_1)

{
  int iVar1;
  char local_12;
  char local_11;
  undefined2 *local_10;
  char local_9;
  
  local_9 = '\x01';
  if (*(char *)(DAT_600c4060 + 0x140) == '\0') {
    FUN_600f0836(param_1,&local_11,&local_12);
    if ((local_11 == '\x02') || (local_12 == '\x01')) {
      local_9 = '\x02';
    }
  }
  else {
    local_9 = *(char *)(DAT_600c4060 + 0x140);
  }
  FUN_600efcc6(DAT_600c4064,param_1);
  if ((*(char *)(DAT_600c4060 + 0x20) == '\0') &&
     ((*(int *)(DAT_600c4060 + 4) == 0 ||
      ((*(int *)(DAT_600c4060 + 4) != 0 && (*(char *)(*(int *)(DAT_600c4060 + 4) + 0x14) == '\0'))))
     )) {
    iVar1 = FUN_600c33f0(DAT_600c4064,local_9);
    if (iVar1 == 1) {
      return;
    }
    *(undefined1 *)(DAT_600c4060 + 0x20) = 1;
  }
  if (*(int *)(DAT_600c4060 + 8) != 0) {
    *(undefined1 *)(DAT_600c4060 + 0x134) = 0;
    *(undefined4 *)(DAT_600c4060 + 0x10) = 0;
    *(undefined4 *)(DAT_600c4060 + 0xc) = *(undefined4 *)(DAT_600c4060 + 8);
    *(undefined1 *)(DAT_600c4060 + 0x148) = *(undefined1 *)(DAT_600c4060 + 0x142);
    iVar1 = FUN_600f045e(DAT_600c4064,1);
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_600c4060 + 0x13c) = 1;
    }
    else {
      *(undefined1 *)(DAT_600c4060 + 0x13c) = 0;
    }
    if (local_9 != '\x02') {
      *(undefined1 *)(DAT_600c4060 + 0x13d) = 0;
      FUN_600c3c00(DAT_600c4064);
      return;
    }
    if ((*(uint *)(DAT_600c4060 + 0xc) & 0x40000000) != 0) {
      FUN_600c5ef4(DAT_600c4064);
      return;
    }
  }
  local_10 = (undefined2 *)FUN_6006dbac(0x140,DAT_600c4068,0x949);
  if (local_10 != (undefined2 *)0x0) {
    *local_10 = 0x207;
    *(undefined1 *)(local_10 + 0x86) = 0;
    *(undefined4 *)(local_10 + 0x84) = *(undefined4 *)(DAT_600c4060 + 0x10);
    FUN_600efcc6(local_10 + 4,DAT_600c4064);
    FUN_601024d8(local_10 + 7,DAT_600c406c,0xf8);
    *(undefined1 *)(local_10 + 0x83) = 0;
    FUN_600962dc(local_10);
  }
  return;
}


