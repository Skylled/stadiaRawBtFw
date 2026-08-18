// 600ce488  FUN_600ce488  size=116 bytes
// --- callers ---
//   60051b50 stats__60051b50
// --- callees ---
//   600ce440 FUN_600ce440
//   6013d238 thunk_EXT_FUN_0000b588


void FUN_600ce488(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  if (param_1 != param_2) {
    puVar11 = param_1 + 9;
    while (param_2 != puVar11) {
      puVar10 = puVar11 + 9;
      if ((uint)puVar11[2] < (uint)param_1[2]) {
        uVar1 = *puVar11;
        uVar3 = puVar11[1];
        uVar5 = puVar11[2];
        uVar7 = puVar11[3];
        uVar2 = puVar11[4];
        uVar4 = puVar11[5];
        uVar6 = puVar11[6];
        uVar8 = puVar11[7];
        uVar9 = puVar11[8];
        if (param_1 != puVar11) {
          thunk_EXT_FUN_0000b588
                    ((int)param_1 + (0x48 - (int)puVar10) + (int)puVar11,param_1,
                     (int)puVar10 + (-0x24 - (int)param_1));
        }
        *param_1 = uVar1;
        param_1[1] = uVar3;
        param_1[2] = uVar5;
        param_1[3] = uVar7;
        param_1[4] = uVar2;
        param_1[5] = uVar4;
        param_1[6] = uVar6;
        param_1[7] = uVar8;
        param_1[8] = uVar9;
        puVar11 = puVar10;
      }
      else {
        FUN_600ce440(puVar11);
        puVar11 = puVar10;
      }
    }
  }
  return;
}


