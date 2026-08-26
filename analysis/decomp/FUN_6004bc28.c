// 6004bc28  FUN_6004bc28  size=112 bytes
// --- callers ---
//   60047548 FUN_60047548
//   60047290 queue__60047290
//   60047678 queue__60047678
//   6004bc98 FUN_6004bc98
// --- callees ---
//   60047d80 tasks__60047d80
//   6004bfb4 thunk_FUN_600ca6a4
//   60048580 FUN_60048580
//   600485c8 FUN_600485c8


void FUN_6004bc28(int param_1)

{
  char cVar1;
  int iVar2;
  
  FUN_60048580();
  cVar1 = *(char *)(param_1 + 0x45);
  while (('\0' < cVar1 && (*(int *)(param_1 + 0x24) != 0))) {
    iVar2 = tasks__60047d80(param_1 + 0x24);
    if (iVar2 != 0) {
      thunk_FUN_600ca6a4();
    }
    cVar1 = cVar1 + -1;
  }
  *(undefined1 *)(param_1 + 0x45) = 0xff;
  FUN_600485c8();
  FUN_60048580();
  cVar1 = *(char *)(param_1 + 0x44);
  while (('\0' < cVar1 && (*(int *)(param_1 + 0x10) != 0))) {
    iVar2 = tasks__60047d80(param_1 + 0x10);
    if (iVar2 != 0) {
      thunk_FUN_600ca6a4();
    }
    cVar1 = cVar1 + -1;
  }
  *(undefined1 *)(param_1 + 0x44) = 0xff;
  FUN_600485c8();
  return;
}


