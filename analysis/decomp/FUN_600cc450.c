// 600cc450  FUN_600cc450  size=82 bytes
// --- callers ---
//   600618f8 FUN_600618f8
//   60051890 FUN_60051890
//   600cbb7c FUN_600cbb7c
//   6005dabc FUN_6005dabc
//   600cbccc FUN_600cbccc
//   60058318 FUN_60058318
//   6007fe74 FUN_6007fe74
//   6005e904 FUN_6005e904
//   60061d38 FUN_60061d38
//   600cbc18 FUN_600cbc18
//   60051b50 stats__60051b50
//   6005dbec FUN_6005dbec
//   6005eaf8 FUN_6005eaf8
//   600cbbc0 FUN_600cbbc0
//   600dfe3e FUN_600dfe3e
//   6005e8d8 FUN_6005e8d8
//   600cbc60 FUN_600cbc60
//   6005b4f4 FUN_6005b4f4
//   600dfe6e FUN_600dfe6e
//   6005ebe0 FUN_6005ebe0
//   6007f7a0 FUN_6007f7a0
//   6005e810 FUN_6005e810
//   6005d844 trigger_bug_report__6005d844
//   6005dcc0 FUN_6005dcc0
// --- callees ---
//   601019da FUN_601019da
//   6010196e FUN_6010196e
//   600cc3cc FUN_600cc3cc
//   600cdcc4 FUN_600cdcc4
//   600cc2d0 FUN_600cc2d0


int * FUN_600cc450(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[2];
  if (param_3 == 0) {
    iVar1 = FUN_600cc3cc();
    if (iVar1 != 0) {
      FUN_600cdcc4(*param_1 + param_1[2],param_1[1] - param_1[2],DAT_600cc4a4);
      FUN_601019da(param_1,4,iVar2,0x7d);
    }
  }
  else {
    iVar1 = FUN_600cc3cc();
    if (iVar1 != 0) {
      iVar1 = FUN_600cc2d0(param_1,param_3,3);
      if (iVar1 == 0) {
        param_1[2] = iVar2 + -1;
      }
      FUN_6010196e(param_1,0x7d);
    }
  }
  return param_1;
}


