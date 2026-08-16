// 6008bae0  bcm__6008bae0  size=172 bytes
// src: bcm.c
// --- callers ---
//   6008bbdc bcm__6008bbdc
// --- callees ---
//   6008b43c bcm__6008b43c
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e0552 FUN_600e0552
//   600e7480 FUN_600e7480


/* src: bcm.c */

undefined4 bcm__6008bae0(int *param_1,int *param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  if ((int)param_3 < 0) {
    FUN_600e0552(3,0,0x6d,DAT_6008bb8c,0x49);
    uVar1 = 0;
  }
  else {
    iVar4 = param_2[3];
    iVar5 = (int)param_3 >> 5;
    iVar2 = param_2[1];
    param_1[3] = iVar4;
    iVar2 = bcm__6008b43c(param_1,iVar2 + iVar5 + 1,param_3,iVar4,param_1,param_2,param_3);
    uVar1 = 0;
    if (iVar2 != 0) {
      iVar2 = *param_1;
      param_3 = param_3 & 0x1f;
      iVar7 = *param_2;
      iVar4 = param_2[1] + -1;
      *(undefined4 *)(iVar2 + (iVar5 + param_2[1]) * 4) = 0;
      if (param_3 == 0) {
        for (; -1 < iVar4; iVar4 = iVar4 + -1) {
          *(undefined4 *)(iVar2 + iVar5 * 4 + iVar4 * 4) = *(undefined4 *)(iVar7 + iVar4 * 4);
        }
      }
      else {
        puVar3 = (uint *)(iVar2 + (iVar5 + iVar4 + 1) * 4);
        for (; -1 < iVar4; iVar4 = iVar4 + -1) {
          uVar6 = *(uint *)(iVar7 + iVar4 * 4);
          *puVar3 = uVar6 >> (0x20 - param_3 & 0xff) | *puVar3;
          puVar3 = puVar3 + -1;
          *puVar3 = uVar6 << param_3;
        }
      }
      thunk_EXT_FUN_0000af90(iVar2,0,iVar5 << 2);
      param_1[1] = iVar5 + param_2[1] + 1;
      FUN_600e7480(param_1);
      uVar1 = 1;
    }
  }
  return uVar1;
}


