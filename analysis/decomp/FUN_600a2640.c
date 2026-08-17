// 600a2640  FUN_600a2640  size=168 bytes
// --- callers ---
//   6009e4d0 FUN_6009e4d0
//   600a2ab0 FUN_600a2ab0
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 FUN_600a2640(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  ushort local_e;
  int *local_c;
  
  iVar1 = DAT_600a26e8;
  local_c = *(int **)(DAT_600a26e8 + 0x60);
  if (((*(byte *)(DAT_600a26e8 + 0x61e) & 8) == 0) && (local_c != (int *)0x0)) {
    for (local_e = 0; local_e < *(ushort *)(iVar1 + 100); local_e = local_e + 1) {
      iVar2 = thunk_EXT_FUN_0000b554(local_c + 1,param_1,6);
      if ((iVar2 == 0) && (*local_c == *(int *)(iVar1 + 0x44))) {
        return 1;
      }
      local_c = local_c + 3;
    }
    if (local_e < *(ushort *)(iVar1 + 0x66)) {
      *local_c = *(int *)(iVar1 + 0x44);
      thunk_EXT_FUN_0000b572(local_c + 1,param_1,6);
      *(short *)(iVar1 + 100) = *(short *)(iVar1 + 100) + 1;
    }
  }
  return 0;
}


