// 600fa3e8  FUN_600fa3e8  size=88 bytes
// --- callers ---
//   600beb20 FUN_600beb20
//   600be558 FUN_600be558
//   600fa73c FUN_600fa73c
// --- callees ---


int FUN_600fa3e8(int param_1,ushort param_2,ushort param_3)

{
  int iVar1;
  ushort local_e;
  int local_c;
  
  local_e = 0;
  iVar1 = param_1;
  while( true ) {
    local_c = iVar1 + 0xc;
    if (*(ushort *)(param_1 + 8) <= local_e) {
      return 0;
    }
    if ((param_2 <= *(ushort *)(iVar1 + 0x14)) && (*(ushort *)(iVar1 + 0x14) <= param_3)) break;
    local_e = local_e + 1;
    iVar1 = local_c;
  }
  return local_c;
}


