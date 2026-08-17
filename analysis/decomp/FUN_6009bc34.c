// 6009bc34  FUN_6009bc34  size=76 bytes
// --- callers ---
//   6009bc88 FUN_6009bc88
//   6009bcd8 FUN_6009bcd8
// --- callees ---


void FUN_6009bc34(void)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = DAT_6009bc80;
  local_c = 0;
  if (*(ushort *)(DAT_6009bc80 + 0xe) < 8) {
    local_c = DAT_6009bc84 + (uint)*(ushort *)(DAT_6009bc80 + 0xe) * 0xfc + 0x12c8;
  }
  *(undefined1 *)(DAT_6009bc80 + 0xd) = 0;
  (**(code **)(iVar1 + 0x10))(local_c,*(undefined4 *)(iVar1 + 0x18));
  return;
}


