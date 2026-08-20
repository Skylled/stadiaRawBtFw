// 600e652a  FUN_600e652a  size=20 bytes
// --- callers ---
//   600eb588 FUN_600eb588
//   6008d3d4 FUN_6008d3d4
//   6008aad8 FUN_6008aad8
//   600e66be FUN_600e66be
//   6008dc2c FUN_6008dc2c
// --- callees ---


void FUN_600e652a(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_2 + -4);
  puVar1 = (undefined4 *)(param_1 + -4);
  do {
    puVar2 = puVar2 + 1;
    puVar1 = puVar1 + 1;
    *puVar1 = *puVar2;
  } while (puVar2 != (undefined4 *)(param_2 + 0x1c));
  return;
}


