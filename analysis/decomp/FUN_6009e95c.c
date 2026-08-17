// 6009e95c  FUN_6009e95c  size=128 bytes
// --- callers ---
// --- callees ---
//   6009e84c FUN_6009e84c
//   6009e8fc FUN_6009e8fc
//   6009cad8 FUN_6009cad8
//   600b09f8 FUN_600b09f8


void FUN_6009e95c(void)

{
  undefined1 uVar1;
  undefined1 local_2a;
  undefined1 local_29;
  undefined4 local_28;
  undefined2 local_24;
  undefined1 *local_20;
  int local_1c;
  
  local_1c = DAT_6009e9dc;
  local_28 = 0;
  local_24 = 0;
  local_20 = DAT_6009e9e0;
  local_29 = 0;
  local_2a = *DAT_6009e9e0;
  if (*(char *)(DAT_6009e9dc + 0x12) == '\x01') {
    FUN_6009e8fc();
    uVar1 = FUN_6009cad8(local_1c,&local_28,&local_29,&local_2a);
    *(undefined1 *)(local_1c + 0x11) = uVar1;
    FUN_600b09f8(*(undefined2 *)(local_1c + 10),*(undefined2 *)(local_1c + 0xc),
                 *(undefined1 *)(local_1c + 0x11),local_2a,local_29,&local_28,
                 *(undefined1 *)(local_1c + 0xa4),*(undefined1 *)(local_1c + 0xe));
    FUN_6009e84c();
  }
  return;
}


