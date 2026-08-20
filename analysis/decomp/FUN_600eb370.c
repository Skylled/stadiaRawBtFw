// 600eb370  FUN_600eb370  size=52 bytes
// --- callers ---
//   600eb3a4 FUN_600eb3a4
//   6008db08 bcm__6008db08
// --- callees ---
//   600eadee FUN_600eadee
//   600eb1d4 FUN_600eb1d4


uint FUN_600eb370(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_600eb1d4();
  iVar2 = FUN_600eb1d4(param_1,param_3);
  if (iVar1 == 0) {
    if (iVar2 == 0) {
      uVar3 = FUN_600eadee(param_1,param_2,param_3,param_4);
      return uVar3;
    }
    uVar3 = 1;
  }
  else {
    uVar3 = (uint)(iVar2 == 0);
  }
  return uVar3;
}


