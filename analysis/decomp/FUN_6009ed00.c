// 6009ed00  FUN_6009ed00  size=154 bytes
// --- callers ---
//   6009b368 FUN_6009b368
//   600a730c FUN_600a730c
//   600f0e6e FUN_600f0e6e
// --- callees ---
//   6009dc14 FUN_6009dc14
//   6009ec14 FUN_6009ec14
//   6009c71c FUN_6009c71c
//   6009c778 FUN_6009c778
//   6009c7fc FUN_6009c7fc


void FUN_6009ed00(undefined4 param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  undefined1 local_9;
  
  local_9 = '\0';
  if (param_3 == '<') {
    *(undefined1 *)(DAT_6009ed9c + 0x8e6) = 0;
    *(undefined1 *)(DAT_6009ed9c + 0x8ee) = 0;
    FUN_6009ec14(0x231);
  }
  if (*(int *)(DAT_6009eda0 + 0xd4) != 0) {
    local_9 = (**(code **)(DAT_6009eda0 + 0xd4))(0x14,0);
  }
  if ((local_9 == '\0') && (*(short *)(DAT_6009ed9c + 0x8d6) == 0x100)) {
    FUN_6009dc14(*(ushort *)(DAT_6009ed9c + 0x8d6) | *(ushort *)(DAT_6009ed9c + 0xb12));
  }
  iVar1 = FUN_6009c778();
  if (((iVar1 == 0) && (param_3 != '\r')) && (iVar1 = FUN_6009c7fc(), iVar1 == 0)) {
    FUN_6009c71c();
  }
  return;
}


