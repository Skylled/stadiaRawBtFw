// 600f8de8  FUN_600f8de8  size=232 bytes
// --- callers ---
//   600b5ec8 FUN_600b5ec8
//   600b6378 FUN_600b6378
//   600b674c FUN_600b674c
// --- callees ---
//   600bb7e4 FUN_600bb7e4
//   600b9408 FUN_600b9408


void FUN_600f8de8(undefined2 *param_1,short param_2,undefined2 param_3)

{
  int iVar1;
  
  if (param_2 == 1) {
    if ((*(byte *)((int)param_1 + 9) & 2) != 0) {
      return;
    }
    *(byte *)((int)param_1 + 9) = *(byte *)((int)param_1 + 9) | 2;
  }
  iVar1 = FUN_600bb7e4(*(undefined4 *)(param_1 + 0x96),8,3,*(undefined1 *)(param_1 + 4));
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x14) = (char)*param_1;
    *(char *)(iVar1 + 0x15) = (char)((ushort)*param_1 >> 8);
    *(char *)(iVar1 + 0x16) = (char)param_1[1];
    *(char *)(iVar1 + 0x17) = (char)((ushort)param_1[1] >> 8);
    *(char *)(iVar1 + 0x18) = (char)param_2;
    *(char *)(iVar1 + 0x19) = (char)((ushort)param_2 >> 8);
    *(char *)(iVar1 + 0x1a) = (char)param_3;
    *(char *)(iVar1 + 0x1b) = (char)((ushort)param_3 >> 8);
    FUN_600b9408(*(undefined4 *)(param_1 + 0x96),0,iVar1);
  }
  return;
}


