// 600fd6d6  FUN_600fd6d6  size=356 bytes
// --- callers ---
//   60094dc4 FUN_60094dc4
//   600fd630 FUN_600fd630
// --- callees ---
//   600fde94 FUN_600fde94
//   600952fc FUN_600952fc
//   600f3caa FUN_600f3caa
//   600c65b0 FUN_600c65b0


void FUN_600fd6d6(int param_1,int param_2)

{
  undefined2 local_14 [3];
  undefined2 local_e;
  byte local_9;
  
  if (param_2 != 0) {
    for (local_9 = 0; local_9 < 2; local_9 = local_9 + 1) {
      if (*(char *)((uint)local_9 * 0xc + param_1 + 0x48) != '\0') {
        if (((int)(uint)*(ushort *)((uint)local_9 * 0xc + param_1 + 0x50) >>
             (*(byte *)(param_2 + 5) - 1 & 0xff) & 1U) != 0) {
          FUN_600952fc(*(undefined1 *)(param_2 + 5),(uint)local_9 * 0xc + param_1 + 0x49,0,0);
          FUN_600f3caa(*(undefined1 *)(param_2 + 5),(uint)local_9 * 0xc + param_1 + 0x49,0);
        }
        if (((int)(uint)*(ushort *)((uint)local_9 * 0xc + param_1 + 0x52) >>
             (*(byte *)(param_2 + 5) - 1 & 0xff) & 1U) != 0) {
          FUN_600952fc(*(undefined1 *)(param_2 + 5),(uint)local_9 * 0xc + param_1 + 0x49,0,1);
        }
      }
    }
    if (*(char *)(param_2 + 6) == '\0') {
      FUN_600c65b0(param_2);
    }
    else {
      for (local_9 = 0; local_9 < 6; local_9 = local_9 + 1) {
        if ((*(char *)((uint)local_9 * 0x20 + param_1 + 0x4ab) != '\0') &&
           (param_2 == *(int *)((uint)local_9 * 0x20 + param_1 + 0x49c))) {
          *(undefined1 *)(param_2 + 7) = 1;
          local_14[0] = 0x1d08;
          local_e = *(undefined2 *)((uint)local_9 * 0x20 + param_1 + 0x490);
          FUN_600fde94((uint)local_9 * 0x20 + 0x490 + param_1,local_14);
        }
      }
    }
  }
  return;
}


