// 600d6588  FUN_600d6588  size=138 bytes
// --- callers ---
//   600d6612 FUN_600d6612
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a
//   6013d378 thunk_EXT_FUN_0000b532


void FUN_600d6588(int *param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar5 = *param_1;
  uVar7 = param_1[1] - iVar5 >> 1;
  uVar4 = uVar7;
  if (uVar7 == 0) {
    uVar4 = 1;
  }
  iVar8 = uVar7 + uVar4;
  if ((CARRY4(uVar7,uVar4)) || (iVar8 < 0)) {
    iVar8 = 0x7fffffff;
  }
  else if (iVar8 == 0) {
    iVar1 = 0;
    goto LAB_600d65be;
  }
  iVar1 = thunk_EXT_FUN_0000b532(iVar8 << 1);
LAB_600d65be:
  iVar2 = *param_1;
  *(undefined2 *)((int)param_2 + (iVar1 - iVar5)) = *param_3;
  for (iVar5 = 0; param_2 != (undefined2 *)(iVar5 + iVar2); iVar5 = iVar5 + 2) {
    *(undefined2 *)(iVar1 + iVar5) = *(undefined2 *)(iVar5 + iVar2);
  }
  puVar3 = (undefined2 *)param_1[1];
  iVar6 = ((int)param_2 - iVar2 & 0xfffffffeU) + 2 + iVar1;
  for (iVar5 = 0; puVar3 != (undefined2 *)(iVar5 + (int)param_2); iVar5 = iVar5 + 2) {
    *(undefined2 *)(iVar6 + iVar5) = *(undefined2 *)(iVar5 + (int)param_2);
  }
  if (iVar2 != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  *param_1 = iVar1;
  param_1[1] = (int)puVar3 + (iVar6 - (int)param_2);
  param_1[2] = iVar1 + iVar8 * 2;
  return;
}


