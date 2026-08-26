// 60100d98  FUN_60100d98  size=112 bytes
// --- callers ---
//   60100f90 FUN_60100f90
//   60100ffc FUN_60100ffc
// --- callees ---
//   60101848 FUN_60101848
//   60100b24 FUN_60100b24


uint FUN_60100d98(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_20;
  int iStack_1c;
  
  if (param_1[param_2 * 2 + 0x2f] == -1 && param_1[param_2 * 2 + 0x2e] == -1) {
    iVar4 = *param_1;
    iVar3 = *(int *)(*(int *)(iVar4 + 4) + 4);
    local_20 = param_1[0x18];
    iStack_1c = param_1[0x19];
    iVar2 = FUN_60100b24(*(undefined1 *)((int)param_1 + 0x59),8,&local_20);
    uVar1 = FUN_60101848(iVar4,iVar2 + param_2 * iVar3);
    if ((uVar1 & 0xff) == 0) {
      param_1[param_2 + 0x1a] = 0;
      uVar1 = param_1[0x18];
      iVar2 = param_1[0x19];
      param_1[param_2 * 2 + 0x2e] = uVar1;
      param_1[param_2 * 2 + 0x2f] = iVar2;
      param_1[0x18] = uVar1 + 1;
      param_1[0x19] = iVar2 + (uint)(0xfffffffe < uVar1);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


