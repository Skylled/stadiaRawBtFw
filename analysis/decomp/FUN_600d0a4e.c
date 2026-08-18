// 600d0a4e  FUN_600d0a4e  size=66 bytes
// --- callers ---
// --- callees ---
//   600d0bc8 FUN_600d0bc8
//   6005505c FUN_6005505c
//   600d1178 FUN_600d1178


undefined4 FUN_600d0a4e(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = param_2;
  uStack_10 = param_3;
  FUN_600d1178(*param_1,6,(int)&uStack_14 + 3,param_4,param_1);
  if (uStack_14._3_1_ == '\0') {
    puVar1 = param_1 + 3;
    *(short *)puVar1 = (short)CONCAT21(*(undefined2 *)(param_2 + 4),*(undefined1 *)(param_2 + 2));
    FUN_6005505c(*param_1,4,puVar1);
    uVar2 = FUN_600d0bc8(*param_1,10,puVar1);
  }
  else {
    uVar2 = 5;
  }
  return uVar2;
}


