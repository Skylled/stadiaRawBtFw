// 60060804  srtc__60060804  size=80 bytes
// src: srtc.cc
// --- callers ---
//   600cbdc8 xbara__600cbdc8
// --- callees ---
//   600cfb2c FUN_600cfb2c
//   6010165c FUN_6010165c
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   600607a8 FUN_600607a8
//   6013cef0 thunk_EXT_FUN_0000887a
//   600cfb42 FUN_600cfb42
//   60054330 FUN_60054330


/* src: srtc.cc */

undefined4 srtc__60060804(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_14 = param_1;
  uStack_10 = param_3;
  uStack_c = param_4;
  thunk_EXT_FUN_0000b4c2();
  if (*(char *)(param_1 + 100) == '\0') {
    FUN_600cfb2c(&uStack_10);
    FUN_60054330(DAT_60060854,&uStack_10);
    FUN_600cfb42(DAT_60060854,4);
    iVar1 = FUN_600607a8();
    if (iVar1 == 0) {
      FUN_6010165c(0x1e,DAT_6006085c,0x30,DAT_60060858);
    }
    *(undefined1 *)(param_1 + 100) = 1;
  }
  thunk_EXT_FUN_0000887a(&local_14);
  return 0;
}


