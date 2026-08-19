// 600d903e  FUN_600d903e  size=56 bytes
// --- callers ---
//   60061e98 FUN_60061e98
//   6006b708 FUN_6006b708
//   6006b630 sound_codec_wm8904__6006b630
//   6006b85c FUN_6006b85c
// --- callees ---
//   6013d0b0 thunk_EXT_FUN_00001ea4


void FUN_600d903e(undefined4 *param_1,undefined1 param_2,undefined2 *param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 local_10 [4];
  undefined1 local_c;
  undefined1 local_b;
  
  local_10[0] = param_2;
  cVar1 = thunk_EXT_FUN_00001ea4
                    (*param_1,*(undefined1 *)(param_1 + 1),local_10,1,&local_c,2,param_4);
  if (cVar1 == '\0') {
    *param_3 = CONCAT11(local_c,local_b);
  }
  return;
}


