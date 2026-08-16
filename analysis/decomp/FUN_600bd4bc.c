// 600bd4bc  FUN_600bd4bc  size=310 bytes
// --- callers ---
//   600be150 FUN_600be150
//   600beb20 FUN_600beb20
//   600fa6e0 FUN_600fa6e0
// --- callees ---
//   600bfc34 FUN_600bfc34
//   600fa34e FUN_600fa34e


undefined4 * FUN_600bd4bc(int param_1,ushort *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *local_24;
  undefined4 *local_18;
  ushort local_14;
  ushort local_12;
  
  iVar3 = (uint)*(ushort *)(DAT_600bd5f4 + 0x102) * 0x1cc + DAT_600bd5f4;
  if (param_1 == 0) {
    local_24 = DAT_600bd5f8;
  }
  else {
    local_24 = (undefined4 *)(param_1 + 0x1cc);
  }
  do {
    if ((undefined4 *)(iVar3 + 0x104U) <= local_24) {
      return (undefined4 *)0x0;
    }
    for (local_14 = 0; local_14 < *param_2; local_14 = local_14 + 1) {
      puVar1 = local_24;
      for (local_12 = 0; local_18 = puVar1 + 3, local_12 < *(ushort *)(local_24 + 2);
          local_12 = local_12 + 1) {
        if (*(char *)((int)puVar1 + 0x16) == '\x03') {
          iVar2 = FUN_600bfc34(puVar1[4],*local_18,param_2 + (uint)local_14 * 9 + 2,
                               param_2[(uint)local_14 * 9 + 1]);
joined_r0x600bd590:
          if (iVar2 != 0) break;
        }
        else if (*(char *)((int)puVar1 + 0x16) == '\x06') {
          iVar2 = FUN_600fa34e(puVar1[4],*local_18,param_2 + (uint)local_14 * 9 + 2,
                               param_2[(uint)local_14 * 9 + 1],0);
          goto joined_r0x600bd590;
        }
        puVar1 = local_18;
      }
      if (local_12 == *(ushort *)(local_24 + 2)) break;
    }
    if (local_14 == *param_2) {
      return local_24;
    }
    local_24 = local_24 + 0x73;
  } while( true );
}


