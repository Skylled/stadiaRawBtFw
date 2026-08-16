// 600ca4ac  tasks__600ca4ac  size=136 bytes
// src: tasks.c
// --- callers ---
//   600cbdd4 init__600cbdd4
// --- callees ---
//   600ca1f8 tasks__600ca1f8
//   601016a2 FUN_601016a2
//   600582f8 FUN_600582f8
//   600583a8 FUN_600583a8
//   600cc5ac FUN_600cc5ac
//   600cacb8 timers__600cacb8


/* src: tasks.c */

void tasks__600ca4ac(void)

{
  bool bVar1;
  int iVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_14 = 0;
  local_10 = 0;
  FUN_600583a8(&local_14,&local_10,&local_c);
  iVar2 = tasks__600ca1f8(DAT_600ca538,DAT_600ca534,local_c,0,0,local_10,local_14);
  *DAT_600ca53c = iVar2;
  if (iVar2 != 0) {
    iVar2 = timers__600cacb8();
    if (iVar2 == 1) {
      disableIRQinterrupts();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(0x50);
      }
      InstructionSynchronizationBarrier(0xf);
      DataSynchronizationBarrier(0xf);
      enableIRQinterrupts();
      *DAT_600ca544 = *DAT_600ca540 + 100;
      *DAT_600ca548 = 0xffffffff;
      *DAT_600ca54c = 1;
      *DAT_600ca550 = 0;
      FUN_600582f8();
      FUN_600cc5ac();
    }
    else if (iVar2 == -1) {
      FUN_601016a2(DAT_600ca55c,0x80f,DAT_600ca558);
    }
  }
  return;
}


