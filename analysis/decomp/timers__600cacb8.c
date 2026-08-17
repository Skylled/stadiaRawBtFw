// 600cacb8  timers__600cacb8  size=82 bytes
// src: timers.c
// --- callers ---
//   600ca4ac tasks__600ca4ac
// --- callees ---
//   600ca1f8 tasks__600ca1f8
//   600583d8 FUN_600583d8
//   601016a2 FUN_601016a2
//   600cac50 FUN_600cac50


/* src: timers.c */

undefined4 timers__600cacb8(void)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  FUN_600cac50();
  if (*DAT_600cad0c != 0) {
    local_14 = 0;
    local_10 = 0;
    FUN_600583d8(&local_14,&local_10,&local_c);
    iVar1 = tasks__600ca1f8(DAT_600cad14,DAT_600cad10,local_c,0,0x1f,local_10,local_14);
    *DAT_600cad18 = iVar1;
    if (iVar1 != 0) {
      return 1;
    }
  }
  FUN_601016a2(DAT_600cad1c,0x10f,DAT_600cad20);
  return 0;
}


