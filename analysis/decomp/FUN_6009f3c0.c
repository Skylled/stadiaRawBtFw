// 6009f3c0  FUN_6009f3c0  size=96 bytes
// --- callers ---
//   6009fa34 FUN_6009fa34
//   600986e0 FUN_600986e0
// --- callees ---
//   600a1394 FUN_600a1394
//   600b1b20 FUN_600b1b20


undefined1 FUN_6009f3c0(void)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined1 local_9;
  
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_9 = 3;
  if ((*(byte *)(DAT_6009f420 + 0x831) & 0x40) == 0) {
    local_10 = (int)&local_24 + 1;
                    /* WARNING: Ignoring partial resolution of indirect */
    local_24._0_1_ = 4;
    local_9 = FUN_600a1394(0xfce9,1,&local_24,DAT_6009f424);
  }
  else {
    iVar1 = FUN_600b1b20();
    if (iVar1 != 0) {
      local_9 = 0;
    }
  }
  return local_9;
}


