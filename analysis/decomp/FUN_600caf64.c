// 600caf64  FUN_600caf64  size=98 bytes
// --- callers ---
//   6006bc3c FUN_6006bc3c
// --- callees ---
//   600cae68 FUN_600cae68


undefined4
FUN_600caf64(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  char *pcVar1;
  bool bVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  pcVar3 = DAT_600cafc8;
  if (*DAT_600cafc8 == '\0') {
    FUN_600cae68();
  }
  if (param_1 < *(uint *)(pcVar3 + 0x10)) {
    uVar4 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar4 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(0x20);
    }
    if (param_1 != 0) {
      *(undefined4 *)(pcVar3 + param_1 * 0x18 + 0x18) = param_2;
      *(undefined4 *)(pcVar3 + param_1 * 0x18 + 0x20) = param_4;
      *(undefined4 *)(pcVar3 + param_1 * 0x18 + 0x1c) = param_3;
      pcVar1 = pcVar3 + param_1 * 0x18 + 0x28;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      pcVar1 = pcVar3 + param_1 * 0x18 + 0x24;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
    }
    *(undefined4 *)(pcVar3 + param_1 * 0x18 + 0x2c) = param_5;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar4);
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}


