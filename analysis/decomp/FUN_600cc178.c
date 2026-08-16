// 600cc178  FUN_600cc178  size=66 bytes
// --- callers ---
//   6010177a FUN_6010177a
// --- callees ---
//   600ca1f8 tasks__600ca1f8


undefined4 FUN_600cc178(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x58) == 0) {
    iVar2 = *(int *)(param_1 + 0x5c);
    if (iVar2 == 0) {
      uVar1 = 9;
    }
    else if ((uint)(*(int *)(iVar2 + 0xd0) << 2) < 0x800) {
      uVar1 = 3;
    }
    else {
      uVar1 = tasks__600ca1f8(DAT_600cc1bc,param_2,*(int *)(iVar2 + 0xd0),param_1,param_3,
                              *(undefined4 *)(iVar2 + 0xcc),iVar2,param_4);
      *(undefined4 *)(param_1 + 0x58) = uVar1;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 6;
  }
  return uVar1;
}


