// 60047f50  FUN_60047f50  size=24 bytes
// --- callers ---
//   6004ba16 FUN_6004ba16
//   60047548 FUN_60047548
//   6004703c FUN_6004703c
//   60048248 FUN_60048248
//   60047290 queue__60047290
//   600426c0 FUN_600426c0
//   60047678 queue__60047678
// --- callees ---


undefined4 FUN_60047f50(void)

{
  undefined4 uVar1;
  
  if (*DAT_60047f68 == 0) {
    return 1;
  }
  if (*DAT_60047f6c == 0) {
    uVar1 = 2;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


