// 600c0930  FUN_600c0930  size=176 bytes
// --- callers ---
//   600fbcf8 FUN_600fbcf8
// --- callees ---
//   600fc9fc FUN_600fc9fc
//   600c08c4 FUN_600c08c4
//   600fbc9a FUN_600fbc9a
//   600fbc3a FUN_600fbc3a


void FUN_600c0930(int param_1)

{
  undefined1 auStack_2c [16];
  undefined1 auStack_1c [15];
  char local_d;
  int local_c;
  
  local_c = param_1 + 4;
  FUN_600fbc3a(local_c,DAT_600c09e0);
  if (*(char *)(local_c + 0xf) < '\0') {
    FUN_600fbc9a(local_c,auStack_1c);
    FUN_600fc9fc(auStack_1c,DAT_600c09e4);
  }
  else {
    FUN_600fbc9a(local_c,auStack_1c);
  }
  if (local_d < '\0') {
    FUN_600fbc9a(auStack_1c,auStack_2c);
    FUN_600fc9fc(auStack_2c,DAT_600c09e4);
  }
  else {
    FUN_600fbc9a(auStack_1c,auStack_2c);
  }
  FUN_600fbc3a(auStack_1c,DAT_600c09e8);
  FUN_600fbc3a(auStack_2c,DAT_600c09ec);
  FUN_600c08c4(auStack_1c,auStack_2c);
  return;
}


