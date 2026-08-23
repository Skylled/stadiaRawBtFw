// 600ed722  FUN_600ed722  size=26 bytes
// --- callers ---
// --- callees ---
//   600ed3ba FUN_600ed3ba


bool FUN_600ed722(undefined4 param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack_c;
  
  uStack_c = param_2;
  iVar1 = FUN_600ed3ba(param_1,(int)&uStack_c + 3,param_3,param_4,param_1);
  if (iVar1 != 0) {
    *param_2 = (uint)uStack_c >> 0x18;
  }
  return iVar1 != 0;
}


