// 600fc758  FUN_600fc758  size=114 bytes
// --- callers ---
// --- callees ---
//   600fcd40 FUN_600fcd40
//   600fc870 FUN_600fc870
//   600fccd0 FUN_600fccd0
//   600fce8c FUN_600fce8c
//   600fcd96 FUN_600fcd96


void FUN_600fc758(int param_1,undefined4 param_2)

{
  undefined1 auStack_24 [8];
  undefined1 auStack_1c [8];
  undefined1 auStack_14 [8];
  
  FUN_600fce8c(param_1);
  FUN_600fccd0(auStack_14,param_1);
  FUN_600fcd40(auStack_1c,param_1);
  FUN_600fcd96(auStack_24,param_1);
  FUN_600fc870(param_1 + 0x1a0,param_1 + 0x5d,param_1 + 0x4d,param_1 + 0xdd,auStack_14,auStack_1c,
               auStack_24,param_1 + 0xed,param_2);
  return;
}


