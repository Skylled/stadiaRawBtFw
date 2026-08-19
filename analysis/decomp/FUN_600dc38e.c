// 600dc38e  FUN_600dc38e  size=248 bytes
// --- callers ---
//   6007b1b8 synapse_audio_processor__6007b1b8
// --- callees ---
//   6013d378 thunk_EXT_FUN_0000b532
//   6013d238 thunk_EXT_FUN_0000b588
//   600dc1c0 FUN_600dc1c0
//   6007bb4c FUN_6007bb4c
//   600dc19e FUN_600dc19e
//   600dc1f2 FUN_600dc1f2
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6007c1d4 FUN_6007c1d4
//   6013d310 thunk_EXT_FUN_0000b52a
//   600dc4d6 FUN_600dc4d6


int FUN_600dc38e(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined1 auStack_38 [2];
  undefined2 local_36;
  int local_34;
  int local_30;
  
  thunk_EXT_FUN_0000b572(param_1,param_2,0x1b8);
  uVar1 = thunk_EXT_FUN_0000b532(0x13d4);
  iVar6 = param_1 + 0x1bc;
  FUN_6007c1d4(uVar1,param_1 + 8,param_5);
  *(undefined4 *)(param_1 + 0x1b8) = uVar1;
  FUN_600dc4d6(iVar6);
  local_36 = 0;
  FUN_600dc1c0(&local_34,0x1e0,&local_36,auStack_38);
  puVar2 = (undefined4 *)thunk_EXT_FUN_0000b532(0x18);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  piVar3 = (int *)thunk_EXT_FUN_0000b532(0x24);
  piVar7 = piVar3 + 9;
  puVar2[5] = piVar7;
  puVar2[3] = piVar3;
  puVar2[4] = piVar3;
  do {
    *piVar3 = 0;
    piVar3[1] = 0;
    piVar3[2] = 0;
    FUN_600dc19e(piVar3,local_30 - local_34 >> 1);
    iVar4 = *piVar3;
    iVar8 = local_30 - local_34;
    if (local_30 != local_34) {
      iVar4 = thunk_EXT_FUN_0000b588(iVar4,local_34,iVar8);
    }
    piVar5 = piVar3 + 3;
    piVar3[1] = iVar4 + iVar8;
    piVar3 = piVar5;
  } while (piVar7 != piVar5);
  puVar2[4] = piVar7;
  *(undefined4 **)(param_1 + 0x1d4) = puVar2;
  if (local_34 != 0) {
    thunk_EXT_FUN_0000b52a();
  }
  FUN_6007bb4c(param_1 + 0x1d8,param_1,param_3,param_4,param_5,*(undefined4 *)(param_1 + 0x1b8),
               iVar6,*(undefined4 *)(param_1 + 0x1d4));
  FUN_600dc1f2(param_1 + 0x45c,*(undefined4 *)(param_1 + 0x1b8),*(undefined4 *)(param_1 + 0x1d4));
  *(int *)(param_1 + 0x470) = iVar6;
  return param_1;
}


