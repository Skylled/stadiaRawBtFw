// 6005e58c  bug_report__6005e58c  size=214 bytes
// src: bug_report.cc
// --- callers ---
//   6005e734 FUN_6005e734
// --- callees ---
//   6005e25c FUN_6005e25c
//   601018de FUN_601018de
//   6010165c FUN_6010165c
//   6005e200 bug_report__6005e200
//   600d4652 FUN_600d4652


/* src: bug_report.cc */

ushort bug_report__6005e58c(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  code *pcVar9;
  char local_23;
  ushort local_22 [3];
  
  iVar1 = DAT_6005e664;
  FUN_6005e25c(DAT_6005e664);
  uVar3 = bug_report__6005e200(iVar1 + 0x10,param_1);
  uVar4 = FUN_600d4652(*(undefined4 *)(iVar1 + 0xc));
  if (uVar3 < uVar4) {
    piVar8 = *(int **)(iVar1 + 0xc);
    pcVar9 = *(code **)(*piVar8 + 0xc);
    uVar5 = bug_report__6005e200(iVar1 + 0x10,2);
    cVar2 = (*pcVar9)(piVar8,uVar3,uVar5,&local_23);
    if (((cVar2 == '\0') && (local_23 == '\0')) &&
       (cVar2 = FUN_601018de(*(undefined4 *)(iVar1 + 0xc),local_22,uVar3,2), cVar2 == '\0')) {
      if (local_22[0] < 0x201) {
        iVar6 = bug_report__6005e200(iVar1 + 0x10,2);
        if (local_22[0] != 0) {
          iVar7 = bug_report__6005e200(iVar1 + 0x10);
          uVar4 = FUN_600d4652(*(undefined4 *)(iVar1 + 0xc));
          if (((uVar3 + iVar6 + iVar7 <= uVar4) && (local_22[0] <= param_3)) &&
             (cVar2 = FUN_601018de(*(undefined4 *)(iVar1 + 0xc),param_2,uVar3 + iVar6),
             cVar2 == '\0')) {
            return local_22[0];
          }
        }
      }
      else {
        FUN_6010165c(0x28,DAT_6005e668,0x130,DAT_6005e66c,uVar3,local_22[0]);
      }
    }
  }
  return 0;
}


