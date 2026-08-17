// 60094d24  FUN_60094d24  size=152 bytes
// --- callers ---
//   600fdf94 FUN_600fdf94
//   600fda2c FUN_600fda2c
//   600c64c8 FUN_600c64c8
//   600feba8 FUN_600feba8
//   600fe432 FUN_600fe432
//   600fd8c4 FUN_600fd8c4
//   600fd83a FUN_600fd83a
//   60094ba4 FUN_60094ba4
//   600fdcfc FUN_600fdcfc
//   600c66e8 FUN_600c66e8
//   60094dc4 FUN_60094dc4
//   600fed9e FUN_600fed9e
//   600c6318 FUN_600c6318
//   600fdab8 FUN_600fdab8
//   600c67ac FUN_600c67ac
//   600fe146 FUN_600fe146
//   600c63e0 FUN_600c63e0
//   600fe1ea FUN_600fe1ea
//   600fe00e FUN_600fe00e
// --- callees ---


undefined1 FUN_60094d24(int param_1,ushort param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined1 local_d;
  int local_c;
  
  local_d = 1;
  iVar2 = *(int *)(DAT_60094dbc + (uint)*(byte *)(param_1 + 0x1c) * 4);
  *(undefined1 *)(param_1 + 0x1c) = *(undefined1 *)((uint)(param_2 & 0xff) * 2 + iVar2 + 1);
  for (local_c = 0;
      (local_c < 1 &&
      (bVar1 = *(byte *)(local_c + iVar2 + (uint)(param_2 & 0xff) * 2), bVar1 != 0x1c));
      local_c = local_c + 1) {
    (**(code **)(DAT_60094dc0 + (uint)bVar1 * 4))(param_1,param_3);
    if ((*(byte *)(param_1 + 0x18) & 1) != 0) {
      *(byte *)(param_1 + 0x18) = *(byte *)(param_1 + 0x18) & 0xfe;
      local_d = 0;
    }
  }
  return local_d;
}


