// 600f23ec  FUN_600f23ec  size=278 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   6009a154 FUN_6009a154


void FUN_600f23ec(undefined1 *param_1)

{
  undefined1 local_24;
  undefined1 local_23;
  int local_20;
  int local_18;
  int local_14;
  int local_10;
  short local_c;
  undefined1 local_9;
  
  local_9 = *param_1;
  local_c = (ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1];
  local_24 = param_1[3];
  local_23 = param_1[4];
  local_20 = (uint)(byte)param_1[8] * 0x1000000 +
             (uint)(byte)param_1[5] + (uint)(byte)param_1[6] * 0x100 +
             (uint)(byte)param_1[7] * 0x10000;
  local_18 = (uint)(byte)param_1[0xc] * 0x1000000 +
             (uint)(byte)param_1[9] + (uint)(byte)param_1[10] * 0x100 +
             (uint)(byte)param_1[0xb] * 0x10000;
  local_14 = (uint)(byte)param_1[0x10] * 0x1000000 +
             (uint)(byte)param_1[0xd] + (uint)(byte)param_1[0xe] * 0x100 +
             (uint)(byte)param_1[0xf] * 0x10000;
  local_10 = (uint)(byte)param_1[0x14] * 0x1000000 +
             (uint)(byte)param_1[0x11] + (uint)(byte)param_1[0x12] * 0x100 +
             (uint)(byte)param_1[0x13] * 0x10000;
  FUN_6009a154(local_9,local_c,&local_24);
  return;
}


