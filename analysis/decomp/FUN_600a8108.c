// 600a8108  FUN_600a8108  size=146 bytes
// --- callers ---
//   600a5964 FUN_600a5964
//   600a44bc FUN_600a44bc
//   600a5670 FUN_600a5670
//   600a7870 FUN_600a7870
//   600a74dc FUN_600a74dc
//   600a6184 FUN_600a6184
//   600a730c FUN_600a730c
//   600a4984 FUN_600a4984
//   600a65f4 FUN_600a65f4
//   600a59d0 FUN_600a59d0
//   600a67ec FUN_600a67ec
//   600a42d0 FUN_600a42d0
//   600a6cf8 FUN_600a6cf8
//   600a5ec8 FUN_600a5ec8
//   600a6d70 FUN_600a6d70
//   600a4a20 FUN_600a4a20
//   600a62cc FUN_600a62cc
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600aa3cc FUN_600aa3cc
//   600a5760 FUN_600a5760
//   600f8c0a FUN_600f8c0a
//   600a804c FUN_600a804c
//   600a2548 FUN_600a2548
//   600aa340 FUN_600aa340


void FUN_600a8108(char param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(DAT_600a819c + 0x118c);
  *(char *)(DAT_600a819c + 0x118c) = param_1;
  if (param_1 == '\0') {
    FUN_600aa3cc(DAT_600a81a0);
    *(undefined1 *)(DAT_600a819c + 0x118d) = 0;
    *(undefined1 *)(DAT_600a819c + 0x117b) = 0;
    FUN_600f8c0a(DAT_600a81a4,0);
    FUN_600a804c();
    FUN_600a5760();
    FUN_600a2548();
    thunk_EXT_FUN_0000b5ba(DAT_600a81a4,0xff,6);
  }
  else {
    if (cVar1 == '\0') {
      FUN_600f8c0a(DAT_600a81a4,1);
    }
    *(undefined4 *)(DAT_600a819c + 0x11a4) = DAT_600a81a8;
    FUN_600aa340(DAT_600a81a0,0xd,0x23);
  }
  return;
}


