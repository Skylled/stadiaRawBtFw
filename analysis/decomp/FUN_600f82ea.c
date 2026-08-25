// 600f82ea  FUN_600f82ea  size=64 bytes
// --- callers ---
//   600bcca8 FUN_600bcca8
//   600fa1dc FUN_600fa1dc
//   600b7db8 FUN_600b7db8
//   600b7800 FUN_600b7800
// --- callees ---


undefined4 FUN_600f82ea(int param_1)

{
  undefined4 uVar1;
  
  if ((*(char *)(param_1 + 0x7e) == '\x03') &&
     ((*(char *)(param_1 + 0xb6) == '\x01' ||
      ((ushort)*(byte *)(param_1 + 0x7f) <= *(ushort *)(param_1 + 0xcc))))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


