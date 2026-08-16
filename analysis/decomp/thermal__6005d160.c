// 6005d160  thermal__6005d160  size=114 bytes
// src: thermal.cc
// --- callers ---
//   6005d3b4 thermal__6005d3b4
// --- callees ---
//   600d3618 FUN_600d3618
//   6005d12c FUN_6005d12c
//   6005d714 trigger_bug_report__6005d714
//   600cbb14 FUN_600cbb14
//   6010165c FUN_6010165c


/* src: thermal.cc */

void thermal__6005d160(char param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char local_14 [4];
  
  if (param_1 == '\0') {
    *param_3 = 0;
  }
  else {
    uVar4 = *param_3;
    local_14[0] = param_1;
    if (uVar4 == 0) {
      iVar1 = FUN_600d3618();
      *param_3 = iVar1 + 60000;
    }
    else {
      uVar3 = FUN_600d3618();
      if (uVar4 < uVar3) {
        uVar2 = FUN_600cbb14(local_14);
        FUN_6010165c(0x28,DAT_6005d1d4,0xc5,DAT_6005d1dc,param_2,uVar2,*param_3);
        trigger_bug_report__6005d714(DAT_6005d1e0,0);
        FUN_6005d12c();
      }
    }
    uVar2 = FUN_600cbb14(local_14);
    FUN_6010165c(0x28,DAT_6005d1d4,200,DAT_6005d1d8,param_2,uVar2,*param_3);
  }
  return;
}


