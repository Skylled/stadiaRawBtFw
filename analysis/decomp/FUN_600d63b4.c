// 600d63b4  FUN_600d63b4  size=138 bytes
// --- callers ---
//   600d643e FUN_600d643e
// --- callees ---
//   6013d378 thunk_EXT_FUN_0000b532
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013d310 thunk_EXT_FUN_0000b52a
//   6013d238 thunk_EXT_FUN_0000b588


void FUN_600d63b4(int *param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = *param_1;
  uVar4 = param_1[1] - iVar6 >> 2;
  uVar2 = uVar4;
  if (uVar4 == 0) {
    uVar2 = 1;
  }
  uVar5 = uVar4 + uVar2;
  if ((CARRY4(uVar4,uVar2)) || (0x3fffffff < uVar5)) {
    uVar5 = 0x3fffffff;
  }
  else if (uVar5 == 0) {
    iVar1 = 0;
    goto LAB_600d63dc;
  }
  iVar1 = thunk_EXT_FUN_0000b532(uVar5 << 2);
LAB_600d63dc:
  uVar3 = *param_3;
  iVar8 = *param_1;
  *(undefined4 *)(iVar1 + (param_2 - iVar6)) = uVar3;
  if (iVar8 != param_2) {
    thunk_EXT_FUN_0000b588(iVar1,iVar8,param_2 - iVar8,uVar3,param_4);
  }
  iVar6 = (param_2 - iVar8) + 4 + iVar1;
  iVar7 = param_1[1] - param_2;
  if (param_1[1] != param_2) {
    iVar6 = thunk_EXT_FUN_0000b572(iVar6,param_2,iVar7);
  }
  if (iVar8 != 0) {
    thunk_EXT_FUN_0000b52a(iVar8);
  }
  *param_1 = iVar1;
  param_1[1] = iVar7 + iVar6;
  param_1[2] = iVar1 + uVar5 * 4;
  return;
}


