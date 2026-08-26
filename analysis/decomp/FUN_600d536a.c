// 600d536a  FUN_600d536a  size=28 bytes
// --- callers ---
// --- callees ---
//   600d5364 FUN_600d5364


void FUN_600d536a(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 0x7c) = *param_2;
  *(undefined4 *)(param_1 + 0x80) = uVar1;
  if (*(char *)(param_1 + 0xac) != '\0') {
    FUN_600d5364((undefined4 *)(param_1 + 0x7c));
  }
  return;
}


