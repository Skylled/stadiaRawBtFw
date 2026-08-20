// 600ea72a  FUN_600ea72a  size=32 bytes
// --- callers ---
//   600ed880 FUN_600ed880
//   600ea74a FUN_600ea74a
// --- callees ---
//   6013cfb0 thunk_EXT_FUN_0000ac52


undefined4 FUN_600ea72a(int *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 extraout_r2;
  undefined4 uVar1;
  int iVar2;
  
  (**(code **)(*param_1 + 0x14))();
  iVar2 = *param_1;
  uVar1 = extraout_r2;
  if (param_3 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(iVar2 + 4);
    *param_3 = uVar1;
  }
  thunk_EXT_FUN_0000ac52(param_1[1],*(undefined4 *)(iVar2 + 0x1c),uVar1,iVar2,param_4);
  return 1;
}


