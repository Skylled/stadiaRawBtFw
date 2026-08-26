// 6010258e  FUN_6010258e  size=26 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_6010258e(undefined4 *param_1,undefined1 *param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined1 *)0x0) {
    return 0;
  }
  if (param_3 < 0x100) {
    *param_2 = (char)param_3;
    uVar1 = 1;
  }
  else {
    *param_1 = 0x8a;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


