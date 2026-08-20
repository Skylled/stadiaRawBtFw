// 600eb47c  FUN_600eb47c  size=52 bytes
// --- callers ---
//   600eb4b0 FUN_600eb4b0
// --- callees ---
//   600eb1d4 FUN_600eb1d4
//   600ea820 FUN_600ea820
//   600eaed6 FUN_600eaed6


undefined4 FUN_600eb47c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_54 [68];
  
  iVar1 = FUN_600eb1d4();
  if (iVar1 == 0) {
    iVar1 = FUN_600ea820(param_1,auStack_54,param_2);
    uVar2 = 0;
    if ((iVar1 != 0) && (iVar1 = FUN_600eaed6(param_1,auStack_54,param_3), uVar2 = 0, iVar1 != 0)) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


