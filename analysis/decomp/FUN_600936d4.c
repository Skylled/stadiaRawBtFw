// 600936d4  FUN_600936d4  size=312 bytes
// --- callers ---
//   600ee33e FUN_600ee33e
// --- callees ---
//   600efcfe FUN_600efcfe
//   6009633c FUN_6009633c
//   600ee304 FUN_600ee304


void FUN_600936d4(undefined4 param_1,undefined1 param_2)

{
  byte bVar1;
  int iVar2;
  byte local_9;
  
  bVar1 = FUN_600ee304(param_2);
  if (bVar1 != 3) {
    for (local_9 = 0; local_9 < 3; local_9 = local_9 + 1) {
      if ((*(char *)((uint)local_9 * 0x5c + DAT_6009380c + 0x180) != '\0') &&
         (iVar2 = FUN_600efcfe((uint)local_9 * 0x5c + DAT_6009380c + 0x17a,param_1), iVar2 == 0)) {
        FUN_6009633c((uint)bVar1 * 0x18 + (uint)local_9 * 0x5c + 0x128 + DAT_6009380c);
        if (*(char *)((uint)bVar1 + (uint)local_9 * 0x5c + DAT_6009380c + 0x170) == '2') {
          return;
        }
        *(undefined1 *)((uint)bVar1 + (uint)local_9 * 0x5c + DAT_6009380c + 0x170) = 0x32;
        *(undefined1 *)((uint)bVar1 + (uint)local_9 * 0x5c + DAT_6009380c + 0x176) = param_2;
        *(char *)((uint)local_9 * 0x5c + DAT_6009380c + 0x179) =
             *(char *)((uint)local_9 * 0x5c + DAT_6009380c + 0x179) + -1;
        if (*(char *)((uint)local_9 * 0x5c + DAT_6009380c + 0x179) != '\0') {
          return;
        }
        *(undefined1 *)((uint)local_9 * 0x5c + DAT_6009380c + 0x180) = 0;
        return;
      }
    }
  }
  return;
}


