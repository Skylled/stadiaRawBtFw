// 600a1490  FUN_600a1490  size=78 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---


void FUN_600a1490(undefined4 param_1,undefined1 param_2)

{
  undefined1 local_9;
  
  for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
    if (*(int *)((local_9 + 0x1bc) * 4 + DAT_600a14e0 + 4) != 0) {
      (**(code **)((local_9 + 0x1bc) * 4 + DAT_600a14e0 + 4))(param_2,param_1);
    }
  }
  return;
}


