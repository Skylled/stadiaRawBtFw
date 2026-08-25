// 600fa064  FUN_600fa064  size=114 bytes
// --- callers ---
//   600f9df0 FUN_600f9df0
// --- callees ---
//   60099fdc FUN_60099fdc


void FUN_600fa064(int param_1)

{
  ushort uVar1;
  
  uVar1 = FUN_60099fdc(*(int *)(param_1 + 300) + 4);
  if (uVar1 < 0xb) {
    *(undefined2 *)(param_1 + 0x118) = *(undefined2 *)(param_1 + 0x86);
  }
  else {
    uVar1 = uVar1 - 10;
    if (*(ushort *)(param_1 + 0x86) < uVar1) {
      *(undefined2 *)(param_1 + 0x118) = *(undefined2 *)(param_1 + 0x86);
    }
    else {
      *(ushort *)(param_1 + 0x118) = uVar1 * (*(ushort *)(param_1 + 0x86) / uVar1);
    }
  }
  return;
}


