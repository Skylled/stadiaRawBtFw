// 600d332a  FUN_600d332a  size=34 bytes
// --- callers ---
//   600d25f4 FUN_600d25f4
//   60055d78 FUN_60055d78
//   600d265a FUN_600d265a
//   600d194a FUN_600d194a
//   60055bd8 FUN_60055bd8
//   600d2140 FUN_600d2140
//   600d1ee0 FUN_600d1ee0
//   600d206c FUN_600d206c
// --- callees ---


undefined4 FUN_600d332a(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if ((param_1 == (undefined4 *)0x0) || (param_2 == 0)) {
    uVar1 = 3;
  }
  else {
    local_10 = param_2;
    uStack_c = param_3;
    uStack_8 = param_3;
    uVar1 = (**(code **)(param_1[0xb4] + 0x18))(*param_1,1,&local_10);
  }
  return uVar1;
}


