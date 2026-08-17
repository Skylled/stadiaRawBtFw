// 600a13f0  FUN_600a13f0  size=156 bytes
// --- callers ---
//   60098530 FUN_60098530
// --- callees ---


undefined1 FUN_600a13f0(int param_1,char param_2)

{
  byte local_b;
  byte local_a;
  undefined1 local_9;
  
  local_9 = 0;
  local_b = 3;
  local_a = 0;
  do {
    if (2 < local_a) {
      if (param_2 != '\0') {
        if (local_b < 3) {
          *(int *)((local_b + 0x1bc) * 4 + DAT_600a148c + 4) = param_1;
        }
        else {
          local_9 = 3;
        }
      }
      return local_9;
    }
    if (*(int *)((local_a + 0x1bc) * 4 + DAT_600a148c + 4) == 0) {
      local_b = local_a;
    }
    else if (param_1 == *(int *)((local_a + 0x1bc) * 4 + DAT_600a148c + 4)) {
      if (param_2 == '\0') {
        *(undefined4 *)((local_a + 0x1bc) * 4 + DAT_600a148c + 4) = 0;
      }
      return 0;
    }
    local_a = local_a + 1;
  } while( true );
}


