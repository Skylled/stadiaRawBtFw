// 600e9542  FUN_600e9542  size=58 bytes
// --- callers ---
//   600e96c6 FUN_600e96c6
// --- callees ---
//   600e7930 FUN_600e7930
//   6010209a FUN_6010209a
//   600e80e2 FUN_600e80e2


void FUN_600e9542(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 int param_6)

{
  if (param_4 + param_6 != param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_6010209a();
  }
  if ((param_4 == 8) && (param_6 == 8)) {
    FUN_600e80e2(param_1,param_3,param_5);
    return;
  }
  FUN_600e7930(param_1,param_3);
  return;
}


