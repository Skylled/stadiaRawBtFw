// 60093810  FUN_60093810  size=372 bytes
// --- callers ---
//   60093a30 FUN_60093a30
// --- callees ---
//   6009633c FUN_6009633c
//   600efcfe FUN_600efcfe


void FUN_60093810(undefined4 param_1,char param_2,char param_3)

{
  int iVar1;
  byte local_a;
  byte local_9;
  
  local_9 = 0;
  do {
    if (2 < local_9) {
      return;
    }
    if ((*(char *)((uint)local_9 * 0x5c + DAT_60093984 + 0x180) != '\0') &&
       (iVar1 = FUN_600efcfe((uint)local_9 * 0x5c + DAT_60093984 + 0x17a,param_1), iVar1 == 0)) {
      for (local_a = 0; local_a < 3; local_a = local_a + 1) {
        if ((param_2 == *(char *)((uint)local_a + (uint)local_9 * 0x5c + DAT_60093984 + 0x170)) &&
           (param_3 == *(char *)((uint)local_a + (uint)local_9 * 0x5c + DAT_60093984 + 0x173))) {
          FUN_6009633c((uint)local_a * 0x18 + (uint)local_9 * 0x5c + 0x128 + DAT_60093984);
          *(char *)((uint)local_9 * 0x5c + DAT_60093984 + 0x179) =
               *(char *)((uint)local_9 * 0x5c + DAT_60093984 + 0x179) + -1;
          *(undefined1 *)((uint)local_a + (uint)local_9 * 0x5c + DAT_60093984 + 0x176) = 0;
          *(undefined1 *)((uint)local_a + (uint)local_9 * 0x5c + DAT_60093984 + 0x170) = 0x32;
          *(undefined1 *)((uint)local_a + (uint)local_9 * 0x5c + DAT_60093984 + 0x173) = 0xff;
          if (*(char *)((uint)local_9 * 0x5c + DAT_60093984 + 0x179) == '\0') {
            *(undefined1 *)((uint)local_9 * 0x5c + DAT_60093984 + 0x180) = 0;
          }
          break;
        }
      }
    }
    local_9 = local_9 + 1;
  } while( true );
}


