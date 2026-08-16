// 6009c7fc  FUN_6009c7fc  size=64 bytes
// --- callers ---
//   6009ed00 FUN_6009ed00
// --- callees ---
//   600b59ec FUN_600b59ec
//   6006ddd8 FUN_6006ddd8
//   600d9250 FUN_600d9250


undefined1 FUN_6009c7fc(void)

{
  undefined4 *puVar1;
  undefined1 local_9;
  
  local_9 = 0;
  if (*(short *)(DAT_6009c83c + 0xa2c) != 0) {
    puVar1 = (undefined4 *)FUN_600d9250(DAT_6009c840);
    local_9 = FUN_600b59ec(*puVar1);
    FUN_6006ddd8(puVar1,DAT_6009c844,0x30b);
  }
  return local_9;
}


