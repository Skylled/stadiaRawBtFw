// 600f9a70  FUN_600f9a70  size=118 bytes
// --- callers ---
//   600b89b8 FUN_600b89b8
// --- callees ---
//   600f8c34 FUN_600f8c34
//   600bb7e4 FUN_600bb7e4
//   600b9408 FUN_600b9408


void FUN_600f9a70(int param_1,int param_2,ushort param_3)

{
  int iVar1;
  int iVar2;
  undefined1 *local_14;
  
  *(char *)(param_1 + 0xb) = *(char *)(param_1 + 0xb) + '\x01';
  FUN_600f8c34(param_1,2);
  iVar1 = FUN_600bb7e4(param_1,param_3,8,*(undefined1 *)(param_1 + 0xb));
  if (iVar1 != 0) {
    if (param_3 != 0) {
      local_14 = (undefined1 *)(iVar1 + 0x14);
      for (iVar2 = 0; iVar2 < (int)(uint)param_3; iVar2 = iVar2 + 1) {
        *local_14 = *(undefined1 *)(iVar2 + param_2);
        local_14 = local_14 + 1;
      }
    }
    FUN_600b9408(param_1,0,iVar1);
  }
  return;
}


