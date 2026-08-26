// 600d6e7a  FUN_600d6e7a  size=46 bytes
// --- callers ---
//   600667fc FUN_600667fc
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   6004cb28 FUN_6004cb28


int FUN_600d6e7a(uint *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_6004cb28(param_2);
  }
  uVar4 = *param_1;
  uVar3 = uVar4;
  if (uVar1 <= uVar4) {
    uVar3 = uVar1;
  }
  if ((uVar3 == 0) || (iVar2 = thunk_EXT_FUN_0000b554(param_1[1],param_2), iVar2 == 0)) {
    iVar2 = uVar4 - uVar1;
  }
  return iVar2;
}


