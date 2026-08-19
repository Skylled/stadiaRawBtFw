// 600de3de  FUN_600de3de  size=34 bytes
// --- callers ---
//   6007dfcc FUN_6007dfcc
//   600ddd92 FUN_600ddd92
//   600ddcc4 FUN_600ddcc4
// --- callees ---
//   6007df4c FUN_6007df4c


void FUN_600de3de(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(uint *)(param_1 + 4) <= param_2) {
    param_2 = *(uint *)(param_1 + 4);
  }
  *(uint *)(param_1 + 0x14) = param_2;
  if (param_3 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 8);
  }
  else {
    *(uint *)(param_1 + 0x18) = param_2;
    *(uint *)(param_1 + 0x10) = param_2;
    FUN_6007df4c();
    uVar1 = 0;
  }
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  return;
}


