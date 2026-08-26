// 600d8258  FUN_600d8258  size=14 bytes
// --- callers ---
//   6005c270 FUN_6005c270
// --- callees ---
//   600d8226 FUN_600d8226


undefined4 FUN_600d8258(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 10) != '\0') {
    uVar1 = FUN_600d8226();
    return uVar1;
  }
  return 9;
}


