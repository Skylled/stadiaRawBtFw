// 600d540c  FUN_600d540c  size=48 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600d540c(int param_1,int param_2,undefined4 *param_3,undefined1 *param_4)

{
  if (param_2 == 9) {
    *param_4 = 1;
    func_0x60062634();
  }
  else if ((param_2 == 0xf) && (param_3 != (undefined4 *)0x0)) {
    *param_3 = *(undefined4 *)(param_1 + 0x1c);
    param_3[1] = *(undefined4 *)(param_1 + 0x20);
    *(undefined1 *)(param_3 + 2) = 3;
    *param_4 = 1;
  }
  return 0;
}


