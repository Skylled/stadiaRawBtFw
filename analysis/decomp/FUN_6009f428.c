// 6009f428  FUN_6009f428  size=178 bytes
// --- callers ---
//   6009be40 FUN_6009be40
// --- callees ---
//   600a1394 FUN_600a1394
//   600b1be8 FUN_600b1be8
//   6009ee18 FUN_6009ee18


char FUN_6009f428(int param_1)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  char local_9;
  
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_9 = '\x03';
  if ((*(byte *)(param_1 + 0x72) & 2) == 0) {
    local_9 = '\x06';
  }
  else {
    if ((*(byte *)(DAT_6009f4dc + 0x831) & 0x40) == 0) {
                    /* WARNING: Ignoring partial resolution of indirect */
      local_24._0_1_ = 0xd;
      local_10 = (int)&local_24 + 2;
                    /* WARNING: Ignoring partial resolution of indirect */
      local_24._1_1_ = *(undefined1 *)(param_1 + 0x73);
      local_9 = FUN_600a1394(0xfce9,2,&local_24,DAT_6009f4e0);
    }
    else {
      iVar1 = FUN_600b1be8(*(undefined1 *)(param_1 + 0x6b),param_1 + 0x6c);
      if (iVar1 != 0) {
        local_9 = '\x01';
      }
    }
    if (local_9 == '\x01') {
      FUN_6009ee18(param_1 + 0x10,0xd);
    }
  }
  return local_9;
}


