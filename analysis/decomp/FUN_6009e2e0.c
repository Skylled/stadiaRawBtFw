// 6009e2e0  FUN_6009e2e0  size=82 bytes
// --- callers ---
//   600a2f3c FUN_600a2f3c
// --- callees ---


void FUN_6009e2e0(void)

{
  undefined4 local_10;
  undefined2 local_a;
  
  local_10 = DAT_6009e334;
  for (local_a = 0; local_a < 0x1e; local_a = local_a + 1) {
    if (((*(char *)(local_10 + 0x2e) != '\0') && (*(char *)(local_10 + 0x17) == '\x02')) &&
       (*(char *)(local_10 + 0x2f) == '\0')) {
      *(undefined1 *)(local_10 + 0x2e) = 0;
    }
    local_10 = local_10 + 0x30;
  }
  return;
}


