// 600c5c8c  FUN_600c5c8c  size=66 bytes
// --- callers ---
//   600c3150 FUN_600c3150
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6009451c FUN_6009451c


void FUN_600c5c8c(void)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_1c = 0x10;
  if (*(char *)(DAT_600c5cd0 + 0x141) == '\0') {
    thunk_EXT_FUN_0000b5ba(&local_18,0x87,0x10);
    FUN_6009451c(&local_1c,DAT_600c5cd4);
  }
  return;
}


