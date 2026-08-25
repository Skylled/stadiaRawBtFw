// 600fbc50  FUN_600fbc50  size=74 bytes
// --- callers ---
//   600c08c4 FUN_600c08c4
// --- callees ---


void FUN_600fbc50(int param_1,byte param_2)

{
  undefined1 uVar1;
  undefined1 local_9;
  
  for (local_9 = param_2; local_9 < 0x10; local_9 = local_9 + 1) {
    if (local_9 == param_2) {
      uVar1 = 0x80;
    }
    else {
      uVar1 = 0;
    }
    *(undefined1 *)((0xf - (uint)local_9) + param_1) = uVar1;
  }
  return;
}


