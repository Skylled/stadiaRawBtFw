// 600d4a7e  FUN_600d4a7e  size=92 bytes
// --- callers ---
//   600d6c76 FUN_600d6c76
// --- callees ---
//   601017e8 FUN_601017e8
//   600600c4 pwm__600600c4
//   6013d178 thunk_EXT_FUN_00008996
//   6005fe04 io_pin__6005fe04
//   6006012c pwm__6006012c
//   60053d08 FUN_60053d08
//   600cf3c2 FUN_600cf3c2


void FUN_600d4a7e(undefined1 *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_1c [6];
  undefined1 local_16;
  
  FUN_601017e8(param_1 + 0x68);
  if (param_1[10] != '\0') {
    io_pin__6005fe04(param_1 + 0xc);
  }
  if (param_1[0x38] != '\0') {
    io_pin__6005fe04(param_1 + 0x3c);
  }
  FUN_600cf3c2(auStack_1c);
  local_16 = param_1[9];
  uVar2 = pwm__6006012c(*(undefined4 *)(param_1 + 4));
  uVar3 = pwm__600600c4(param_1[8]);
  FUN_60053d08(uVar2,uVar3,auStack_1c);
  cVar1 = thunk_EXT_FUN_00008996();
  if (cVar1 == '\0') {
    *param_1 = 1;
  }
  return;
}


