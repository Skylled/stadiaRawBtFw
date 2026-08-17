// 6009e8fc  FUN_6009e8fc  size=88 bytes
// --- callers ---
//   6009cc7c FUN_6009cc7c
//   6009c848 FUN_6009c848
//   6009e95c FUN_6009e95c
//   6009f4e4 FUN_6009f4e4
//   600f1334 FUN_600f1334
//   6009dc14 FUN_6009dc14
//   6009daac FUN_6009daac
// --- callees ---
//   6009ec14 FUN_6009ec14
//   600b0c60 FUN_600b0c60


undefined1 FUN_6009e8fc(void)

{
  int iVar1;
  int iVar2;
  undefined1 local_9;
  
  iVar1 = DAT_6009e954;
  local_9 = 0;
  if (*(char *)(DAT_6009e954 + 0x12) == '\x01') {
    iVar2 = FUN_600b0c60(0);
    if (iVar2 == 0) {
      local_9 = 3;
    }
    else {
      *(undefined1 *)(iVar1 + 0x1b) = 0;
      *(undefined1 *)(iVar1 + 0x12) = 0;
      *(byte *)(DAT_6009e958 + 0x9c6) = *(byte *)(DAT_6009e958 + 0x9c6) & 0xfb;
      FUN_6009ec14(0x231);
    }
  }
  return local_9;
}


