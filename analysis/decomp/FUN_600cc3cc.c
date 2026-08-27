// 600cc3cc  FUN_600cc3cc  size=122 bytes
// --- callers ---
//   600d37ce FUN_600d37ce
//   600d3534 FUN_600d3534
//   600cbccc FUN_600cbccc
//   600ce4fc FUN_600ce4fc
//   60058318 FUN_60058318
//   600cc450 FUN_600cc450
//   60083900 FUN_60083900
//   6007fe74 FUN_6007fe74
//   60061d38 FUN_60061d38
//   600dadaa FUN_600dadaa
//   600d3938 FUN_600d3938
//   6005e020 power_rpcs__6005e020
//   6006185c FUN_6006185c
//   600ce55c FUN_600ce55c
//   60101aa4 FUN_60101aa4
//   600d4566 FUN_600d4566
//   600ce52c FUN_600ce52c
//   6007f7a0 FUN_6007f7a0
//   6005dcc0 FUN_6005dcc0
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6004cb28 FUN_6004cb28


undefined4 FUN_600cc3cc(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  char *pcVar6;
  
  pcVar6 = (char *)*param_1;
  if (*pcVar6 == '{') {
    iVar3 = FUN_6004cb28(param_2);
    puVar2 = DAT_600cc44c;
    iVar5 = param_1[2];
    if ((uint)(iVar5 + 7 + iVar3) <= (uint)param_1[1]) {
      if (iVar5 == 2) {
        pcVar6[1] = '\"';
      }
      else {
        *(undefined2 *)(pcVar6 + iVar5 + -1) = *DAT_600cc44c;
        pcVar6[iVar5 + 1] = *(char *)(puVar2 + 1);
        param_1[2] = param_1[2] + 2;
      }
      thunk_EXT_FUN_0000b572(*param_1 + param_1[2],param_2,iVar3,param_1[2],param_4);
      iVar5 = *param_1;
      iVar3 = iVar3 + param_1[2];
      uVar1 = *DAT_600cc448;
      uVar4 = *(undefined1 *)(DAT_600cc448 + 1);
      param_1[2] = iVar3;
      *(undefined2 *)(iVar5 + iVar3) = uVar1;
      *(undefined1 *)(iVar5 + iVar3 + 2) = uVar4;
      param_1[2] = param_1[2] + 3;
      return 1;
    }
    uVar4 = 8;
  }
  else {
    uVar4 = 9;
  }
  *(undefined1 *)((int)param_1 + 0xd) = uVar4;
  *(undefined1 *)(param_1 + 3) = uVar4;
  return 0;
}


