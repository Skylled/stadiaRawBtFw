// 600d932a  FUN_600d932a  size=74 bytes
// --- callers ---
//   600aa534 FUN_600aa534
//   600a9f04 FUN_600a9f04
//   60096450 FUN_60096450
// --- callees ---


uint FUN_600d932a(int *param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = 0;
  for (piVar2 = (int *)*param_1; uVar1 = (uint)uVar3, piVar2 != (int *)0x0; piVar2 = (int *)*piVar2)
  {
    uVar3 = uVar3 + 1;
    iVar4 = param_2;
    if (0 < piVar2[3]) goto LAB_600d9340;
  }
  goto LAB_600d935e;
  while( true ) {
    iVar5 = piVar2[3];
    iVar6 = iVar5 - iVar4;
    if (iVar6 < 1) {
      uVar1 = uVar1 + 1;
      piVar2[3] = 0;
    }
    else {
      piVar2[3] = iVar6;
    }
    piVar2 = (int *)*piVar2;
    if (iVar6 < 1) {
      uVar1 = uVar1 & 0xffff;
    }
    iVar4 = iVar4 - iVar5;
    if (piVar2 == (int *)0x0) break;
LAB_600d9340:
    if (iVar4 < 1) break;
  }
LAB_600d935e:
  if (0 < param_1[2]) {
    param_2 = param_1[2] - param_2;
    if (param_2 < 0) {
      param_2 = 0;
    }
    param_1[2] = param_2;
  }
  return uVar1;
}


