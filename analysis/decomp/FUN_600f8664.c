// 600f8664  FUN_600f8664  size=340 bytes
// --- callers ---
//   600b6900 FUN_600b6900
// --- callees ---
//   600bc2a0 FUN_600bc2a0
//   600aa340 FUN_600aa340
//   600f8f7a FUN_600f8f7a
//   600f9db4 FUN_600f9db4


undefined4 FUN_600f8664(int param_1,short *param_2)

{
  bool bVar1;
  char local_9;
  
  local_9 = *(char *)(param_1 + 0x32);
  if (((char)param_2[0x12] == '\0') || ((*(byte *)(param_1 + 6) & 4) != 0)) {
    return 0;
  }
  if (*param_2 != 1) goto LAB_600f879c;
  if ((char)param_2[0x12] == '\0') {
    local_9 = '\0';
  }
  else {
    local_9 = (char)param_2[0x13];
  }
  if (local_9 == *(char *)(param_1 + 0x32)) goto LAB_600f879c;
  *(char *)(param_1 + 0x11c) = *(char *)(param_1 + 0x11c) + -1;
  if (*(char *)(param_1 + 0x11c) == '\0') {
    *param_2 = 2;
  }
  bVar1 = false;
  if (*(char *)(param_1 + 0x32) == '\x03') {
LAB_600f8712:
    if ((*(byte *)(param_1 + 0xa8) & 1) != 0) {
      bVar1 = true;
      *(undefined1 *)(param_1 + 0x32) = 0;
    }
  }
  else if (*(char *)(param_1 + 0x32) == '\x04') {
    if ((local_9 != '\x03') || ((*(byte *)(param_1 + 0xa8) & 8) == 0)) goto LAB_600f8712;
    *(undefined1 *)(param_1 + 0x32) = 3;
    bVar1 = true;
  }
  if (bVar1) {
    *(undefined1 *)(param_1 + 0x30) = 1;
    if (*(char *)(param_1 + 0x32) == '\0') {
      *(undefined1 *)(param_1 + 0x3c) = 0;
      *(undefined1 *)(param_1 + 0x3e) = 0;
      if (((char)param_2[1] != '\0') && (0x248 < (ushort)param_2[2])) {
        param_2[2] = 0x248;
      }
    }
    FUN_600bc2a0(param_1,param_1 + 0xc);
    FUN_600f8f7a(param_1,param_1 + 0xc);
    FUN_600aa340(param_1 + 0x13c,3,0x1e);
    return 1;
  }
LAB_600f879c:
  if (local_9 != *(char *)(param_1 + 0x32)) {
    FUN_600f9db4(param_1);
  }
  return 0;
}


