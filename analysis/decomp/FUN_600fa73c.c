// 600fa73c  FUN_600fa73c  size=162 bytes
// --- callers ---
//   600beb20 FUN_600beb20
//   600fa6e0 FUN_600fa6e0
//   600be558 FUN_600be558
// --- callees ---
//   600bfe2c FUN_600bfe2c
//   600fa3e8 FUN_600fa3e8


short FUN_600fa73c(undefined4 param_1,ushort *param_2)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  ushort local_12;
  ushort local_10;
  ushort local_c;
  short local_a;
  
  local_a = 0;
  bVar1 = false;
  local_10 = 0;
  local_12 = 0;
  for (local_c = 0; local_c < *param_2; local_c = local_c + 1) {
    if (!bVar1) {
      local_10 = param_2[(uint)local_c * 2 + 1];
      local_12 = param_2[(uint)local_c * 2 + 2];
    }
    iVar3 = FUN_600fa3e8(param_1,local_10,local_12);
    if (iVar3 == 0) {
      bVar1 = false;
    }
    else {
      sVar2 = FUN_600bfe2c(iVar3);
      local_a = local_a + sVar2;
      if (local_10 == local_12) {
        bVar1 = false;
      }
      else {
        local_10 = *(short *)(iVar3 + 8) + 1;
        local_c = local_c - 1;
        bVar1 = true;
      }
    }
  }
  return local_a;
}


