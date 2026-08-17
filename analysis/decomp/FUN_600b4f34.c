// 600b4f34  FUN_600b4f34  size=166 bytes
// --- callers ---
//   600fca7c FUN_600fca7c
//   600f3bde FUN_600f3bde
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600bb6dc FUN_600bb6dc
//   600fa0d6 FUN_600fa0d6


undefined4 FUN_600b4f34(undefined4 param_1,undefined2 param_2,undefined1 param_3)

{
  int iVar1;
  char *pcVar2;
  char *local_10;
  int local_c;
  
  iVar1 = thunk_EXT_FUN_0000b554(DAT_600b4fdc,param_1,6);
  if (iVar1 == 0) {
    local_10 = DAT_600b4fe0;
    for (local_c = 0; local_c < 4; local_c = local_c + 1) {
      if (((*local_10 != '\0') && (local_10[1] == '\x04')) &&
         (*(undefined2 *)(local_10 + 0x14) = param_2, *(int *)(local_10 + 0x5c) == 0)) {
        FUN_600fa0d6(local_10);
      }
      local_10 = local_10 + 0xa4;
    }
  }
  else {
    pcVar2 = (char *)FUN_600bb6dc(param_1,param_3);
    if (((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) || (pcVar2[1] != '\x04')) {
      return 0;
    }
    *(undefined2 *)(pcVar2 + 0x14) = param_2;
    if (*(int *)(pcVar2 + 0x5c) == 0) {
      FUN_600fa0d6(pcVar2);
    }
  }
  return 1;
}


