// 600ef3cc  FUN_600ef3cc  size=128 bytes
// --- callers ---
//   600fde94 FUN_600fde94
//   600fd9f4 FUN_600fd9f4
//   600fdc46 FUN_600fdc46
// --- callees ---
//   600aa648 FUN_600aa648
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600ef3cc(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x10);
    if (*(char *)(iVar1 + 0x27) != '\0') {
      *(char *)(iVar1 + 0x27) = *(char *)(iVar1 + 0x27) + -1;
    }
    if (*(char *)(*(int *)(param_1 + 0xc) + 6) != '\0') {
      *(char *)(*(int *)(param_1 + 0xc) + 6) = *(char *)(*(int *)(param_1 + 0xc) + 6) + -1;
    }
    if (*(char *)(iVar1 + 0x27) == '\0') {
      *(undefined1 *)(iVar1 + 7) = 0;
      *(undefined1 *)(iVar1 + 8) = 0;
      *(undefined2 *)(iVar1 + 0x34) = 0;
    }
    FUN_600aa648(param_1 + 0x14);
    thunk_EXT_FUN_0000b5ba(param_1,0,0x20);
  }
  return;
}


