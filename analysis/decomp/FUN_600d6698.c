// 600d6698  FUN_600d6698  size=136 bytes
// --- callers ---
//   600641a8 usb_host_audio_topology__600641a8
// --- callees ---
//   600d5bca FUN_600d5bca
//   600d5bd2 FUN_600d5bd2


void FUN_600d6698(int *param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar5 = *param_1;
  uVar6 = param_1[1] - iVar5 >> 1;
  uVar3 = uVar6;
  if (uVar6 == 0) {
    uVar3 = 1;
  }
  iVar7 = uVar6 + uVar3;
  if ((CARRY4(uVar6,uVar3)) || (iVar7 < 0)) {
    iVar7 = 0x7fffffff;
  }
  else if (iVar7 == 0) {
    iVar1 = 0;
    goto LAB_600d66ce;
  }
  iVar1 = FUN_600d5bd2(iVar7);
LAB_600d66ce:
  iVar2 = *param_1;
  *(undefined2 *)((int)param_2 + (iVar1 - iVar5)) = *param_3;
  for (iVar5 = 0; puVar4 = (undefined2 *)(iVar5 + iVar2), param_2 != puVar4; iVar5 = iVar5 + 2) {
    *(undefined2 *)(iVar1 + iVar5) = *puVar4;
  }
  puVar4 = (undefined2 *)param_1[1];
  iVar2 = ((int)param_2 - iVar2 & 0xfffffffeU) + 2 + iVar1;
  for (iVar5 = 0; puVar4 != (undefined2 *)(iVar5 + (int)param_2); iVar5 = iVar5 + 2) {
    *(undefined2 *)(iVar2 + iVar5) = *(undefined2 *)(iVar5 + (int)param_2);
  }
  FUN_600d5bca();
  param_1[2] = iVar1 + iVar7 * 2;
  *param_1 = iVar1;
  param_1[1] = (int)puVar4 + (iVar2 - (int)param_2);
  return;
}


