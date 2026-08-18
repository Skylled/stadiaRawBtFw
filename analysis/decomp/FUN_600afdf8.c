// 600afdf8  FUN_600afdf8  size=162 bytes
// --- callers ---
//   600ab620 FUN_600ab620
//   600f395a FUN_600f395a
//   600f39fc FUN_600f39fc
//   600ab778 FUN_600ab778
//   600f3b0a FUN_600f3b0a
// --- callees ---
//   600af7c8 FUN_600af7c8
//   600afd28 FUN_600afd28


undefined4 * FUN_600afdf8(undefined2 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  byte local_9;
  
  uVar1 = FUN_600af7c8((char)((ushort)param_1 >> 8));
  uVar2 = FUN_600afd28((char)param_1);
  local_9 = 0;
  while( true ) {
    if (5 < local_9) {
      return (undefined4 *)0x0;
    }
    if (*(char *)(DAT_600afe9c + (uint)local_9 * 0x60 + 0x12a4) == '\0') break;
    local_9 = local_9 + 1;
  }
  puVar3 = (undefined4 *)(DAT_600afe9c + (uint)local_9 * 0x60 + 0x1248);
  *(undefined1 *)(puVar3 + 0x17) = 1;
  *(undefined2 *)(puVar3 + 9) = param_1;
  *(ushort *)((int)puVar3 + 0x26) = (ushort)local_9;
  puVar3[1] = uVar2;
  *puVar3 = uVar1;
  return puVar3;
}


