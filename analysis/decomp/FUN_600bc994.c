// 600bc994  FUN_600bc994  size=80 bytes
// --- callers ---
//   600b5720 FUN_600b5720
//   600f7ca0 FUN_600f7ca0
//   600ba1c4 FUN_600ba1c4
// --- callees ---


void FUN_600bc994(int param_1)

{
  byte bVar1;
  int local_14;
  
  if (*(char *)(param_1 + 0x32) == '\x01') {
    *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) & 6;
  }
  else {
    *(undefined1 *)(param_1 + 0x24) = *(undefined1 *)(DAT_600bcae4 + 0xf4e);
  }
  bVar1 = *(byte *)(param_1 + 0x24);
  local_14 = 0;
  do {
    if (3 < local_14) {
      return;
    }
    if (*(char *)(param_1 + 0x32) == '\x02') {
      if ((3 < local_14 + 4) && (local_14 + 4 < 7)) {
LAB_600bca0a:
        if (*(int *)(local_14 * 0x1c + DAT_600bcae4 + 0xed0) != 0) {
          if (((int)(uint)bVar1 >> (local_14 + 4U & 0xff) & 1U) == 0) {
            (**(code **)(local_14 * 0x1c + DAT_600bcae4 + 0xed0))
                      (param_1 + 4,0,*(undefined2 *)(param_1 + 0x30),*(undefined1 *)(param_1 + 0x32)
                      );
            if (*(int *)(param_1 + (local_14 + 0x24) * 4) != 0) {
              FUN_600bc00c(*(undefined4 *)(param_1 + (local_14 + 0x24) * 4));
              *(undefined4 *)(param_1 + (local_14 + 0x24) * 4) = 0;
            }
          }
          else {
            if (*(int *)(param_1 + (local_14 + 0x24) * 4) != 0) {
              *(undefined1 *)(*(int *)(param_1 + (local_14 + 0x24) * 4) + 4) = 6;
            }
            (**(code **)(local_14 * 0x1c + DAT_600bcae4 + 0xed0))
                      (param_1 + 4,1,0,*(undefined1 *)(param_1 + 0x32));
          }
        }
      }
    }
    else if (((*(char *)(param_1 + 0x32) != '\x01') || (local_14 + 4 < 4)) || (6 < local_14 + 4))
    goto LAB_600bca0a;
    local_14 = local_14 + 1;
  } while( true );
}


