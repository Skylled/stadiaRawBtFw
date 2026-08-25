// 600f8ed0  FUN_600f8ed0  size=170 bytes
// --- callers ---
//   600ba1c4 FUN_600ba1c4
// --- callees ---
//   600bb7e4 FUN_600bb7e4
//   600b9408 FUN_600b9408


void FUN_600f8ed0(undefined4 param_1,undefined2 param_2,undefined1 param_3,undefined2 param_4)

{
  int iVar1;
  
  iVar1 = FUN_600bb7e4(param_1,8,3,param_3);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x14) = 0;
    *(undefined1 *)(iVar1 + 0x15) = 0;
    *(char *)(iVar1 + 0x16) = (char)param_2;
    *(char *)(iVar1 + 0x17) = (char)((ushort)param_2 >> 8);
    *(char *)(iVar1 + 0x18) = (char)param_4;
    *(char *)(iVar1 + 0x19) = (char)((ushort)param_4 >> 8);
    *(undefined1 *)(iVar1 + 0x1a) = 0;
    *(undefined1 *)(iVar1 + 0x1b) = 0;
    FUN_600b9408(param_1,0,iVar1);
  }
  return;
}


