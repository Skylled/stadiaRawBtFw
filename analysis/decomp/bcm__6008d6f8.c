// 6008d6f8  bcm__6008d6f8  size=292 bytes
// src: bcm.c
// --- callers ---
//   6008db50 bcm__6008db50
//   6008d730 bcm__6008d730
// --- callees ---
//   600eadd0 FUN_600eadd0
//   600ea89c FUN_600ea89c
//   600e0552 FUN_600e0552
//   600eb428 FUN_600eb428
//   600eb1d4 FUN_600eb1d4
//   600ea8ba FUN_600ea8ba


/* src: bcm.c */

undefined4 bcm__6008d6f8(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  code *pcVar5;
  code *pcVar6;
  undefined1 auStack_130 [68];
  int aiStack_ec [17];
  undefined1 auStack_a8 [68];
  undefined1 auStack_64 [76];
  int *local_18;
  
  local_18 = param_1;
  iVar1 = FUN_600eb428(param_1,*param_2);
  if (iVar1 == 0) {
    puVar3 = param_2 + 1;
    iVar1 = FUN_600eb1d4();
    if (iVar1 == 0) {
      piVar4 = param_1 + 0x1f;
      pcVar5 = *(code **)(*param_1 + 0x24);
      pcVar6 = *(code **)(*param_1 + 0x28);
      (*pcVar6)(param_1,auStack_130,puVar3);
      iVar1 = FUN_600eadd0(param_1,param_2 + 0x23,param_1 + 0x45);
      if (iVar1 == 0) {
        (*pcVar6)(param_1,aiStack_ec,param_2 + 0x23);
        (*pcVar6)(param_1,auStack_a8,aiStack_ec);
        (*pcVar5)(param_1,auStack_64,auStack_a8,aiStack_ec);
        if (param_1[0x30] == 0) {
          (*pcVar5)(param_1,aiStack_ec,auStack_a8,param_1 + 0xe);
          FUN_600ea89c(param_1,auStack_130,auStack_130,aiStack_ec);
        }
        else {
          FUN_600ea89c(param_1,aiStack_ec,auStack_a8);
          FUN_600ea89c(param_1,aiStack_ec,aiStack_ec,auStack_a8);
          FUN_600ea8ba(param_1,auStack_130,auStack_130,aiStack_ec);
        }
        (*pcVar5)(param_1,auStack_130,auStack_130,puVar3);
        (*pcVar5)(param_1,aiStack_ec,piVar4,auStack_64);
        piVar4 = aiStack_ec;
      }
      else {
        FUN_600ea89c(param_1,auStack_130,auStack_130,param_1 + 0xe);
        (*pcVar5)(param_1,auStack_130,auStack_130,puVar3);
      }
      FUN_600ea89c(param_1,auStack_130,auStack_130,piVar4);
      (*pcVar6)(param_1,aiStack_ec,param_2 + 0x12);
      uVar2 = FUN_600eadd0(param_1,aiStack_ec,auStack_130);
    }
    else {
      uVar2 = 1;
    }
    return uVar2;
  }
  local_18 = (int *)0x2f7;
  FUN_600e0552(0xf,0,0x6a,DAT_6008d72c);
  return 0;
}


