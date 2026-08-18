// 600d265a  FUN_600d265a  size=74 bytes
// --- callers ---
//   60055fbc FUN_60055fbc
//   600563b8 FUN_600563b8
//   600d26a4 FUN_600d26a4
//   600d3202 FUN_600d3202
// --- callees ---
//   600d332a FUN_600d332a
//   600d2246 FUN_600d2246
//   600d22c8 FUN_600d22c8
//   600d25f4 FUN_600d25f4


undefined1 FUN_600d265a(int param_1,int param_2)

{
  undefined1 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar1 = 3;
  }
  else {
    *(undefined1 *)(param_2 + 0x43e) = 0;
    if (*(byte *)(param_2 + 0x438) == 0) {
      uVar1 = 0;
    }
    else {
      if (*(byte *)(param_2 + 0x438) < 9) {
        if (*(int *)(param_2 + 0x418) != 0) {
          FUN_600d332a(param_1,*(int *)(param_2 + 0x418),0);
        }
        FUN_600d2246(param_1,param_2);
        FUN_600d25f4(param_1);
      }
      else {
        FUN_600d22c8(param_2,2);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


