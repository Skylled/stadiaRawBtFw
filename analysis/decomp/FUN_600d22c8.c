// 600d22c8  FUN_600d22c8  size=134 bytes
// --- callers ---
//   6005663c FUN_6005663c
//   600d234e FUN_600d234e
//   600d265a FUN_600d265a
// --- callees ---
//   600563b8 FUN_600563b8


undefined4 FUN_600d22c8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (param_1 == 0) {
    return 3;
  }
  bVar3 = false;
  iVar7 = *(int *)(param_1 + 4);
  bVar2 = false;
  iVar5 = param_1;
  while (iVar5 != param_1 + (uint)*(byte *)(param_1 + 0x412) * 0x40) {
    piVar1 = (int *)(iVar5 + 0x38);
    iVar5 = iVar5 + 0x40;
    if (*(char *)(*piVar1 + 5) == '\t') {
      bVar2 = true;
    }
    else {
      bVar3 = true;
    }
  }
  if ((bVar3) && (*(code **)(iVar7 + 4) != (code *)0x0)) {
    iVar4 = (**(code **)(iVar7 + 4))(param_1,param_1 + 8,param_2);
    if (bVar2) {
      iVar5 = FUN_600563b8(iVar7,param_1,param_1 + 8,param_2,param_4);
      if (iVar4 != 0) goto LAB_600d2340;
    }
    else if (iVar4 != 0) goto LAB_600d2344;
LAB_600d2310:
    uVar6 = 0;
  }
  else {
    if (bVar2) {
      iVar5 = FUN_600563b8(iVar7,param_1,param_1 + 8,param_2,param_4);
LAB_600d2340:
      if (iVar5 == 0) goto LAB_600d2310;
    }
LAB_600d2344:
    if (param_2 == 1) {
      uVar6 = 8;
    }
    else {
      uVar6 = 1;
    }
  }
  return uVar6;
}


