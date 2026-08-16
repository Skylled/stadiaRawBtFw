// 600ca1b4  tasks__600ca1b4  size=58 bytes
// src: tasks.c
// --- callers ---
//   600ca27c tasks__600ca27c
// --- callees ---
//   600cdbd8 FUN_600cdbd8
//   601016a2 FUN_601016a2
//   6013d180 thunk_EXT_FUN_000080d8


/* src: tasks.c */

void tasks__600ca1b4(int param_1)

{
  char cVar1;
  
  FUN_600cdbd8(param_1 + 100);
  cVar1 = *(char *)(param_1 + 0xc9);
  if (cVar1 == '\0') {
    thunk_EXT_FUN_000080d8(*(undefined4 *)(param_1 + 0x30));
  }
  else if (cVar1 != '\x01') {
    if (cVar1 != '\x02') {
      FUN_601016a2(DAT_600ca1f4,0x101a,DAT_600ca1f0);
      return;
    }
    return;
  }
  thunk_EXT_FUN_000080d8(param_1);
  return;
}


