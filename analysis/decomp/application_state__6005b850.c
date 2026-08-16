// 6005b850  application_state__6005b850  size=114 bytes
// src: application_state.cc
// --- callers ---
//   6005b8dc application_state__6005b8dc
// --- callees ---
//   600d37ac FUN_600d37ac
//   600d4036 FUN_600d4036
//   600d3e60 FUN_600d3e60
//   600d3b3a FUN_600d3b3a
//   600d3b24 FUN_600d3b24
//   6005b794 application_state__6005b794


/* src: application_state.cc */

void application_state__6005b850(int param_1)

{
  int iVar1;
  int local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 auStack_98 [144];
  
  iVar1 = FUN_600d3e60();
  if (iVar1 - 2U < 0xb) {
    local_a4 = (int)*(char *)(DAT_6005b8c4 + (iVar1 - 2U));
  }
  else {
    local_a4 = 1;
  }
  if (*(int *)(param_1 + 0x78) != local_a4) {
    local_a0 = DAT_6005b8c8;
    local_9c = 0xce;
    FUN_600d3b3a(auStack_98);
    FUN_600d37ac(auStack_98,DAT_6005b8cc);
    FUN_600d37ac(auStack_98,DAT_6005b8d0);
    FUN_600d37ac(auStack_98,DAT_6005b8d4);
    FUN_600d4036(auStack_98,param_1 + 0x78);
    FUN_600d37ac(auStack_98,DAT_6005b8d8);
    FUN_600d4036(auStack_98,&local_a4);
    FUN_600d3b24(&local_a0);
    *(int *)(param_1 + 0x78) = local_a4;
    application_state__6005b794(param_1);
  }
  return;
}


