// 600d2a8e  FUN_600d2a8e  size=64 bytes
// --- callers ---
//   600d2bb0 FUN_600d2bb0
//   600d2ace FUN_600d2ace
// --- callees ---
//   600d2a6e FUN_600d2a6e


int FUN_600d2a8e(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    uVar1 = *(ushort *)((int)param_2 + 0xe) & 0x3ff;
    iVar2 = iVar2 + uVar1;
    FUN_600d2a6e(*(undefined4 *)(param_1 + 8),param_2,*(undefined2 *)(param_2 + 7),uVar1,param_4);
    *param_2 = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 **)(param_1 + 0x20) = param_2;
    *(char *)(param_1 + 0x48) = *(char *)(param_1 + 0x48) + '\x01';
    if (param_2 == param_3) break;
    param_2 = (undefined4 *)(*(int *)(param_1 + 0x1c) + (uint)*(byte *)((int)param_2 + 0x1e) * 0x20)
    ;
  }
  return iVar2;
}


