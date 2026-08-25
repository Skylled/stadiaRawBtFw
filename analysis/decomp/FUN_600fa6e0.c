// 600fa6e0  FUN_600fa6e0  size=92 bytes
// --- callers ---
//   600beb20 FUN_600beb20
// --- callees ---
//   600bd4bc FUN_600bd4bc
//   600fa73c FUN_600fa73c


short FUN_600fa6e0(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  short local_e;
  int local_c;
  
  local_e = 0;
  for (local_c = FUN_600bd4bc(0,param_1); local_c != 0; local_c = FUN_600bd4bc(local_c,param_1)) {
    sVar1 = FUN_600fa73c(local_c,param_2);
    if (sVar1 != 0) {
      local_e = sVar1 + local_e + 3;
    }
  }
  return local_e;
}


