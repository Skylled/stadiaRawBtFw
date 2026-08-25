// 600f8208  FUN_600f8208  size=92 bytes
// --- callers ---
//   600f7d88 FUN_600f7d88
// --- callees ---
//   600b9408 FUN_600b9408
//   600bb7e4 FUN_600bb7e4


void FUN_600f8208(undefined4 param_1,undefined2 param_2,undefined1 param_3)

{
  int iVar1;
  
  iVar1 = FUN_600bb7e4(param_1,2,0x13,param_3);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x14) = (char)param_2;
    *(char *)(iVar1 + 0x15) = (char)((ushort)param_2 >> 8);
    FUN_600b9408(param_1,0,iVar1);
  }
  return;
}


