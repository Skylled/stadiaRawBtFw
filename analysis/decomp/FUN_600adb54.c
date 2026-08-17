// 600adb54  FUN_600adb54  size=162 bytes
// --- callers ---
//   600ab0d4 FUN_600ab0d4
// --- callees ---
//   600af350 FUN_600af350
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600adb54(void)

{
  int iVar1;
  undefined1 auStack_24 [8];
  byte local_1c [8];
  byte local_14 [9];
  byte local_b;
  byte local_a;
  char local_9;
  
  if (*(int *)(DAT_600adbf8 + 0x1558) != 0) {
    local_9 = (**(code **)(DAT_600adbf8 + 0x1558))(4,0,local_1c);
    if ((local_9 != '\0') && (local_1c[0] != 0)) {
      local_b = local_1c[0];
      local_a = 1;
      while ((local_a <= local_b && (local_9 != '\0'))) {
        local_14[0] = local_a;
        local_9 = (**(code **)(DAT_600adbf8 + 0x1558))(5,local_14,local_1c);
        if (local_9 == '\x01') {
          thunk_EXT_FUN_0000b572(auStack_24,local_1c,7);
          iVar1 = FUN_600af350(auStack_24);
          if (iVar1 == 0) {
            local_9 = '\0';
          }
        }
        local_a = local_a + 1;
      }
    }
  }
  return;
}


