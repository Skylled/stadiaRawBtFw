// 600cf1e6  FUN_600cf1e6  size=26 bytes
// --- callers ---
//   600cf2be FUN_600cf2be
// --- callees ---


int FUN_600cf1e6(undefined4 param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  
  if (*(ushort *)(param_2 + 0x20) < *(ushort *)(param_2 + 0x22)) {
    uVar1 = *(ushort *)(param_2 + 0x22);
    uVar2 = *(int *)(param_2 + 0x1c) + (uint)*(ushort *)(param_2 + 0x20);
  }
  else {
    uVar2 = (uint)*(ushort *)(param_2 + 0x20);
    uVar1 = *(ushort *)(param_2 + 0x22);
  }
  return uVar2 - uVar1;
}


