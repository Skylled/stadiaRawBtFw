// 600fca7c  FUN_600fca7c  size=58 bytes
// --- callers ---
//   600fcab6 FUN_600fcab6
//   600fb686 FUN_600fb686
// --- callees ---
//   600fcf26 FUN_600fcf26
//   600b4f34 FUN_600b4f34
//   600aa3cc FUN_600aa3cc
//   600fca48 FUN_600fca48


void FUN_600fca7c(int param_1)

{
  FUN_600aa3cc(param_1 + 4);
  *(undefined2 *)(param_1 + 0x28) = 0;
  FUN_600b4f34(param_1 + 0x1d,3,2);
  FUN_600fcf26(param_1);
  FUN_600fca48(param_1);
  return;
}


