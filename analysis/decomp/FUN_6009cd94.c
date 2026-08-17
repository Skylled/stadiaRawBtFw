// 6009cd94  FUN_6009cd94  size=148 bytes
// --- callers ---
//   600c2f68 FUN_600c2f68
// --- callees ---


void FUN_6009cd94(ushort param_1,ushort param_2,char param_3)

{
  int iVar1;
  
  iVar1 = DAT_6009ce28;
  if ((((*(byte *)(DAT_6009ce2c + 0x81b) & 2) != 0) &&
      (((3 < param_1 && (param_1 < 0x4001)) || (param_1 == 0xffff)))) &&
     ((((3 < param_2 && (param_2 < 0x4001)) || (param_2 == 0xffff)) &&
      ((param_3 == '\x01' || (param_3 == '\0')))))) {
    *(char *)(DAT_6009ce28 + 8) = param_3;
    if (param_1 != 0xffff) {
      *(ushort *)(iVar1 + 6) = param_1;
    }
    if (param_2 != 0xffff) {
      *(ushort *)(iVar1 + 4) = param_2;
    }
  }
  return;
}


