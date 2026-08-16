// 600492ee  FUN_600492ee  size=410 bytes
// --- callers ---
// --- callees ---
//   60047968 FUN_60047968


int FUN_600492ee(undefined4 *param_1,uint param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  
  puStack_28 = param_1;
  uStack_24 = param_2;
  uStack_20 = param_3;
  puVar1 = (undefined4 *)func_0x600490b4(*param_1);
  if (puVar1 < (undefined4 *)param_1[0x1f]) {
    param_1[0x1f] = puVar1;
  }
  if ((undefined4 *)param_1[0x20] < puVar1) {
    param_1[0x20] = puVar1;
  }
  puStack_28 = puVar1;
  if ((undefined4 *)param_1[1] < puVar1) {
    if (puVar1 < (undefined4 *)param_1[0x19]) {
      piVar6 = param_1 + 1;
      iVar4 = 0xd;
      while (iVar5 = iVar4, 0 < iVar5) {
        iVar4 = iVar5 >> 1;
        iVar3 = func_0x6004c234(piVar6 + iVar4 * 2,&puStack_28);
        if (iVar3 != 0) {
          piVar6 = piVar6 + iVar4 * 2 + 2;
          iVar4 = (iVar5 - iVar4) + -1;
        }
      }
      uVar7 = ((piVar6[1] - piVar6[-1]) * ((int)puVar1 - piVar6[-2])) / (*piVar6 - piVar6[-2]) +
              piVar6[-1];
    }
    else {
      uVar7 = param_1[0x1a];
    }
  }
  else {
    uVar7 = param_1[2];
  }
  if (uVar7 < (uint)param_1[0x21]) {
    param_1[0x21] = uVar7;
  }
  param_1[0x23] = puVar1;
  param_1[0x24] = uVar7;
  if ((uint)param_1[0x22] < uVar7) {
    param_1[0x22] = uVar7;
  }
  uVar2 = FUN_60047968();
  uVar2 = ((uVar2 % 1000) * 1000 + 500) / 1000 + (uVar2 / 1000) * 1000;
  iVar4 = param_1[0x2c] + uVar7;
  if ((uVar2 < (uint)param_1[0x29]) || ((uint)param_1[0x25] < uVar2 - param_1[0x29])) {
    if ((uint)param_1[0x26] <= (uint)param_1[0x2a]) {
      iVar5 = param_1[0x2b];
      if (*(char *)(param_1 + 0x28) == '\0') {
        param_1[0x27] = iVar5;
      }
      else if (iVar5 < (int)param_1[0x27]) {
        param_1[0x27] = iVar5;
      }
      else {
        param_1[0x27] = param_1[0x27];
      }
      *(undefined1 *)(param_1 + 0x28) = 1;
    }
    param_1[0x2a] = 0;
  }
  if (param_1[0x2a] == 0) {
    param_1[0x29] = uVar2;
    param_1[0x2b] = iVar4;
    param_1[0x2a] = 1;
  }
  else {
    if ((int)param_1[0x2b] < iVar4) {
      param_1[0x2b] = iVar4;
    }
    else {
      param_1[0x2b] = param_1[0x2b];
    }
    param_1[0x2a] = param_1[0x2a] + 1;
  }
  if (*(char *)(param_1 + 0x28) != '\0') {
    if ((int)param_1[0x27] < (int)param_1[0x1b]) {
      param_1[0x1b] = param_1[0x27];
    }
  }
  if ((int)param_1[0x1b] < (int)uVar7) {
    if ((int)uVar7 < (int)param_1[0x1d]) {
      piVar6 = param_1 + 0x1b;
      iVar4 = 2;
      uStack_24 = uVar7;
      while (iVar5 = iVar4, 0 < iVar5) {
        iVar4 = iVar5 >> 1;
        iVar3 = func_0x6004c094(piVar6 + iVar4 * 2,&uStack_24);
        if (iVar3 != 0) {
          piVar6 = piVar6 + iVar4 * 2 + 2;
          iVar4 = (iVar5 - iVar4) + -1;
        }
      }
      iVar4 = (int)((piVar6[1] - piVar6[-1]) * (uVar7 - piVar6[-2])) / (*piVar6 - piVar6[-2]) +
              piVar6[-1];
    }
    else {
      iVar4 = param_1[0x1e];
    }
  }
  else {
    iVar4 = param_1[0x1c];
  }
  return iVar4;
}


