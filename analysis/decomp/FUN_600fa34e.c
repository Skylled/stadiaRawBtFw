// 600fa34e  FUN_600fa34e  size=154 bytes
// --- callers ---
//   600bd4bc FUN_600bd4bc
//   600fa34e FUN_600fa34e
// --- callees ---
//   600bfc34 FUN_600bfc34
//   600bfb4c FUN_600bfb4c
//   600fa34e FUN_600fa34e


undefined4 FUN_600fa34e(byte *param_1,int param_2,undefined4 param_3,undefined2 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  byte *local_1c;
  int local_14;
  byte local_d;
  byte *local_c;
  
  local_c = param_1 + param_2;
  local_1c = param_1;
  if (param_5 < 4) {
    while (local_1c < local_c) {
      local_d = *local_1c;
      iVar1 = FUN_600bfb4c(local_1c + 1,local_d,&local_14);
      local_d = local_d >> 3;
      if (local_d == 3) {
        iVar2 = FUN_600bfc34(iVar1,local_14,param_3,param_4);
        if (iVar2 != 0) {
          return 1;
        }
      }
      else if ((local_d == 6) &&
              (iVar2 = FUN_600fa34e(iVar1,local_14,param_3,param_4,param_5 + 1), iVar2 != 0)) {
        return 1;
      }
      local_1c = (byte *)(local_14 + iVar1);
    }
  }
  return 0;
}


