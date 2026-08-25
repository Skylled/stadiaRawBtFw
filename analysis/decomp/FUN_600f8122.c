// 600f8122  FUN_600f8122  size=230 bytes
// --- callers ---
//   600b5844 FUN_600b5844
// --- callees ---
//   600b9408 FUN_600b9408
//   600aa340 FUN_600aa340
//   600bb7e4 FUN_600bb7e4
//   600f8c34 FUN_600f8c34


void FUN_600f8122(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                 undefined2 param_5)

{
  int iVar1;
  
  *(char *)(param_1 + 0xb) = *(char *)(param_1 + 0xb) + '\x01';
  FUN_600f8c34(param_1,3);
  iVar1 = FUN_600bb7e4(param_1,8,0x12,*(undefined1 *)(param_1 + 0xb));
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x14) = (char)param_2;
    *(char *)(iVar1 + 0x15) = (char)((ushort)param_2 >> 8);
    *(char *)(iVar1 + 0x16) = (char)param_3;
    *(char *)(iVar1 + 0x17) = (char)((ushort)param_3 >> 8);
    *(char *)(iVar1 + 0x18) = (char)param_4;
    *(char *)(iVar1 + 0x19) = (char)((ushort)param_4 >> 8);
    *(char *)(iVar1 + 0x1a) = (char)param_5;
    *(char *)(iVar1 + 0x1b) = (char)((ushort)param_5 >> 8);
    *(undefined1 *)(param_1 + 0x34) = 1;
    FUN_600aa340(param_1 + 0x44,2,0x1e);
    FUN_600b9408(param_1,0,iVar1);
  }
  return;
}


