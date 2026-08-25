// 600f99ee  FUN_600f99ee  size=130 bytes
// --- callers ---
//   600b6fcc FUN_600b6fcc
//   600ba1c4 FUN_600ba1c4
//   600b70f4 FUN_600b70f4
// --- callees ---
//   600bb7e4 FUN_600bb7e4
//   600b9408 FUN_600b9408


void FUN_600f99ee(undefined4 param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  
  iVar1 = FUN_600bb7e4(param_1,4,7,param_2);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x14) = (char)param_3;
    *(char *)(iVar1 + 0x15) = (char)((ushort)param_3 >> 8);
    *(char *)(iVar1 + 0x16) = (char)param_4;
    *(char *)(iVar1 + 0x17) = (char)((ushort)param_4 >> 8);
    FUN_600b9408(param_1,0,iVar1);
  }
  return;
}


