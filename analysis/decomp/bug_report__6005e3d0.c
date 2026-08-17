// 6005e3d0  bug_report__6005e3d0  size=194 bytes
// src: bug_report.cc
// --- callers ---
//   600d4664 FUN_600d4664
// --- callees ---
//   601018de FUN_601018de
//   6010165c FUN_6010165c
//   6005e200 bug_report__6005e200
//   600d4652 FUN_600d4652


/* src: bug_report.cc */

uint bug_report__6005e3d0(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  code *pcVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uStack_1c;
  
  iVar7 = param_1 + 0x10;
  *(undefined4 *)(param_1 + 8) = 0;
  iVar10 = param_1;
  uStack_1c = param_2;
  do {
    uVar5 = *(uint *)(param_1 + 8);
    uVar1 = FUN_600d4652(*(undefined4 *)(param_1 + 0xc));
    if (uVar1 <= uVar5) {
      FUN_6010165c(0x1e,DAT_6005e494,0x179,DAT_6005e49c,iVar10);
LAB_6005e462:
      *(undefined1 *)(param_1 + 4) = 1;
      return 0;
    }
    piVar6 = *(int **)(param_1 + 0xc);
    uVar9 = *(undefined4 *)(param_1 + 8);
    pcVar8 = *(code **)(*piVar6 + 0xc);
    uVar2 = bug_report__6005e200(iVar7,2);
    uVar1 = (*pcVar8)(piVar6,uVar9,uVar2,(int)&uStack_1c + 1);
    if ((uVar1 & 0xff) != 0) {
      return uVar1;
    }
    if (uStack_1c._1_1_ != '\0') {
      *(undefined1 *)(param_1 + 4) = 1;
      return 0;
    }
    uVar1 = FUN_601018de(*(undefined4 *)(param_1 + 0xc),(int)&uStack_1c + 2,
                         *(undefined4 *)(param_1 + 8),2);
    if ((uVar1 & 0xff) != 0) {
      return uVar1;
    }
    if (0x200 < uStack_1c._2_2_) {
      FUN_6010165c(0x28,DAT_6005e494,0x170,DAT_6005e498);
      piVar6 = *(int **)(param_1 + 0xc);
      pcVar8 = *(code **)*piVar6;
      uVar2 = (*(code *)((undefined4 *)*piVar6)[5])(piVar6);
      (*pcVar8)(piVar6,0,uVar2);
      *(undefined4 *)(param_1 + 8) = 0;
      goto LAB_6005e462;
    }
    iVar3 = bug_report__6005e200(iVar7);
    iVar4 = bug_report__6005e200(iVar7,2);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar4 + iVar3;
  } while( true );
}


