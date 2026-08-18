// 600c60cc  FUN_600c60cc  size=42 bytes
// --- callers ---
//   600c611c FUN_600c611c
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600c60cc(char *param_1)

{
  if (*param_1 == '\0') {
    thunk_EXT_FUN_0000b5ba(DAT_600c60f8,0,0x5c8);
    *param_1 = '\x02';
  }
  return;
}


