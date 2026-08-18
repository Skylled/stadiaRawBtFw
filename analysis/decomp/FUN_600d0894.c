// 600d0894  FUN_600d0894  size=84 bytes
// --- callers ---
// --- callees ---
//   600d11ba FUN_600d11ba
//   600d1178 FUN_600d1178


int FUN_600d0894(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = param_2;
  uStack_10 = param_3;
  FUN_600d1178(*param_1,6,(int)&uStack_14 + 3,param_4,param_1);
  if (uStack_14._3_1_ == 3) {
    iVar1 = FUN_600d11ba(*param_1,7,0);
    if (iVar1 != 0) {
      return iVar1;
    }
    uVar2 = 6;
    uStack_14 = CONCAT13(1,(undefined3)uStack_14);
  }
  else {
    if (2 < uStack_14._3_1_) {
      return 5;
    }
    uVar2 = 7;
    uStack_14 = CONCAT13((char)*(undefined2 *)(param_2 + 2),(undefined3)uStack_14);
  }
  iVar1 = FUN_600d11ba(*param_1,uVar2,(int)&uStack_14 + 3);
  return iVar1;
}


