// 600994b8  FUN_600994b8  size=194 bytes
// --- callers ---
//   600a96d8 FUN_600a96d8
//   600f22c2 FUN_600f22c2
// --- callees ---
//   60098f34 FUN_60098f34
//   600b26d0 FUN_600b26d0


void FUN_600994b8(undefined2 param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  byte bVar2;
  int iVar3;
  undefined2 *puVar4;
  
  bVar2 = FUN_60098f34(param_1);
  puVar1 = DAT_6009957c;
  if (3 < bVar2) {
    return;
  }
  puVar4 = (undefined2 *)((uint)bVar2 * 0x14c + 0x110 + DAT_60099580);
  *DAT_6009957c = param_2;
  if (*(char *)(puVar4 + 0x96) == '\x03') {
    if (*(char *)((int)puVar4 + 299) == '\x03') {
      *(undefined1 *)(puVar4 + 0x96) = 4;
      return;
    }
    iVar3 = FUN_600b26d0(*puVar4,1);
    if (iVar3 != 0) {
      *(undefined1 *)((int)puVar4 + 0x12d) = 3;
      *(undefined1 *)(puVar4 + 0x96) = 4;
      return;
    }
  }
  if (*(char *)(puVar4 + 0x96) == '\x05') {
    *(undefined1 *)(puVar4 + 0x96) = 0;
    *(undefined1 *)((int)puVar4 + 0x12d) = 0;
  }
  if (*(int *)(DAT_60099580 + 0x7dc) != 0) {
    (**(code **)(DAT_60099580 + 0x7dc))(puVar1);
    *(undefined4 *)(DAT_60099580 + 0x7dc) = 0;
  }
  return;
}


