// 600ef5be  FUN_600ef5be  size=138 bytes
// --- callers ---
//   600feba8 FUN_600feba8
// --- callees ---
//   600efcfe FUN_600efcfe
//   600ef57c FUN_600ef57c


undefined4 FUN_600ef5be(int param_1,int param_2,int param_3)

{
  int iVar1;
  byte local_9;
  
  local_9 = 0;
  while( true ) {
    if (3 < local_9) {
      return 0;
    }
    if (((*(char *)((uint)local_9 * 0x3c + param_1 + 0x1c) != '\0') &&
        (iVar1 = FUN_600efcfe((uint)local_9 * 0x3c + param_1 + 0x1d,param_2 + 1), iVar1 == 0)) &&
       (iVar1 = FUN_600ef57c((uint)local_9 * 0x3c + param_1 + 0x24,param_3 + 8), iVar1 != 0)) break;
    local_9 = local_9 + 1;
  }
  return 1;
}


