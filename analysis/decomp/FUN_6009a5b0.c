// 6009a5b0  FUN_6009a5b0  size=370 bytes
// --- callers ---
//   600a3d8c FUN_600a3d8c
// --- callees ---
//   600b2764 FUN_600b2764
//   60099190 FUN_60099190
//   600b26d0 FUN_600b26d0
//   600b2eec FUN_600b2eec


void FUN_6009a5b0(undefined2 *param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  char local_a;
  char local_9;
  
  local_9 = '\x01';
  local_a = '\x01';
  if ((*(char *)((int)param_1 + 299) == '\x01') || (*(char *)(param_1 + 0x96) == '\x01')) {
    if (((param_2 == 0) || ((*(ushort *)(param_2 + 0x2a) & 4) == 0)) ||
       (((*(byte *)((int)param_1 + 0x113) & 4) != 0 && ((*(byte *)(DAT_6009a724 + 0x818) & 4) != 0))
       )) {
      if (*(char *)((int)param_1 + 299) == '\x01') {
        *(undefined1 *)((int)param_1 + 299) = 5;
        if (param_2 != 0) {
          *(undefined1 *)(param_2 + 0xee) = 1;
        }
        local_9 = FUN_600b2eec(param_1 + 3,*(char *)((int)param_1 + 0x129) == '\0');
      }
      if (*(char *)(param_1 + 0x96) == '\x01') {
        *(undefined1 *)((int)param_1 + 299) = 5;
        local_a = FUN_600b2764(*param_1);
      }
    }
    else {
      iVar1 = FUN_600b26d0(*param_1,0);
      if (iVar1 == 0) {
        local_9 = *(char *)((int)param_1 + 299) != '\x01';
        if (*(char *)(param_1 + 0x96) == '\x01') {
          local_a = '\0';
        }
      }
      else {
        *(undefined1 *)((int)param_1 + 0x12d) = 1;
        if (*(char *)((int)param_1 + 299) == '\x01') {
          *(undefined1 *)((int)param_1 + 299) = 2;
        }
        if (*(char *)(param_1 + 0x96) == '\x01') {
          *(undefined1 *)(param_1 + 0x96) = 2;
        }
      }
    }
    if (local_9 == '\0') {
      *(undefined1 *)((int)param_1 + 299) = 0;
      FUN_60099190(param_3,param_1 + 3);
    }
    if ((local_a == '\0') &&
       (*(undefined1 *)(param_1 + 0x96) = 0, *(int *)(DAT_6009a724 + 0x7dc) != 0)) {
      *(undefined1 *)(DAT_6009a724 + 0x7d4) = param_3;
      (**(code **)(DAT_6009a724 + 0x7dc))(DAT_6009a728);
      *(undefined4 *)(DAT_6009a724 + 0x7dc) = 0;
    }
  }
  return;
}


