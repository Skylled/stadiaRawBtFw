// 600e7a32  FUN_600e7a32  size=234 bytes
// --- callers ---
//   6008b79c bcm__6008b79c
//   600e7b96 FUN_600e7b96
//   600e7ecc FUN_600e7ecc
//   6008bbdc bcm__6008bbdc
//   600e7dea FUN_600e7dea
//   600e91e6 FUN_600e91e6
//   600e863c FUN_600e863c
//   600e7b1c FUN_600e7b1c
//   600e87fa FUN_600e87fa
//   600eb1e4 FUN_600eb1e4
// --- callees ---


uint FUN_600e7a32(int *param_1,uint *param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0;
    while( true ) {
      if ((param_4 & 0xfffffffc) == 0) break;
      uVar2 = *param_2;
      uVar3 = *param_3;
      param_4 = param_4 - 4;
      uVar4 = uVar3 + uVar2;
      *param_1 = uVar5 + uVar4;
      uVar5 = (uint)CARRY4(uVar3,uVar2) + (uint)CARRY4(uVar5,uVar4);
      uVar4 = param_2[1];
      uVar2 = param_3[1];
      uVar3 = uVar2 + uVar4;
      param_1[1] = uVar3 + uVar5;
      uVar2 = (uint)CARRY4(uVar2,uVar4) + (uint)CARRY4(uVar3,uVar5);
      uVar5 = param_3[2] + param_2[2];
      uVar3 = (uint)CARRY4(param_3[2],param_2[2]) + (uint)CARRY4(uVar5,uVar2);
      param_1[2] = uVar5 + uVar2;
      uVar2 = param_3[3] + param_2[3];
      uVar5 = (uint)CARRY4(param_3[3],param_2[3]) + (uint)CARRY4(uVar3,uVar2);
      param_1[3] = uVar3 + uVar2;
      param_3 = param_3 + 4;
      param_2 = param_2 + 4;
      param_1 = param_1 + 4;
    }
    for (uVar2 = 0; param_4 != uVar2; uVar2 = uVar2 + 1) {
      uVar3 = param_3[uVar2] + param_2[uVar2];
      iVar1 = uVar3 + uVar5;
      uVar5 = (uint)CARRY4(param_3[uVar2],param_2[uVar2]) + (uint)CARRY4(uVar3,uVar5);
      param_1[uVar2] = iVar1;
    }
  }
  return uVar5;
}


