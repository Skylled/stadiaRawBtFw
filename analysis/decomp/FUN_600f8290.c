// 600f8290  FUN_600f8290  size=52 bytes
// --- callers ---
//   600b8094 FUN_600b8094
//   600b7800 FUN_600b7800
// --- callees ---
//   600b72cc FUN_600b72cc


undefined4 FUN_600f8290(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_600b72cc(0,param_1 + (uint)*(ushort *)(param_1 + 4) + 4,*(ushort *)(param_1 + 2) + 4);
  return uVar1;
}


