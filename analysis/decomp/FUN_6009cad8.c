// 6009cad8  FUN_6009cad8  size=416 bytes
// --- callers ---
//   6009e95c FUN_6009e95c
//   6009dc14 FUN_6009dc14
//   6009daac FUN_6009daac
//   6009cc7c FUN_6009cc7c
//   6009c848 FUN_6009c848
// --- callees ---
//   6009f644 FUN_6009f644
//   600f1746 FUN_600f1746
//   6009f93c FUN_6009f93c
//   6013d3a0 thunk_EXT_FUN_0000b572


char FUN_6009cad8(int param_1,undefined4 param_2,undefined1 *param_3,undefined1 *param_4)

{
  int iVar1;
  byte local_a;
  char local_9;
  
  if (*(short *)(param_1 + 2) == 0) {
    if (*(char *)(param_1 + 0xc0) == '\0') {
      local_9 = '\x03';
    }
    else {
      local_9 = '\x02';
    }
  }
  else {
    local_9 = '\0';
  }
  if ((local_9 == '\0') &&
     ((local_9 = *(char *)(param_1 + 0x1a), *(char *)(param_1 + 0x1a) == '\x01' ||
      (*(char *)(param_1 + 0x1a) == '\x04')))) {
    if ((*(char *)(DAT_6009cc78 + 0xa6a) == '\x02') || (*(char *)(DAT_6009cc78 + 0xa6a) == '\x03'))
    {
      iVar1 = FUN_600f1746(param_1 + 0x14);
      if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x72) & 2) != 0)) {
        FUN_6009f93c(4);
        thunk_EXT_FUN_0000b572(param_2,iVar1 + 0x6c,6);
        *param_3 = *(undefined1 *)(iVar1 + 0x6b);
        *param_4 = 3;
        return local_9;
      }
      FUN_6009f644(4,1);
    }
    *param_3 = *(undefined1 *)(param_1 + 0x13);
    thunk_EXT_FUN_0000b572(param_2,param_1 + 0x14,6);
  }
  else if (((*(char *)(DAT_6009cc78 + 0xa6a) == '\x02') && (*(char *)(param_1 + 0xe) != '\0')) ||
          (*(char *)(DAT_6009cc78 + 0xa6a) == '\x03')) {
    for (local_a = 0; local_a < 8; local_a = local_a + 1) {
      if (((*(ushort *)(DAT_6009cc78 + (uint)local_a * 0xfc + 0x12f2) & 0x80) != 0) &&
         ((*(byte *)(DAT_6009cc78 + (uint)local_a * 0xfc + 0x133a) & 2) != 0)) {
        thunk_EXT_FUN_0000b572(param_2,DAT_6009cc78 + (uint)local_a * 0xfc + 0x1334,6);
        *param_3 = *(undefined1 *)(DAT_6009cc78 + (uint)local_a * 0xfc + 0x1333);
        break;
      }
    }
    if (local_a == 8) {
      *param_4 = 1;
    }
    else {
      *param_4 = 3;
    }
  }
  else if (*(char *)(DAT_6009cc78 + 0xa6a) != '\0') {
    *param_4 = 1;
  }
  return local_9;
}


