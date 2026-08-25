// 600f7a34  FUN_600f7a34  size=52 bytes
// --- callers ---
//   600f5db4 FUN_600f5db4
//   600fa5a6 FUN_600fa5a6
//   600f592e FUN_600f592e
//   600f5e3c FUN_600f5e3c
// --- callees ---
//   600b5e00 FUN_600b5e00
//   600bcc30 FUN_600bcc30


bool FUN_600f7a34(undefined2 param_1)

{
  int iVar1;
  
  iVar1 = FUN_600bcc30(0,param_1);
  if (iVar1 != 0) {
    FUN_600b5e00(iVar1,0x1b,0);
  }
  return iVar1 != 0;
}


