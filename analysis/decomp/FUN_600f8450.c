// 600f8450  FUN_600f8450  size=344 bytes
// --- callers ---
//   600f7912 FUN_600f7912
// --- callees ---
//   600f83f2 FUN_600f83f2
//   600f9db4 FUN_600f9db4


undefined4 FUN_600f8450(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  pcVar3 = (char *)(param_2 + 0x26);
  if (*pcVar3 != *(char *)(param_1 + 0xa7)) {
    *pcVar3 = *(char *)(param_1 + 0xa7);
  }
  if (*(char *)(param_1 + 0xa8) == '\x01') {
    *pcVar3 = '\0';
  }
  if ((*(char *)(param_2 + 0x24) == '\0') || ((*(byte *)(param_1 + 6) & 4) != 0)) {
    *(undefined1 *)(param_1 + 0x30) = 0;
  }
  else {
    iVar1 = FUN_600f83f2(param_1);
    if (iVar1 == 0) {
      FUN_600f9db4(param_1);
      return 0;
    }
    if (*(char *)(param_1 + 0xa8) == '\x01') {
      *(undefined1 *)(param_2 + 0x24) = 0;
      *(undefined1 *)(param_2 + 0x30) = 0;
      *(undefined1 *)(param_2 + 0x32) = 0;
    }
    else {
      if ((*pcVar3 == '\x04') && ((*(byte *)(param_1 + 0xa8) & 0x10) == 0)) {
        *pcVar3 = '\x03';
      }
      if ((*pcVar3 == '\x03') && ((*(byte *)(param_1 + 0xa8) & 8) == 0)) {
        *pcVar3 = '\0';
      }
    }
    if (*pcVar3 == '\0') {
      *(undefined1 *)(param_2 + 0x30) = 0;
      *(undefined1 *)(param_2 + 0x32) = 0;
    }
    else {
      if ((*(char *)(param_2 + 2) != '\0') &&
         (*(ushort *)(param_1 + 0x11a) < *(ushort *)(param_2 + 4))) {
        return 0;
      }
      if (*(short *)(param_2 + 0x2e) == 0) {
        *(undefined2 *)(param_2 + 0x2e) = 0x3f2;
      }
      else if (*(ushort *)(param_1 + 0x11a) < *(ushort *)(param_2 + 0x2e)) {
        return 0;
      }
      if (0x23c < *(ushort *)(param_2 + 0x2e)) {
        *(undefined2 *)(param_2 + 0x2e) = 0x23c;
      }
    }
    uVar2 = *(undefined4 *)(param_2 + 0x2a);
    *(undefined4 *)(param_1 + 0x32) = *(undefined4 *)pcVar3;
    *(undefined4 *)(param_1 + 0x36) = uVar2;
    *(undefined2 *)(param_1 + 0x3a) = *(undefined2 *)(param_2 + 0x2e);
  }
  return 1;
}


