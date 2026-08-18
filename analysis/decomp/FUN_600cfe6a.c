// 600cfe6a  FUN_600cfe6a  size=46 bytes
// --- callers ---
//   600d0332 FUN_600d0332
//   600d0590 FUN_600d0590
// --- callees ---
//   600d10f6 FUN_600d10f6


undefined4
FUN_600cfe6a(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (param_1[2] == 0) {
    uVar2 = 1;
  }
  else {
    iVar5 = 0;
    uVar2 = 1;
    while( true ) {
      uVar3 = (uint)*(byte *)(param_1[2] + 4);
      if ((int)uVar3 <= iVar5) break;
      iVar4 = *(int *)(param_1[2] + 8);
      iVar1 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      uVar2 = FUN_600d10f6(*param_1,*(undefined1 *)(iVar4 + iVar1),uVar3,iVar4,param_4);
    }
    param_1[2] = 0;
  }
  return uVar2;
}


