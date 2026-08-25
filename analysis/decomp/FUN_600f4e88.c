// 600f4e88  FUN_600f4e88  size=78 bytes
// --- callers ---
//   600ab110 FUN_600ab110
// --- callees ---
//   600ad494 FUN_600ad494
//   600f57f6 FUN_600f57f6


undefined4
FUN_600f4e88(int param_1,undefined4 param_2,undefined1 param_3,short param_4,short param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600ad494(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(short *)(param_1 + 0x1a) = param_4;
    *(short *)(param_1 + 0x18) = param_5 + param_4;
    uVar2 = FUN_600f57f6(param_1,param_2,param_3);
  }
  return uVar2;
}


