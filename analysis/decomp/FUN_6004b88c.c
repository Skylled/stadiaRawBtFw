// 6004b88c  FUN_6004b88c  size=30 bytes
// --- callers ---
// --- callees ---
//   6004b47a FUN_6004b47a
//   6004b884 FUN_6004b884


undefined4 FUN_6004b88c(int param_1)

{
  FUN_6004b47a(*(undefined4 *)(param_1 + 4));
  if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 8));
  }
  FUN_6004b884(param_1);
  return 1;
}


