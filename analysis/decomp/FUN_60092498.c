// 60092498  FUN_60092498  size=118 bytes
// --- callers ---
//   60086b08 FUN_60086b08
// --- callees ---
//   6013d080 thunk_EXT_FUN_00006788
//   6013d0e8 thunk_EXT_FUN_00006a74
//   6013d270 thunk_EXT_FUN_00006e5c
//   6013d038 thunk_EXT_FUN_00008832


undefined4 FUN_60092498(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  puVar1 = DAT_60092510;
  iVar2 = thunk_EXT_FUN_00006788();
  thunk_EXT_FUN_00006e5c(*puVar1,0xffffffff);
  iVar6 = *(int *)(iVar2 + 0x2c);
  piVar3 = (int *)iVar6;
  do {
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)thunk_EXT_FUN_00008832(0x1c);
      if (piVar3 == (int *)0x0) {
        uVar5 = 0xc;
      }
      else {
        iVar4 = *(int *)(param_1 + 4);
        piVar3[6] = (int)piVar3;
        *piVar3 = iVar4;
        piVar3[4] = param_1;
        piVar3[5] = param_2;
        if (iVar4 != 0) {
          *(int **)(iVar4 + 4) = piVar3;
        }
        *(int **)(param_1 + 4) = piVar3;
        piVar3[2] = iVar6;
        piVar3[1] = param_1 + 4;
        piVar3[3] = iVar2 + 0x2c;
        if (iVar6 != 0) {
          *(int **)(iVar6 + 4) = piVar3 + 2;
        }
        *(int **)(iVar2 + 0x2c) = piVar3 + 2;
LAB_600924f2:
        uVar5 = 0;
      }
      thunk_EXT_FUN_00006a74(*puVar1,0,0);
      return uVar5;
    }
    if (piVar3[2] == param_1) {
      piVar3[3] = param_2;
      goto LAB_600924f2;
    }
    piVar3 = (int *)*piVar3;
  } while( true );
}


