// 600d2762  FUN_600d2762  size=82 bytes
// --- callers ---
//   60057c78 FUN_60057c78
//   600d29b8 FUN_600d29b8
//   600d2bb0 FUN_600d2bb0
// --- callees ---
//   600d16ae FUN_600d16ae
//   600d1692 FUN_600d1692


int FUN_600d2762(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  *param_3 = 0;
  puVar1 = param_2;
  while( true ) {
    iVar2 = iVar2 + (*(ushort *)((int)puVar1 + 10) & 0x7fff);
    if (puVar1 == param_3) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_600d1692(*(undefined4 *)(param_1 + 0x3c));
  if (*(char *)(param_1 + 0x49) == '\0') {
    *(undefined4 **)(param_1 + 0x10) = param_2;
  }
  else {
    **(undefined4 **)(param_1 + 0x14) = param_2;
  }
  *(undefined4 **)(param_1 + 0x14) = puVar1;
  while( true ) {
    *(char *)(param_1 + 0x49) = *(char *)(param_1 + 0x49) + '\x01';
    if (param_2 == puVar1) break;
    param_2 = (undefined4 *)*param_2;
  }
  FUN_600d16ae(*(undefined4 *)(param_1 + 0x3c));
  return iVar2;
}


