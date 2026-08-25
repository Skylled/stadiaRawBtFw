// 600f8264  FUN_600f8264  size=44 bytes
// --- callers ---
//   600b74d8 FUN_600b74d8
//   600b7674 FUN_600b7674
// --- callees ---
//   600b72cc FUN_600b72cc


undefined4 FUN_600f8264(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_600b72cc(0,param_1 + 8 + (uint)*(ushort *)(param_1 + 4),*(undefined2 *)(param_1 + 2));
  return uVar1;
}


