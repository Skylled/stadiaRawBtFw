// 60098820  FUN_60098820  size=150 bytes
// --- callers ---
// --- callees ---
//   600a1394 FUN_600a1394
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined4 FUN_60098820(undefined4 param_1,char param_2,int param_3,undefined1 param_4)

{
  thunk_EXT_FUN_0000b5ba(DAT_600988b8,0,0x20);
  *(undefined2 *)(DAT_600988b8 + 2) = 0xfc2e;
  if (param_2 == '\0') {
    DAT_600988b8[0x1c] = param_4;
  }
  else {
    *(undefined4 *)(DAT_600988b8 + 0xc) = DAT_600988bc;
    *(undefined4 *)(DAT_600988b8 + 8) = *DAT_600988c0;
    if (*(int *)(DAT_600988b8 + 8) == 0) {
      return 0;
    }
    DAT_600988b8[0x1c] = *DAT_600988c4;
  }
  DAT_600988b8[4] = param_2;
  *(undefined4 *)(DAT_600988b8 + 0x14) = param_1;
  if (param_3 == 0) {
    *(undefined4 *)(DAT_600988b8 + 0x18) = DAT_600988c8;
  }
  else {
    *(int *)(DAT_600988b8 + 0x18) = param_3;
  }
  FUN_600a1394(*(undefined2 *)(DAT_600988b8 + 2),0,0,DAT_600988cc);
  *DAT_600988b8 = 1;
  return 1;
}


