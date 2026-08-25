// 600f87b8  FUN_600f87b8  size=562 bytes
// --- callers ---
//   600f9df0 FUN_600f9df0
// --- callees ---
//   6006e0a4 FUN_6006e0a4


char FUN_600f87b8(int param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  undefined1 local_9;
  
  local_9 = '\x01';
  *(undefined1 *)(*(int *)(param_1 + 300) + 0xa3) = 0;
  if (*(char *)(param_2 + 0x26) == '\0') {
    if ((*(byte *)(param_1 + 0xa8) & 1) == 0) {
      local_9 = '\x02';
    }
  }
  else if (*(char *)(param_2 + 0x26) != *(char *)(param_1 + 0xa7)) {
    if (((0x19 >> *(sbyte *)(param_2 + 0x26) & 1U) == 0) || (*(char *)(param_1 + 0xa7) == '\x03')) {
      *(undefined1 *)(param_2 + 0x26) = *(undefined1 *)(param_1 + 0x32);
      *(undefined1 *)(param_2 + 0x27) = *(undefined1 *)(param_1 + 0x33);
      *(undefined1 *)(param_2 + 0x28) = *(undefined1 *)(param_1 + 0x34);
      local_9 = '\0';
    }
    else if (*(char *)(param_1 + 0xa7) == '\0') {
      *(undefined1 *)(param_2 + 0x26) = 0;
      *(undefined1 *)(param_2 + 0x27) = 0;
      *(undefined1 *)(param_2 + 0x28) = *(undefined1 *)(param_2 + 0x27);
      *(undefined2 *)(param_2 + 0x2e) = 0;
      *(undefined2 *)(param_2 + 0x2c) = *(undefined2 *)(param_2 + 0x2e);
      *(undefined2 *)(param_2 + 0x2a) = *(undefined2 *)(param_2 + 0x2c);
      *(undefined2 *)(param_1 + 0x3a) = 0;
      *(undefined2 *)(param_1 + 0x38) = *(undefined2 *)(param_1 + 0x3a);
      *(undefined2 *)(param_1 + 0x36) = *(undefined2 *)(param_1 + 0x38);
      local_9 = '\0';
    }
    else if ((*(char *)(param_2 + 0x26) != '\x03') || ((*(byte *)(param_1 + 0xa8) & 8) == 0)) {
      local_9 = '\x02';
    }
  }
  if (local_9 == '\x01') {
    *(undefined1 *)(param_1 + 0x11e) = 0;
    if ((*(char *)(param_2 + 0x24) != '\0') && (*(char *)(param_2 + 0x26) != '\0')) {
      if (*(char *)(param_2 + 0x30) != '\0') {
        *(undefined1 *)(param_1 + 0x89) = *(undefined1 *)(param_2 + 0x31);
        *(ushort *)(param_1 + 0x54) = *(ushort *)(param_1 + 0x54) | 0x10;
        if (*(char *)(param_2 + 0x31) == '\0') {
          *(byte *)(param_1 + 0x11f) = *(byte *)(param_1 + 0x11f) | 2;
        }
      }
      sVar1 = FUN_6006e0a4(*(undefined1 *)(param_1 + 0xac));
      if ((*(short *)(param_2 + 0x2e) == 0) ||
         (*(ushort *)(param_1 + 0x5c) < *(ushort *)(param_2 + 0x2e))) {
        *(undefined2 *)(param_2 + 0x2e) = *(undefined2 *)(param_1 + 0x5c);
        *(undefined1 *)(param_1 + 0x11e) = 1;
      }
      if ((ushort)(sVar1 - 0x19U) < *(ushort *)(param_2 + 0x2e)) {
        *(ushort *)(param_2 + 0x2e) = sVar1 - 0x19U;
        *(undefined1 *)(param_1 + 0x11e) = 1;
      }
      if ((*(char *)(param_2 + 0x26) == '\x03') || (*(char *)(param_2 + 0x26) == '\x04')) {
        *(undefined1 *)(param_1 + 0x11e) = 1;
      }
    }
    uVar2 = *(undefined4 *)(param_2 + 0x2a);
    *(undefined4 *)(param_1 + 0x7e) = *(undefined4 *)(param_2 + 0x26);
    *(undefined4 *)(param_1 + 0x82) = uVar2;
    *(undefined2 *)(param_1 + 0x86) = *(undefined2 *)(param_2 + 0x2e);
    if (*(char *)(param_2 + 0x24) != '\0') {
      *(ushort *)(param_1 + 0x54) = *(ushort *)(param_1 + 0x54) | 8;
    }
  }
  else if (local_9 == '\0') {
    if (*(char *)(param_1 + 0x11d) == '\0') {
      *(undefined1 *)(param_1 + 0x11d) = 1;
    }
    else {
      local_9 = '\x02';
    }
  }
  return local_9;
}


