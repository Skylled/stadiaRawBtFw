// 600eb1d4  FUN_600eb1d4  size=16 bytes
// --- callers ---
//   6008d350 FUN_6008d350
//   600eb280 FUN_600eb280
//   6008d3d4 FUN_6008d3d4
//   600eb47c FUN_600eb47c
//   600eb370 FUN_600eb370
//   6008da3c bcm__6008da3c
//   600eb1e4 FUN_600eb1e4
//   6008d5e0 bcm__6008d5e0
//   600eb4b0 FUN_600eb4b0
// --- callees ---
//   600eab3a FUN_600eab3a


bool FUN_600eb1d4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_600eab3a(param_1,param_2 + 0x88,param_3,param_4,param_4);
  return iVar1 == 0;
}


