// 600d48c4  FUN_600d48c4  size=20 bytes
// --- callers ---
//   6005f9a8 FUN_6005f9a8
// --- callees ---
//   6013cfc0 thunk_EXT_FUN_000009c0


undefined4 FUN_600d48c4(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*param_1 == '\0') {
    thunk_EXT_FUN_000009c0
              (*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),param_3,0,param_4);
  }
  return 0;
}


