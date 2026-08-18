// 600c330c  FUN_600c330c  size=78 bytes
// --- callers ---
//   600c2810 FUN_600c2810
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600efcc6 FUN_600efcc6
//   600c309c FUN_600c309c


void FUN_600c330c(void)

{
  undefined1 auStack_10 [7];
  undefined1 local_9;
  
  if (*(short *)(DAT_600c335c + 6) != 0) {
    FUN_600c309c(0);
  }
  if (*DAT_600c3360 != 0) {
    thunk_EXT_FUN_0000b5ba(auStack_10,0,8);
    FUN_600efcc6(auStack_10,DAT_600c3364);
    local_9 = 1;
    *DAT_600c3360 = 0;
    (*(code *)*DAT_600c335c)(5,0);
  }
  return;
}


