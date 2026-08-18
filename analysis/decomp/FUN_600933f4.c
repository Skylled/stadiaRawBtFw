// 600933f4  FUN_600933f4  size=120 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600933f4(undefined2 *param_1)

{
  byte bVar1;
  int iVar2;
  int local_c;
  
  iVar2 = *(int *)(DAT_60093470 + (uint)*(ushort *)(DAT_6009346c + 0x18) * 4);
  *(ushort *)(DAT_6009346c + 0x18) = (ushort)*(byte *)((uint)(byte)*param_1 * 3 + iVar2 + 2);
  for (local_c = 0;
      (local_c < 2 && (bVar1 = *(byte *)(local_c + iVar2 + (uint)(byte)*param_1 * 3), bVar1 != 0x13)
      ); local_c = local_c + 1) {
    (**(code **)(DAT_60093474 + (uint)bVar1 * 4))(param_1);
  }
  return 1;
}


