// 6009f2ec  FUN_6009f2ec  size=204 bytes
// --- callers ---
//   6009f8c8 FUN_6009f8c8
// --- callees ---
//   600a1394 FUN_600a1394
//   600b1a8c FUN_600b1a8c
//   6009ee18 FUN_6009ee18


char FUN_6009f2ec(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  char local_15;
  undefined1 *local_14;
  
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_15 = '\x03';
  if (*(char *)(DAT_6009f3b8 + 0xa6b) == '\0') {
    local_15 = '\x06';
  }
  else {
    if ((*(byte *)(DAT_6009f3b8 + 0x831) & 0x40) == 0) {
                    /* WARNING: Ignoring partial resolution of indirect */
      local_2c._0_1_ = 3;
      local_14 = (undefined1 *)((int)&local_2c + 2);
                    /* WARNING: Ignoring partial resolution of indirect */
      local_2c._1_1_ = *(undefined1 *)(param_1 + 0x6b);
      for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
        puVar1 = local_14 + 1;
        *local_14 = *(undefined1 *)((param_1 - iVar2) + 0x71);
        local_14 = puVar1;
      }
      local_15 = FUN_600a1394(0xfce9,8,&local_2c,DAT_6009f3bc);
    }
    else {
      iVar2 = FUN_600b1a8c(*(undefined1 *)(param_1 + 0x6b),param_1 + 0x6c);
      if (iVar2 != 0) {
        local_15 = '\x01';
      }
    }
    if (local_15 == '\x01') {
      FUN_6009ee18(param_1 + 0x10,3);
    }
  }
  return local_15;
}


