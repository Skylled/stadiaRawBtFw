// 600c40b0  FUN_600c40b0  size=268 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600efcc6 FUN_600efcc6
//   600a21e4 FUN_600a21e4


void FUN_600c40b0(int param_1,undefined4 param_2)

{
  undefined1 auStack_124 [6];
  undefined1 auStack_11e [3];
  char local_11b;
  byte local_11a;
  undefined1 local_119;
  undefined4 local_118;
  undefined1 local_114;
  undefined1 local_113;
  undefined1 local_111;
  int local_10;
  ushort local_a;
  
  FUN_600efcc6(auStack_124,param_1 + 2,param_1 + 2,auStack_124,param_2);
  thunk_EXT_FUN_0000b572(auStack_11e,param_1 + 8,3);
  local_a = (ushort)*(byte *)(param_1 + 8) * 0x100 + (*(byte *)(param_1 + 9) & 0xe0);
  local_11a = (byte)((int)(uint)local_a >> 5) & 1;
  local_119 = *(undefined1 *)(param_1 + 0xe);
  local_113 = *(undefined1 *)(param_1 + 0x11);
  local_114 = *(undefined1 *)(param_1 + 0x10);
  local_111 = *(undefined1 *)(param_1 + 0xf);
  local_118 = param_2;
  local_10 = FUN_600a21e4(param_1 + 2);
  if (local_10 != 0) {
    local_11b = '\x01';
  }
  if (*DAT_600c41bc != 0) {
    (*(code *)*DAT_600c41bc)(0,auStack_124);
  }
  if ((local_10 != 0) && (local_11b != '\0')) {
    *(undefined1 *)(local_10 + 0x14) = 1;
  }
  return;
}


