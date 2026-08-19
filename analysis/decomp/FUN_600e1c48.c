// 600e1c48  FUN_600e1c48  size=74 bytes
// --- callers ---
//   600e1d72 FUN_600e1d72
// --- callees ---
//   600e1c1c FUN_600e1c1c
//   600875a0 FUN_600875a0
//   600e0e02 FUN_600e0e02


void FUN_600e1c48(int param_1,int param_2)

{
  char local_a8 [32];
  undefined1 auStack_88 [40];
  undefined1 auStack_60 [40];
  undefined1 auStack_38 [44];
  
  FUN_600e1c1c(auStack_88,param_2 + 0x50);
  FUN_600e0e02(auStack_60,param_2,auStack_88);
  FUN_600e0e02(auStack_38,param_2 + 0x28,auStack_88);
  FUN_600875a0(param_1,auStack_38);
  FUN_600875a0(local_a8,auStack_60);
  *(byte *)(param_1 + 0x1f) = *(byte *)(param_1 + 0x1f) ^ local_a8[0] << 7;
  return;
}


