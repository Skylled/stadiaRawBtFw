// 600f5a00  FUN_600f5a00  size=152 bytes
// --- callers ---
//   600f5a98 FUN_600f5a98
// --- callees ---


void FUN_600f5a00(char param_1,int param_2,char param_3)

{
  bool bVar1;
  byte local_9;
  
  bVar1 = false;
  if (param_2 != 0) {
    for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
      if ((param_1 == *(char *)((uint)local_9 + param_2 + 0x1e)) && (bVar1 = true, param_3 == '\0'))
      {
        *(undefined1 *)((uint)local_9 + param_2 + 0x1e) = 0;
        break;
      }
    }
    if ((!bVar1) && (param_3 != '\0')) {
      for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
        if (*(char *)((uint)local_9 + param_2 + 0x1e) == '\0') {
          *(char *)((uint)local_9 + param_2 + 0x1e) = param_1;
          return;
        }
      }
    }
  }
  return;
}


