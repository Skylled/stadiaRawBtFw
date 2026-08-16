// 600961e0  FUN_600961e0  size=84 bytes
// --- callers ---
//   600a9fce FUN_600a9fce
// --- callees ---
//   6006ddd8 FUN_6006ddd8


void FUN_600961e0(undefined2 *param_1)

{
  byte bVar1;
  undefined1 local_9;
  
  local_9 = '\x01';
  bVar1 = (byte)((ushort)*param_1 >> 8);
  if ((bVar1 < 0x32) && (*(int *)(DAT_60096234 + (uint)bVar1 * 4) != 0)) {
    local_9 = (*(code *)**(undefined4 **)(DAT_60096234 + (uint)bVar1 * 4))(param_1);
  }
  if (local_9 != '\0') {
    FUN_6006ddd8(param_1,DAT_60096238,0x253);
  }
  return;
}


