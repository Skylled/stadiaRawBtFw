// 600a038c  FUN_600a038c  size=210 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   600a046c FUN_600a046c
//   600b0718 FUN_600b0718
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600bc424 FUN_600bc424


void FUN_600a038c(void)

{
  undefined4 local_c;
  
  if (*(int *)(DAT_600a0460 + 0xd4) != 0) {
    (**(code **)(DAT_600a0460 + 0xd4))(1,0);
  }
  if (*(char *)(DAT_600a0464 + 0x881) == '\0') {
    FUN_600bc424();
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      *(undefined1 *)(DAT_600a0464 + local_c * 0xfc + 0x1318) = 0;
    }
    *(undefined4 *)(DAT_600a0464 + 0xb38) = 1;
    *(undefined2 *)(DAT_600a0464 + 0xb18) = 0x12;
    *(undefined2 *)(DAT_600a0464 + 0xb1a) = 0x1000;
    *(undefined2 *)(DAT_600a0464 + 0xb1c) = 0;
    *(undefined2 *)(DAT_600a0464 + 0xb14) = 0x12;
    *(undefined2 *)(DAT_600a0464 + 0xb16) = 0x800;
    *(undefined2 *)(DAT_600a0464 + 0xb1e) = 0;
    *(undefined1 *)(DAT_600a0464 + 0x881) = 1;
    FUN_600a046c();
    *(undefined1 *)(DAT_600a0464 + 0xa30) = 0;
    *(undefined1 *)(DAT_600a0464 + 0x9c7) = 0;
    *(undefined1 *)(DAT_600a0464 + 0x9b8) = 0;
    *(undefined4 *)(DAT_600a0464 + 0x9c0) = 0;
    thunk_EXT_FUN_0000b5ba(DAT_600a0468,0,0x5a);
    FUN_600b0718();
  }
  return;
}


