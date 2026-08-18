// 600d0dfc  FUN_600d0dfc  size=26 bytes
// --- callers ---
//   600551b8 FUN_600551b8
// --- callees ---
//   600d0c3c FUN_600d0c3c


undefined4 FUN_600d0dfc(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 3;
  }
  else {
    uVar1 = FUN_600d0c3c();
    *param_1 = 0;
    param_1[1] = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)((int)param_1 + 0xe) = 0;
  }
  return uVar1;
}


