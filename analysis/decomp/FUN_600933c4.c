// 600933c4  FUN_600933c4  size=44 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600933c4(ushort *param_1)

{
  if ((*param_1 & 0xff) < 0x35) {
    (**(code **)(DAT_600933f0 + (uint)(*param_1 & 0xff) * 4))(param_1);
  }
  return 1;
}


