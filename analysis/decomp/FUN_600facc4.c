// 600facc4  FUN_600facc4  size=98 bytes
// --- callers ---
// --- callees ---
//   600fa7de FUN_600fa7de
//   6009ad00 FUN_6009ad00
//   600fb848 FUN_600fb848
//   600c1b74 FUN_600c1b74


void FUN_600facc4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_24 [28];
  
  FUN_600fa7de(param_1,2,0,param_4,param_2);
  FUN_600c1b74(8,param_1);
  FUN_600c1b74(9,param_1);
  if (((*(byte *)(param_1 + 0x191) & 1) != 0) && ((*(byte *)(param_1 + 0x192) & 1) != 0)) {
    FUN_6009ad00(param_1 + 0x1d,0x20,auStack_24,1);
  }
  FUN_600fb848(param_1,0);
  return;
}


