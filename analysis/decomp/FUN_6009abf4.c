// 6009abf4  FUN_6009abf4  size=148 bytes
// --- callers ---
//   600fd356 FUN_600fd356
// --- callees ---
//   6009c6d8 FUN_6009c6d8


void FUN_6009abf4(ushort param_1,ushort param_2)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  
  iVar1 = DAT_6009ac88;
  if ((((3 < param_1) && (param_1 < 0x4001)) || (param_1 == 0xffff)) &&
     (((3 < param_2 && (param_2 < 0x4001)) || (param_2 == 0xffff)))) {
    bVar2 = param_1 != *(ushort *)(DAT_6009ac88 + 0xea);
    if (bVar2) {
      *(ushort *)(DAT_6009ac88 + 0xea) = param_1;
    }
    bVar3 = param_2 != *(ushort *)(iVar1 + 0xec);
    if (bVar3) {
      *(ushort *)(iVar1 + 0xec) = param_2;
    }
    if ((bVar3 || bVar2) && (*(char *)(iVar1 + 0x160) == '\x02')) {
      FUN_6009c6d8();
    }
  }
  return;
}


