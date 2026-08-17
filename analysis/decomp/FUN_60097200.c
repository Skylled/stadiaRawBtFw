// 60097200  FUN_60097200  size=142 bytes
// --- callers ---
//   6006c1f4 FUN_6006c1f4
// --- callees ---
//   600a1394 FUN_600a1394
//   6006eca4 FUN_6006eca4


bool FUN_60097200(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  bool bVar2;
  undefined4 local_18;
  undefined2 local_14;
  int local_10;
  undefined1 local_9;
  
  local_9 = 2;
  local_18 = 0;
  local_14 = 0;
  *(undefined1 *)(DAT_60097290 + 0x98) = param_1;
  local_10 = FUN_6006eca4(param_1);
  if (local_10 == 0) {
    bVar2 = false;
  }
  else {
    *(undefined4 *)(DAT_60097290 + 0x9c) = param_3;
    local_9 = 6;
    local_18 = CONCAT13((char)((uint)local_10 >> 8),CONCAT12((char)local_10,(undefined2)local_18));
    local_14 = (undefined2)((uint)local_10 >> 0x10);
    bVar1 = FUN_600a1394(0xfc18,6,&local_18,DAT_60097294);
    bVar2 = bVar1 < 2;
  }
  return bVar2;
}


