// 600d93ec  FUN_600d93ec  size=40 bytes
// --- callers ---
//   6006edd0 FUN_6006edd0
// --- callees ---
//   6006eb00 FUN_6006eb00


undefined4 FUN_600d93ec(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    uVar1 = FUN_6006eb00(param_1 + iVar2,param_2);
    if ((int)uVar1 < 1) {
      return 1;
    }
    if (param_2 <= uVar1) {
      uVar1 = param_2;
    }
    param_2 = param_2 - uVar1;
    iVar2 = iVar2 + uVar1;
  } while (param_2 != 0);
  return 0;
}


