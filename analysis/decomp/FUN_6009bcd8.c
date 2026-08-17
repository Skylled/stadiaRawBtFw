// 6009bcd8  FUN_6009bcd8  size=144 bytes
// --- callers ---
//   6009bd70 FUN_6009bd70
// --- callees ---
//   6009bc88 FUN_6009bc88
//   6009bc34 FUN_6009bc34
//   600fbc02 FUN_600fbc02


undefined4 FUN_6009bcd8(ushort param_1)

{
  undefined4 uVar1;
  undefined1 auStack_28 [20];
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  int local_10;
  int local_c;
  
  local_c = DAT_6009bd68;
  local_14 = *(undefined1 *)(DAT_6009bd68 + 9);
  local_13 = *(undefined1 *)(DAT_6009bd68 + 8);
  local_12 = *(undefined1 *)(DAT_6009bd68 + 7);
  if (param_1 < 8) {
    local_10 = DAT_6009bd6c + (uint)param_1 * 0xfc + 0x12c8;
    if (((*(byte *)(local_10 + 0xe4) & 2) == 0) || ((*(byte *)(local_10 + 0x7b) & 2) == 0)) {
      uVar1 = 0;
    }
    else {
      FUN_600fbc02(local_10 + 0x7c,0x10,&local_14,3,auStack_28);
      uVar1 = FUN_6009bc88(auStack_28);
    }
  }
  else {
    FUN_6009bc34();
    uVar1 = 1;
  }
  return uVar1;
}


