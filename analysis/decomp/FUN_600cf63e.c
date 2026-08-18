// 600cf63e  FUN_600cf63e  size=32 bytes
// --- callers ---
//   600cf8de FUN_600cf8de
//   600cfa22 FUN_600cfa22
// --- callees ---


void FUN_600cf63e(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = DAT_60053f18;
  if (param_2 != 0) {
    if (*(uint *)(param_1 + 0x90) >> 0x1e == 1) {
      *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & DAT_60053f18 | 0x80000000;
    }
    *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & uVar1 | 0x80000000;
    *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xffe3ffff | 0x40000;
    return;
  }
  if (*(uint *)(param_1 + 0x10) >> 0x1e != 1) {
    *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0x7fe3ffff;
  }
  return;
}


