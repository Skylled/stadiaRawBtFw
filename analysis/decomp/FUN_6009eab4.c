// 6009eab4  FUN_6009eab4  size=170 bytes
// --- callers ---
//   600f3022 FUN_600f3022
// --- callees ---
//   600f7ca0 FUN_600f7ca0


void FUN_6009eab4(char *param_1)

{
  char cVar1;
  int iVar2;
  char *local_24;
  int local_18;
  short *local_14;
  
  local_14 = DAT_6009eb60;
  cVar1 = *param_1;
  local_18 = 0;
  while( true ) {
    if (3 < local_18) {
      return;
    }
    if (((char)local_14[0x94] != '\0') &&
       ((ushort)((ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1]) == *local_14)) break;
    local_18 = local_18 + 1;
    local_14 = local_14 + 0xa6;
  }
  if (cVar1 == '\0') {
    local_24 = param_1 + 3;
    for (iVar2 = 0; iVar2 < 8; iVar2 = iVar2 + 1) {
      *(char *)((int)local_14 + iVar2 + 0x13d) = *local_24;
      local_24 = local_24 + 1;
    }
  }
  if ((cVar1 != '>') && (cVar1 != '\b')) {
    FUN_600f7ca0(local_14 + 3);
  }
  return;
}


