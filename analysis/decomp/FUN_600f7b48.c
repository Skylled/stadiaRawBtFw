// 600f7b48  FUN_600f7b48  size=144 bytes
// --- callers ---
//   600fd376 FUN_600fd376
//   60069dd4 FUN_60069dd4
// --- callees ---
//   60098ec8 FUN_60098ec8
//   600b5844 FUN_600b5844
//   600bb6dc FUN_600bb6dc


undefined4
FUN_600f7b48(undefined4 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
            undefined2 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_60098ec8(param_1,2);
  iVar2 = FUN_600bb6dc(param_1,2);
  if ((iVar2 == 0) || (iVar1 == 0)) {
    uVar3 = 0;
  }
  else if ((*(char *)(iVar2 + 0x32) == '\x02') && (*(char *)(iVar2 + 1) == '\x04')) {
    *(undefined2 *)(iVar2 + 0x3a) = param_2;
    *(undefined2 *)(iVar2 + 0x3c) = param_3;
    *(undefined2 *)(iVar2 + 0x3e) = param_4;
    *(undefined2 *)(iVar2 + 0x40) = param_5;
    *(byte *)(iVar2 + 0x38) = *(byte *)(iVar2 + 0x38) | 2;
    FUN_600b5844(iVar2);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


