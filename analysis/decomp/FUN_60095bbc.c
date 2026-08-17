// 60095bbc  FUN_60095bbc  size=82 bytes
// --- callers ---
//   600c4da8 FUN_600c4da8
// --- callees ---


void FUN_60095bbc(undefined4 param_1)

{
  undefined1 local_11;
  
  for (local_11 = 0; local_11 < 5; local_11 = local_11 + 1) {
    if ((*(char *)((uint)local_11 + DAT_60095c10 + 0x150) != '\0') &&
       (*(int *)(DAT_60095c10 + (local_11 + 0x56) * 4) != 0)) {
      (**(code **)(DAT_60095c10 + (local_11 + 0x56) * 4))(0,0,0,param_1);
    }
  }
  return;
}


