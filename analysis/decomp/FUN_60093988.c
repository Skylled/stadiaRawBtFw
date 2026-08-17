// 60093988  FUN_60093988  size=162 bytes
// --- callers ---
//   60093d20 FUN_60093d20
// --- callees ---
//   60096314 FUN_60096314


void FUN_60093988(int param_1,byte param_2,undefined4 param_3,undefined1 param_4,byte param_5,
                 undefined1 param_6)

{
  *(undefined1 *)(param_1 + 0x58) = 1;
  *(undefined4 *)((uint)param_2 * 0x18 + param_1 + 8) = DAT_60093a2c;
  if (*(char *)((uint)param_2 + param_1 + 0x48) == '2') {
    *(char *)(param_1 + 0x51) = *(char *)(param_1 + 0x51) + '\x01';
  }
  if (*(byte *)((uint)param_2 + param_1 + 0x4e) < param_5) {
    *(byte *)((uint)param_2 + param_1 + 0x4e) = param_5;
    *(undefined1 *)((uint)param_2 + param_1 + 0x48) = param_4;
    *(undefined1 *)((uint)param_2 + param_1 + 0x4b) = param_6;
  }
  FUN_60096314((uint)param_2 * 0x18 + param_1,0,param_3);
  return;
}


