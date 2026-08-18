// 600d201e  FUN_600d201e  size=78 bytes
// --- callers ---
//   600563b8 FUN_600563b8
// --- callees ---
//   600d33b2 FUN_600d33b2
//   600d15c8 FUN_600d15c8


undefined4 FUN_600d201e(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *local_1c;
  undefined4 uStack_18;
  
  uVar2 = param_1;
  local_1c = param_2;
  uStack_18 = param_3;
  iVar1 = FUN_600d15c8(0x4c);
  if (iVar1 == 0) {
    uVar2 = 0xc;
  }
  else {
    *(undefined4 *)(iVar1 + 8) = param_1;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    FUN_600d33b2(param_1,8,&local_1c);
    *(int **)(iVar1 + 4) = local_1c;
    FUN_600d33b2(param_1,9,&local_1c,local_1c,uVar2);
    *(int **)(iVar1 + 0x10) = local_1c;
    FUN_600d33b2(param_1,7,&local_1c);
    uVar2 = 0;
    *(char *)(iVar1 + 0x32) = (char)local_1c;
    *param_2 = iVar1;
  }
  return uVar2;
}


