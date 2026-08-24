// 600f0b06  FUN_600f0b06  size=178 bytes
// --- callers ---
//   600ac2a4 FUN_600ac2a4
//   600fadb6 FUN_600fadb6
//   600f0bb8 FUN_600f0bb8
// --- callees ---
//   6009ff18 FUN_6009ff18


void FUN_600f0b06(undefined4 param_1,byte param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 local_a;
  undefined1 local_9;
  
  iVar1 = FUN_6009ff18(param_1);
  if (iVar1 != 0) {
    if ((*(char *)(iVar1 + 0x50) == '\x02') || (*(char *)(iVar1 + 0x50) == '\x01')) {
      *param_3 = 3;
    }
    else {
      local_9 = 1;
      if ((param_2 & 4) != 0) {
        local_9 = 4;
      }
      if ((*(ushort *)(iVar1 + 0x2a) & 0x400) == 0) {
        if ((*(byte *)(iVar1 + 0x7b) & 1) == 0) {
          local_a = 0;
        }
        else {
          local_a = *(byte *)(iVar1 + 0xd8);
        }
      }
      else if ((*(ushort *)(iVar1 + 0x2a) & 0x200) == 0) {
        local_a = 1;
      }
      else {
        local_a = 4;
      }
      if (local_a < local_9) {
        *param_3 = 2;
      }
      else {
        *param_3 = 1;
      }
    }
  }
  return;
}


