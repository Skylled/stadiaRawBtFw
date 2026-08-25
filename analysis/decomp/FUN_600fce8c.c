// 600fce8c  FUN_600fce8c  size=154 bytes
// --- callers ---
//   600fc758 FUN_600fc758
// --- callees ---
//   600fcd40 FUN_600fcd40
//   600c13e8 FUN_600c13e8
//   600fcd96 FUN_600fcd96


bool FUN_600fce8c(int param_1)

{
  int iVar1;
  undefined1 auStack_20 [8];
  undefined1 auStack_18 [8];
  int local_10;
  int local_c;
  
  if (*(char *)(param_1 + 0x26) == '\0') {
    FUN_600fcd40(auStack_18,param_1);
    FUN_600fcd96(auStack_20,param_1);
    local_c = param_1 + 0x5d;
    local_10 = param_1 + 0x4d;
  }
  else {
    FUN_600fcd40(auStack_20,param_1);
    FUN_600fcd96(auStack_18,param_1);
    local_c = param_1 + 0x4d;
    local_10 = param_1 + 0x5d;
  }
  iVar1 = FUN_600c13e8(param_1 + 0x8d,local_c,local_10,auStack_18,auStack_20,param_1 + 0x1a0,
                       param_1 + 0x1c6);
  return iVar1 != 0;
}


