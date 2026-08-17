// 600b4ed0  FUN_600b4ed0  size=96 bytes
// --- callers ---
//   60132bb4 FUN_60132bb4
// --- callees ---
//   600bcc30 FUN_600bcc30


undefined4 FUN_600b4ed0(undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined2 param_4)

{
  undefined4 uVar1;
  int unaff_r7;
  
  *(undefined2 *)(unaff_r7 + 4) = param_4;
  *(undefined1 *)(unaff_r7 + 3) = param_3;
  if (*(char *)(unaff_r7 + 3) == '\0') {
    uVar1 = FUN_600bcc30(0,*(undefined2 *)(unaff_r7 + 6));
    *(undefined4 *)(unaff_r7 + 0xc) = uVar1;
    if (*(int *)(unaff_r7 + 0xc) == 0) {
      return 0;
    }
    *(undefined4 *)(unaff_r7 + 8) = *(undefined4 *)(*(int *)(unaff_r7 + 0xc) + 300);
    if (((*(int *)(unaff_r7 + 8) == 0) || (**(char **)(unaff_r7 + 8) == '\0')) ||
       (*(char *)(*(int *)(unaff_r7 + 8) + 1) != '\x04')) {
      return 0;
    }
    *(undefined2 *)(*(int *)(unaff_r7 + 8) + 0x14) = *(undefined2 *)(unaff_r7 + 4);
  }
  else {
    *(undefined2 *)(DAT_600b4f30 + 0xea0) = *(undefined2 *)(unaff_r7 + 4);
  }
  return 1;
}


