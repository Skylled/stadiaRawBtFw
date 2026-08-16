// 600950bc  FUN_600950bc  size=218 bytes
// --- callers ---
//   600ef390 FUN_600ef390
//   600fed9e FUN_600fed9e
//   600feba8 FUN_600feba8
//   600ef900 FUN_600ef900
// --- callees ---
//   600efcc6 FUN_600efcc6
//   60094f58 FUN_60094f58
//   6009519c FUN_6009519c
//   60095234 FUN_60095234


int FUN_600950bc(undefined1 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  int iVar2;
  byte local_9;
  
  local_9 = 0;
  while( true ) {
    if (5 < local_9) {
      return 0;
    }
    if (*(char *)((uint)local_9 * 0x20 + DAT_60095198 + 0x4ab) == '\0') break;
    local_9 = local_9 + 1;
  }
  iVar2 = (uint)local_9 * 0x20 + 0x490 + DAT_60095198;
  *(undefined1 *)(iVar2 + 0x1b) = 1;
  *(undefined1 *)(iVar2 + 0x1d) = 0;
  *(undefined1 *)(iVar2 + 8) = param_3;
  FUN_600efcc6(iVar2 + 2,param_2);
  uVar1 = FUN_60094f58(param_1);
  *(undefined4 *)(iVar2 + 0xc) = uVar1;
  uVar1 = FUN_6009519c(param_2);
  *(undefined4 *)(iVar2 + 0x10) = uVar1;
  if (*(int *)(iVar2 + 0x10) == 0) {
    uVar1 = FUN_60095234(param_2);
    *(undefined4 *)(iVar2 + 0x10) = uVar1;
  }
  if ((*(int *)(iVar2 + 0xc) != 0) && (*(int *)(iVar2 + 0x10) != 0)) {
    *(char *)(*(int *)(iVar2 + 0x10) + 0x27) = *(char *)(*(int *)(iVar2 + 0x10) + 0x27) + '\x01';
    *(char *)(*(int *)(iVar2 + 0xc) + 6) = *(char *)(*(int *)(iVar2 + 0xc) + 6) + '\x01';
    return iVar2;
  }
  *(undefined1 *)(iVar2 + 0x1b) = 0;
  return 0;
}


