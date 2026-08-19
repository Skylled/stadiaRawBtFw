// 600de54a  FUN_600de54a  size=56 bytes
// --- callers ---
// --- callees ---
//   600de6e8 FUN_600de6e8
//   600de534 FUN_600de534


void FUN_600de54a(int param_1,int param_2)

{
  undefined4 extraout_r1;
  
  if (*(int *)(param_2 + 4) != 0) {
    FUN_600de6e8(param_1 + 0x78);
    *(undefined1 *)(param_1 + 0x74) = 0;
    *(undefined1 *)(param_1 + 0xd) = 1;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x6c) = 0;
    *(undefined4 *)(param_1 + 0x70) = 0;
    FUN_600de534(param_1 + 0x2c);
    *(char *)(param_1 + 0x58) = (char)extraout_r1;
    *(undefined4 *)(param_1 + 0x5c) = extraout_r1;
  }
  func_0x600dea44(param_1 + 0xcc);
  return;
}


