// 600d5ee6  FUN_600d5ee6  size=152 bytes
// --- callers ---
//   600644dc usb_host_audio_topology__600644dc
// --- callees ---
//   600d5bca FUN_600d5bca
//   600d5bd2 FUN_600d5bd2


int * FUN_600d5ee6(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 *puVar10;
  
  if (param_2 != param_1) {
    iVar8 = *param_2;
    puVar10 = (undefined2 *)param_2[1];
    iVar3 = *param_1;
    iVar9 = (int)puVar10 - iVar8;
    uVar2 = iVar9 >> 1;
    if ((uint)(param_1[2] - iVar3 >> 1) < uVar2) {
      iVar3 = 0;
      if (uVar2 != 0) {
        iVar3 = FUN_600d5bd2();
      }
      for (iVar5 = 0; puVar10 != (undefined2 *)(iVar8 + iVar5); iVar5 = iVar5 + 2) {
        *(undefined2 *)(iVar3 + iVar5) = *(undefined2 *)(iVar8 + iVar5);
      }
      FUN_600d5bca(*param_1);
      *param_1 = iVar3;
      param_1[2] = iVar3 + iVar9;
    }
    else {
      iVar7 = param_1[1];
      iVar5 = iVar7 - iVar3;
      uVar1 = iVar5 >> 1;
      if (uVar1 < uVar2) {
        for (iVar6 = 0; 0 < (int)(uVar1 - iVar6); iVar6 = iVar6 + 1) {
          *(undefined2 *)(iVar3 + iVar6 * 2) = *(undefined2 *)(iVar8 + iVar6 * 2);
        }
        for (iVar3 = 0; puVar4 = (undefined2 *)(iVar8 + iVar5 + iVar3), puVar10 != puVar4;
            iVar3 = iVar3 + 2) {
          *(undefined2 *)(iVar7 + iVar3) = *puVar4;
        }
      }
      else {
        for (iVar5 = 0; 0 < (int)(uVar2 - iVar5); iVar5 = iVar5 + 1) {
          *(undefined2 *)(iVar3 + iVar5 * 2) = *(undefined2 *)(iVar8 + iVar5 * 2);
        }
      }
    }
    param_1[1] = iVar9 + *param_1;
  }
  return param_1;
}


