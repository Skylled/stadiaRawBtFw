// 600f9ae6  FUN_600f9ae6  size=118 bytes
// --- callers ---
//   600ba1c4 FUN_600ba1c4
//   600b89b8 FUN_600b89b8
// --- callees ---
//   600f8c34 FUN_600f8c34
//   600bb7e4 FUN_600bb7e4
//   600b9408 FUN_600b9408


void FUN_600f9ae6(int param_1,undefined2 param_2)

{
  int iVar1;
  
  *(char *)(param_1 + 0xb) = *(char *)(param_1 + 0xb) + '\x01';
  FUN_600f8c34(param_1,3);
  iVar1 = FUN_600bb7e4(param_1,2,10,*(undefined1 *)(param_1 + 0xb));
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x14) = (char)param_2;
    *(char *)(iVar1 + 0x15) = (char)((ushort)param_2 >> 8);
    *(undefined1 *)(param_1 + 0xa3) = 1;
    FUN_600b9408(param_1,0,iVar1);
  }
  return;
}


