// 600b7c94  FUN_600b7c94  size=38 bytes
// --- callers ---
//   600b7800 FUN_600b7800
// --- callees ---


void FUN_600b7c94(int param_1,undefined4 param_2,ushort param_3)

{
  char cVar1;
  char local_9;
  
  local_9 = '\x01';
  if ((param_3 & 0x10) != 0) {
    *(undefined1 *)(param_1 + 0xb8) = 0;
    *(undefined1 *)(param_1 + 0xbc) = 1;
  }
  switch((ushort)((int)(uint)param_3 >> 2) & 3) {
  case 0:
    cVar1 = *(char *)(param_1 + 0xb6);
    *(undefined1 *)(param_1 + 0xb6) = 0;
    if (((param_3 & 0x80) != 0) || (cVar1 != '\0')) {
      local_9 = FUN_600b842c(param_1,0xff);
    }
    break;
  case 1:
    *(undefined1 *)(param_1 + 0xb6) = 0;
    local_9 = FUN_600b842c(param_1,0xff);
    break;
  case 2:
    *(undefined1 *)(param_1 + 0xb6) = 1;
    FUN_600f82c4(param_1);
    break;
  case 3:
    *(undefined1 *)(param_1 + 0xb6) = 0;
    local_9 = FUN_600b842c(param_1,param_3 >> 8 & 0x3f);
  }
  if ((local_9 != '\0') && (*(char *)(param_1 + 0xbc) != '\0')) {
    if (*(char *)(param_1 + 0xb9) == '\0') {
      if (*(char *)(param_1 + 0xb7) == '\0') {
        FUN_600b7674(param_1,0,0x80);
      }
      else {
        FUN_600b7674(param_1,2,0x80);
      }
    }
    else {
      FUN_600b7674(param_1,3,0x80);
    }
    *(undefined1 *)(param_1 + 0xbc) = 0;
  }
  FUN_6006ddd8(param_2,DAT_600b7db4,0x439);
  return;
}


