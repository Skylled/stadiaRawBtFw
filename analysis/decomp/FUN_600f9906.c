// 600f9906  FUN_600f9906  size=232 bytes
// --- callers ---
//   600b6d30 FUN_600b6d30
//   600b6550 FUN_600b6550
//   600f9db4 FUN_600f9db4
//   600b674c FUN_600b674c
//   600b6900 FUN_600b6900
// --- callees ---
//   600d9250 FUN_600d9250
//   600f8c34 FUN_600f8c34
//   600bb7e4 FUN_600bb7e4
//   600bce60 FUN_600bce60
//   600b9408 FUN_600b9408


void FUN_600f9906(undefined2 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *(char *)(*(int *)(param_1 + 0x96) + 0xb) = *(char *)(*(int *)(param_1 + 0x96) + 0xb) + '\x01';
  FUN_600f8c34(*(undefined4 *)(param_1 + 0x96),3);
  *(undefined1 *)((int)param_1 + 7) = *(undefined1 *)(*(int *)(param_1 + 0x96) + 0xb);
  iVar1 = FUN_600bb7e4(*(undefined4 *)(param_1 + 0x96),4,6,*(undefined1 *)((int)param_1 + 7));
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x14) = (char)param_1[1];
    *(char *)(iVar1 + 0x15) = (char)((ushort)param_1[1] >> 8);
    *(char *)(iVar1 + 0x16) = (char)*param_1;
    *(char *)(iVar1 + 0x17) = (char)((ushort)*param_1 >> 8);
    if (*(char *)(param_1 + 0x3f) == '\0') {
      while (*(int *)(param_1 + 0x98) != 0) {
        uVar2 = FUN_600d9250(param_1 + 0x98);
        FUN_600bce60(uVar2,param_1);
        FUN_600b9408(*(undefined4 *)(param_1 + 0x96),param_1,uVar2);
      }
    }
    FUN_600b9408(*(undefined4 *)(param_1 + 0x96),0,iVar1);
  }
  return;
}


