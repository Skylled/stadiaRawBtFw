// 600942d4  FUN_600942d4  size=52 bytes
// --- callers ---
//   600c2d5c FUN_600c2d5c
//   60093d20 FUN_60093d20
//   600fd03a FUN_600fd03a
// --- callees ---
//   600a3424 FUN_600a3424
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600942d4(undefined4 param_1)

{
  undefined1 auStack_14 [8];
  undefined1 local_c;
  
  thunk_EXT_FUN_0000b5ba(auStack_14,0,10);
  local_c = 0;
  FUN_600a3424(*(undefined1 *)(DAT_60094308 + 0x124),param_1,auStack_14);
  return;
}


