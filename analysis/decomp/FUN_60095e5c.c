// 60095e5c  FUN_60095e5c  size=126 bytes
// --- callers ---
// --- callees ---


undefined1 FUN_60095e5c(undefined2 *param_1)

{
  byte bVar1;
  int iVar2;
  int local_c;
  
  iVar2 = *(int *)(DAT_60095ee0 + (uint)*(byte *)(DAT_60095edc + 0x116) * 4);
  *(undefined1 *)(DAT_60095edc + 0x116) = *(undefined1 *)((uint)(byte)*param_1 * 3 + iVar2 + 2);
  for (local_c = 0;
      (local_c < 2 && (bVar1 = *(byte *)(local_c + iVar2 + (uint)(byte)*param_1 * 3), bVar1 != 6));
      local_c = local_c + 1) {
    (**(code **)(DAT_60095ee4 + (uint)bVar1 * 4))(param_1);
  }
  return 1;
}


