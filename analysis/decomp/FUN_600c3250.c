// 600c3250  FUN_600c3250  size=102 bytes
// --- callers ---
//   600c3924 FUN_600c3924
// --- callees ---
//   600fa338 FUN_600fa338
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600efcc6 FUN_600efcc6


void FUN_600c3250(int param_1)

{
  undefined1 auStack_10 [6];
  undefined1 local_a;
  undefined1 local_9;
  
  thunk_EXT_FUN_0000b5ba(auStack_10,0,8);
  FUN_600efcc6(auStack_10,DAT_600c32b8);
  if ((*(short *)(param_1 + 4) == 0) || (*(short *)(param_1 + 4) == -0xc)) {
    local_a = FUN_600fa338(*DAT_600c32bc);
  }
  else {
    local_9 = 1;
  }
  *DAT_600c32bc = 0;
  (*(code *)*DAT_600c32c0)(5,auStack_10);
  return;
}


