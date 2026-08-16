// 600485c8  FUN_600485c8  size=34 bytes
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
//   6004bc28 FUN_6004bc28
//   600480cc FUN_600480cc
//   60047290 queue__60047290
// --- callees ---
//   6004c084 thunk_FUN_601016a2


void FUN_600485c8(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = DAT_600485ec;
  if (*DAT_600485ec == 0) {
    thunk_FUN_601016a2(DAT_600485f4,0x19a,DAT_600485f0);
  }
  iVar3 = *piVar2 + -1;
  *piVar2 = iVar3;
  if ((iVar3 == 0) && (bVar1 = (bool)isCurrentModePrivileged(), bVar1)) {
    setBasePriority(0);
  }
  return;
}


