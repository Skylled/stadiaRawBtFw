// 6004a82e  FUN_6004a82e  size=52 bytes
// --- callers ---
//   6004a3c4 FUN_6004a3c4
// --- callees ---
//   6004bff4 thunk_FUN_6007d978
//   6004560c FUN_6004560c
//   6004c02c thunk_FUN_600ddafa


void FUN_6004a82e(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x14);
  iVar3 = *(int *)(param_1 + 0x18);
  iVar1 = FUN_6004560c();
  if (iVar1 == 0) {
    if (iVar3 != iVar2) {
      thunk_FUN_600ddafa(param_1);
    }
  }
  else {
    thunk_FUN_6007d978(param_1);
  }
  *(char *)(param_1 + 0x58) = *(char *)(param_1 + 100);
  if (*(char *)(param_1 + 100) != '\0') {
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined1 *)(param_1 + 100) = 0;
  }
  return;
}


