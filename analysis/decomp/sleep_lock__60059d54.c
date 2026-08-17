// 60059d54  sleep_lock__60059d54  size=238 bytes
// src: sleep_lock.cc
// --- callers ---
// --- callees ---
//   60101b76 FUN_60101b76
//   601016f0 FUN_601016f0
//   60059cd8 FUN_60059cd8
//   600cbb14 FUN_600cbb14
//   6005990c sleep_driver__6005990c
//   6013cf80 thunk_EXT_FUN_0000714c
//   6010165c FUN_6010165c


/* src: sleep_lock.cc */

void sleep_lock__60059d54(void)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  char local_b0 [4];
  uint local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 *local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [134];
  
  pcVar1 = DAT_60059e44;
  if (*DAT_60059e44 == '\0') {
    return;
  }
  uVar4 = thunk_EXT_FUN_0000714c();
  uVar4 = ((uVar4 % 1000) * 1000 + 500) / 1000 + (uVar4 / 1000) * 1000;
  if (*(uint *)(pcVar1 + 4) <= uVar4) {
    FUN_6010165c(0x1e,DAT_60059e54,0x3f,PTR_s_Did_not_attempt_to_sleep_until_a_60059e64);
    goto LAB_60059db0;
  }
  local_ac = 0;
  if (*DAT_60059e48 == 0) {
    cVar3 = '\r';
  }
  else {
    cVar3 = sleep_driver__6005990c(*DAT_60059e48,*(uint *)(pcVar1 + 4) - uVar4,&local_ac);
    pcVar2 = DAT_60059e4c;
    if (cVar3 == '\t') {
      if (*DAT_60059e4c == '\0') {
        FUN_6010165c(0x14,DAT_60059e54,0x35,DAT_60059e50);
        *pcVar2 = '\x01';
      }
      goto LAB_60059db0;
    }
    if (cVar3 == '\0') {
      FUN_6010165c(0x14,DAT_60059e54,0x3b,PTR_s_Slept_for__lu_ms_60059e60,local_ac);
      iVar6 = 0;
      if (local_ac < *(uint *)(pcVar1 + 4)) {
        iVar6 = *(uint *)(pcVar1 + 4) - local_ac;
      }
      *(int *)(pcVar1 + 4) = iVar6;
      goto LAB_60059db0;
    }
  }
  local_a8 = DAT_60059e54;
  local_a4 = 0x39;
  local_a0 = local_92;
  local_9c = 0x80;
  uStack_98 = 0;
  local_94 = 0;
  local_93 = 0;
  local_92[0] = 0;
  FUN_60101b76(&local_a0,PTR_s_Unable_to_sleep__60059e5c);
  local_b0[0] = cVar3;
  uVar5 = FUN_600cbb14(local_b0);
  FUN_60101b76(&local_a0,uVar5);
  FUN_601016f0(0x1e,local_a8,local_a4,&local_a0);
LAB_60059db0:
  uVar5 = DAT_60059e58;
  *pcVar1 = '\0';
  local_a8 = 0xb;
  FUN_60059cd8(uVar5,&local_a8);
  return;
}


