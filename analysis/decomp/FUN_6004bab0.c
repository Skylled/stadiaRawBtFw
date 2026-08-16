// 6004bab0  FUN_6004bab0  size=84 bytes
// --- callers ---
//   600416d4 FUN_600416d4
//   6004b8ce FUN_6004b8ce
// --- callees ---
//   6004c34c queue__600c9e6c
//   60047290 queue__60047290
//   6004c464 thunk_FUN_60092528
//   60047aa8 tasks__60047aa8
//   6004b9e0 FUN_6004b9e0
//   60047958 FUN_60047958


int FUN_6004bab0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_6004b9e0();
  if ((iVar1 != 0) || (iVar1 = thunk_FUN_60092528(param_1,0), iVar1 == 0)) {
    iVar1 = *param_1;
    if (iVar1 == 0) {
      iVar1 = 0x16;
    }
    else {
      if (*(int *)(iVar1 + 8) == 1) {
        iVar2 = queue__600c9e6c(*(undefined4 *)(iVar1 + 0xc));
      }
      else {
        FUN_60047958();
        iVar2 = queue__60047290(*(undefined4 *)(iVar1 + 0xc),0,0,0,param_4);
        *(undefined4 *)(iVar1 + 4) = 0;
        tasks__60047aa8();
      }
      if (iVar2 == 1) {
        iVar1 = 0;
      }
      else {
        iVar1 = 0xc;
      }
    }
  }
  return iVar1;
}


