// 600814b8  FUN_600814b8  size=46 bytes
// --- callers ---
//   60081ab4 gatt_server__60081ab4
// --- callees ---
//   600d3b3a FUN_600d3b3a
//   600d37ac FUN_600d37ac
//   60101740 FUN_60101740


undefined4 FUN_600814b8(char *param_1)

{
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 auStack_98 [148];
  
  if (*param_1 == '\0') {
    local_a0 = DAT_600814e8;
    local_9c = 0x132;
    FUN_600d3b3a(auStack_98);
    FUN_600d37ac(auStack_98,DAT_600814ec);
    FUN_60101740(&local_a0);
  }
  return DAT_600814f0;
}


