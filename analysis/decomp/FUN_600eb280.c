// 600eb280  FUN_600eb280  size=240 bytes
// --- callers ---
// --- callees ---
//   600eadd0 FUN_600eadd0
//   600ea8ba FUN_600ea8ba
//   600eb1d4 FUN_600eb1d4
//   600ea89c FUN_600ea89c


undefined4 FUN_600eb280(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  code *pcVar4;
  code *pcVar5;
  undefined1 auStack_130 [68];
  int aiStack_ec [17];
  undefined1 auStack_a8 [68];
  undefined1 auStack_64 [72];
  
  iVar1 = FUN_600eb1d4();
  if (iVar1 == 0) {
    piVar3 = param_1 + 0x1f;
    pcVar4 = *(code **)(*param_1 + 0x24);
    pcVar5 = *(code **)(*param_1 + 0x28);
    (*pcVar5)(param_1,auStack_130,param_2);
    iVar1 = FUN_600eadd0(param_1,param_2 + 0x88,param_1 + 0x45);
    if (iVar1 == 0) {
      (*pcVar5)(param_1,aiStack_ec,param_2 + 0x88);
      (*pcVar5)(param_1,auStack_a8,aiStack_ec);
      (*pcVar4)(param_1,auStack_64,auStack_a8,aiStack_ec);
      if (param_1[0x30] == 0) {
        (*pcVar4)(param_1,aiStack_ec,auStack_a8,param_1 + 0xe);
        FUN_600ea89c(param_1,auStack_130,auStack_130,aiStack_ec);
      }
      else {
        FUN_600ea89c(param_1,aiStack_ec,auStack_a8);
        FUN_600ea89c(param_1,aiStack_ec,aiStack_ec,auStack_a8);
        FUN_600ea8ba(param_1,auStack_130,auStack_130,aiStack_ec);
      }
      (*pcVar4)(param_1,auStack_130,auStack_130,param_2);
      (*pcVar4)(param_1,aiStack_ec,piVar3,auStack_64);
      piVar3 = aiStack_ec;
    }
    else {
      FUN_600ea89c(param_1,auStack_130,auStack_130,param_1 + 0xe);
      (*pcVar4)(param_1,auStack_130,auStack_130,param_2);
    }
    FUN_600ea89c(param_1,auStack_130,auStack_130,piVar3);
    (*pcVar5)(param_1,aiStack_ec,param_2 + 0x44);
    uVar2 = FUN_600eadd0(param_1,aiStack_ec,auStack_130);
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


