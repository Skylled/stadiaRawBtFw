// 6009362c  FUN_6009362c  size=162 bytes
// --- callers ---
//   600ee33e FUN_600ee33e
// --- callees ---
//   600efcfe FUN_600efcfe
//   6009633c FUN_6009633c


void FUN_6009362c(undefined4 param_1)

{
  int iVar1;
  byte local_a;
  byte local_9;
  
  local_9 = 0;
  while( true ) {
    if (2 < local_9) {
      return;
    }
    if ((*(char *)((uint)local_9 * 0x5c + DAT_600936d0 + 0x180) != '\0') &&
       (iVar1 = FUN_600efcfe((uint)local_9 * 0x5c + DAT_600936d0 + 0x17a,param_1), iVar1 == 0))
    break;
    local_9 = local_9 + 1;
  }
  for (local_a = 0; local_a < 3; local_a = local_a + 1) {
    FUN_6009633c((uint)local_a * 0x18 + (uint)local_9 * 0x5c + 0x128 + DAT_600936d0);
  }
  *(undefined1 *)((uint)local_9 * 0x5c + DAT_600936d0 + 0x180) = 0;
  return;
}


