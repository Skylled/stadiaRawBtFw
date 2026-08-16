// 600bcf88  FUN_600bcf88  size=394 bytes
// --- callers ---
//   600b720c FUN_600b720c
//   600bcca8 FUN_600bcca8
//   600b90d8 FUN_600b90d8
// --- callees ---


void FUN_600bcf88(undefined2 *param_1)

{
  byte local_a;
  byte local_9;
  
  if (param_1[0x51] != 0) {
    if (*(char *)(param_1 + 0x50) == '\0') {
      if ((ushort)param_1[0x51] < (ushort)param_1[0x9c]) {
        *(undefined1 *)(param_1 + 0x50) = 1;
        if ((*(int *)(param_1 + 0xaa) == 0) || (*(int *)(*(int *)(param_1 + 0xaa) + 0x2c) == 0)) {
          for (local_a = 0; local_a < 4; local_a = local_a + 1) {
            if (param_1 == *(undefined2 **)(*(int *)(param_1 + 0x96) + (local_a + 0x24) * 4)) {
              if (*(int *)((uint)local_a * 0x1c + DAT_600bd114 + 0xed8) == 0) {
                return;
              }
              (**(code **)((uint)local_a * 0x1c + DAT_600bd114 + 0xed8))
                        (*(int *)(param_1 + 0x96) + 4,1);
              return;
            }
          }
        }
        else {
          (**(code **)(*(int *)(param_1 + 0xaa) + 0x2c))(*param_1,1);
        }
      }
    }
    else if ((ushort)param_1[0x9c] <= (ushort)param_1[0x51] >> 1) {
      *(undefined1 *)(param_1 + 0x50) = 0;
      if ((*(int *)(param_1 + 0xaa) == 0) || (*(int *)(*(int *)(param_1 + 0xaa) + 0x2c) == 0)) {
        for (local_9 = 0; local_9 < 4; local_9 = local_9 + 1) {
          if (param_1 == *(undefined2 **)(*(int *)(param_1 + 0x96) + (local_9 + 0x24) * 4)) {
            if (*(int *)((uint)local_9 * 0x1c + DAT_600bd114 + 0xed8) == 0) {
              return;
            }
            (**(code **)((uint)local_9 * 0x1c + DAT_600bd114 + 0xed8))
                      (*(int *)(param_1 + 0x96) + 4,0);
            return;
          }
        }
      }
      else {
        *(undefined1 *)(DAT_600bd114 + 9) = 1;
        (**(code **)(*(int *)(param_1 + 0xaa) + 0x2c))(*param_1,0);
        *(undefined1 *)(DAT_600bd114 + 9) = 0;
      }
    }
  }
  return;
}


