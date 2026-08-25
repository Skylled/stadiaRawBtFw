// 600f8d34  FUN_600f8d34  size=180 bytes
// --- callers ---
//   600b61c4 FUN_600b61c4
//   600b5ec8 FUN_600b5ec8
//   600b6550 FUN_600b6550
// --- callees ---
//   600bb7e4 FUN_600bb7e4
//   600f8c34 FUN_600f8c34
//   600b9408 FUN_600b9408


void FUN_600f8d34(undefined2 *param_1)

{
  int iVar1;
  
  *(char *)(*(int *)(param_1 + 0x96) + 0xb) = *(char *)(*(int *)(param_1 + 0x96) + 0xb) + '\x01';
  FUN_600f8c34(*(undefined4 *)(param_1 + 0x96),3);
  *(undefined1 *)((int)param_1 + 7) = *(undefined1 *)(*(int *)(param_1 + 0x96) + 0xb);
  iVar1 = FUN_600bb7e4(*(undefined4 *)(param_1 + 0x96),4,2,*(undefined1 *)((int)param_1 + 7));
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x14) = (char)*(undefined2 *)(*(int *)(param_1 + 0xaa) + 4);
    *(char *)(iVar1 + 0x15) = (char)((ushort)*(undefined2 *)(*(int *)(param_1 + 0xaa) + 4) >> 8);
    *(char *)(iVar1 + 0x16) = (char)*param_1;
    *(char *)(iVar1 + 0x17) = (char)((ushort)*param_1 >> 8);
    FUN_600b9408(*(undefined4 *)(param_1 + 0x96),0,iVar1);
  }
  return;
}


