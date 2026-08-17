// 600c1b20  FUN_600c1b20  size=78 bytes
// --- callers ---
//   600c239c FUN_600c239c
//   600c1b74 FUN_600c1b74
// --- callees ---
//   600b5264 FUN_600b5264


bool FUN_600c1b20(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  *(short *)(DAT_600c1b70 + 0x1fe) = *(short *)(DAT_600c1b70 + 0x1fe) + 1;
  iVar1 = FUN_600b5264(6,param_1,param_2);
  if (iVar1 == 0) {
    *(short *)(DAT_600c1b70 + 0x1fe) = *(short *)(DAT_600c1b70 + 0x1fe) + -1;
  }
  return iVar1 != 0;
}


