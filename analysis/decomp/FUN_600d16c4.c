// 600d16c4  FUN_600d16c4  size=102 bytes
// --- callers ---
//   60060ccc usb_device__60060ccc
// --- callees ---
//   60055860 FUN_60055860


bool FUN_600d16c4(int param_1,undefined4 param_2,byte *param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_60055860();
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)((param_1 + -2) * 0x60 + 0x400d81b4) = 0x180000;
    puVar1[0xc] = puVar1[0xc] | 0x4000;
    puVar1[0xc] = puVar1[0xc] | 0x8000;
    *puVar1 = 0;
    puVar1[4] = (param_3[1] & 0xf) << 0x10 | (param_3[2] & 0xf) << 8 | *param_3 & 0xf |
                puVar1[4] & 0xfff0f0f0;
  }
  return puVar1 == (undefined4 *)0x0;
}


