// 600d53c4  FUN_600d53c4  size=52 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600d53c4(undefined4 param_1,int param_2,undefined1 *param_3,undefined1 *param_4)

{
  int iVar1;
  
  if (param_2 == 9) {
    *param_4 = 1;
    func_0x60061e70();
  }
  else if (((param_2 == 10) && (param_3 != (undefined1 *)0x0)) &&
          (iVar1 = func_0x60062124(param_1,param_3[1],*param_3,param_4,param_4), iVar1 != 0)) {
    *param_4 = 1;
  }
  return 0;
}


