// 600c7bac  FUN_600c7bac  size=182 bytes
// --- callers ---
//   600ffada FUN_600ffada
// --- callees ---
//   6006dbac FUN_6006dbac


int FUN_600c7bac(ushort param_1,ushort param_2,int param_3)

{
  int iVar1;
  undefined1 *puVar2;
  byte local_d;
  undefined1 *local_c;
  
  iVar1 = FUN_6006dbac(((ushort)(param_2 + 0xb) & 0x7fff) << 1,DAT_600c7c64,199);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 4) = 0xd;
    *(undefined2 *)(iVar1 + 2) = 1;
    local_c = (undefined1 *)(iVar1 + 0x16);
    *(undefined1 *)(iVar1 + 0x15) = 0xe;
    local_d = 0;
    while ((local_d < param_2 && (*(ushort *)(iVar1 + 2) + 2 <= (uint)param_1))) {
      puVar2 = local_c + 1;
      *local_c = (char)*(undefined2 *)((uint)local_d * 2 + param_3);
      local_c = local_c + 2;
      *puVar2 = (char)((ushort)*(undefined2 *)((uint)local_d * 2 + param_3) >> 8);
      *(short *)(iVar1 + 2) = *(short *)(iVar1 + 2) + 2;
      local_d = local_d + 1;
    }
  }
  return iVar1;
}


