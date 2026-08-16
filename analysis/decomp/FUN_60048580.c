// 60048580  FUN_60048580  size=56 bytes
// --- callers ---
//   6004bb82 FUN_6004bb82
//   60047aa8 tasks__60047aa8
//   600471bc queue__600471bc
//   60047678 queue__60047678
//   600477e4 queue__600477e4
//   60047ea8 tasks__60047ea8
//   6004bc98 FUN_6004bc98
//   60048474 FUN_60048474
//   60047548 FUN_60047548
//   6004703c FUN_6004703c
//   6004901e FUN_6004901e
//   6004bc28 FUN_6004bc28
//   600480cc FUN_600480cc
//   60047290 queue__60047290
// --- callees ---
//   6004c084 thunk_FUN_601016a2


void FUN_60048580(void)

{
  bool bVar1;
  int iVar2;
  
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x50);
  }
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  enableIRQinterrupts();
  iVar2 = *DAT_600485b8;
  *DAT_600485b8 = iVar2 + 1;
  if ((iVar2 + 1 == 1) && ((*DAT_600485bc & 0xff) != 0)) {
    thunk_FUN_601016a2(DAT_600485c4,0x193,DAT_600485c0);
    return;
  }
  return;
}


