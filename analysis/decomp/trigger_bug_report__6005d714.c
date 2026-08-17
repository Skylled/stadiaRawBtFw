// 6005d714  trigger_bug_report__6005d714  size=152 bytes
// src: trigger_bug_report.cc
// --- callers ---
//   60071884 FUN_60071884
//   60074658 timer__60074658
//   6005d160 thermal__6005d160
//   6007991c http_flash_writer__6007991c
//   6005d3b4 thermal__6005d3b4
// --- callees ---
//   600d3618 FUN_600d3618
//   6013d088 thunk_EXT_FUN_00007734
//   6005bdac FUN_6005bdac
//   600653f8 FUN_600653f8
//   6010165c FUN_6010165c
//   601016a2 FUN_601016a2
//   6013d398 thunk_EXT_FUN_00001834
//   60101198 FUN_60101198


/* src: trigger_bug_report.cc */

void trigger_bug_report__6005d714(char *param_1,undefined4 param_2)

{
  char cVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  char *pcVar7;
  uint uVar8;
  
  pcVar7 = param_1;
  do {
    uVar8 = (int)pcVar7 - (int)param_1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  iVar4 = thunk_EXT_FUN_00007734();
  if ((iVar4 != 2) || ((*(uint *)(DAT_6005d7ac + 4) & 0x1ff) != 0)) {
    FUN_601016a2(DAT_6005d7b4,0x25,DAT_6005d7b0);
  }
  puVar2 = DAT_6005d7b8;
  uVar5 = FUN_600d3618();
  if (uVar5 < *puVar2) {
    FUN_6010165c(0x28,DAT_6005d7b4,0x2a,DAT_6005d7bc,param_1);
  }
  else {
    iVar4 = FUN_600d3618();
    uVar3 = DAT_6005d7c0;
    uVar6 = DAT_6005d7b4;
    *puVar2 = iVar4 + 60000;
    FUN_6010165c(0x14,uVar6,0x30,uVar3,param_1);
    uVar6 = FUN_600653f8();
    if (99 < uVar8) {
      uVar8 = 100;
    }
    FUN_60101198(uVar6,DAT_6005d7c4,param_1,uVar8 & 0xffff);
    uVar6 = FUN_6005bdac();
    thunk_EXT_FUN_00001834(uVar6,5,param_2,1,0);
  }
  return;
}


