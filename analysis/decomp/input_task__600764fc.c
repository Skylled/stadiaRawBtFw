// 600764fc  input_task__600764fc  size=160 bytes
// src: input_task.cc
// --- callers ---
//   600dad26 FUN_600dad26
// --- callees ---
//   600d37b8 FUN_600d37b8
//   60066070 keys__60066070
//   60076438 input_task__60076438
//   60065db0 FUN_60065db0
//   600cb598 key_value_store__600cb598
//   600d3b3a FUN_600d3b3a
//   600d37ac FUN_600d37ac
//   60065dd8 FUN_60065dd8
//   601010c8 FUN_601010c8
//   600d736c FUN_600d736c
//   60101ba2 FUN_60101ba2
//   600d6e14 FUN_600d6e14


/* src: input_task.cc */

void input_task__600764fc(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  int local_a8;
  int local_a4;
  int iStack_a0;
  
  iVar2 = FUN_600d6e14(param_2);
  if (iVar2 == 0) {
    cVar1 = keys__60066070(param_2,&local_b4,4);
LAB_60076546:
    if (cVar1 == '\0') goto LAB_60076584;
  }
  else {
    uVar3 = FUN_60065db0(param_2);
    uVar4 = FUN_60065dd8(param_2);
    local_b0 = (uint)local_b0._2_2_ << 0x10;
    cVar1 = FUN_601010c8(uVar3,uVar4,&local_b0);
    if ((cVar1 == '\0') && ((local_b0 & 0xffff) == 4)) {
      cVar1 = key_value_store__600cb598(uVar3,uVar4,&local_b4,4,0);
      goto LAB_60076546;
    }
  }
  local_b0 = DAT_6007659c;
  local_ac = 0x294;
  FUN_600d3b3a(&local_a8);
  FUN_600d37ac(&local_a8,DAT_600765a0);
  uVar3 = FUN_600d736c(param_2,local_a8 + iStack_a0,local_a4 - iStack_a0);
  FUN_60101ba2(&local_a8,uVar3);
  FUN_600d37b8(&local_b0);
  local_b4 = 0x10;
LAB_60076584:
  input_task__60076438(param_1,local_b4);
  return;
}


