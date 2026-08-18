// 600c447c  FUN_600c447c  size=236 bytes
// --- callers ---
// --- callees ---
//   600efcc6 FUN_600efcc6
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600c447c(short *param_1)

{
  ushort uVar1;
  undefined1 auStack_12c [6];
  undefined1 local_126;
  undefined1 local_125;
  undefined1 local_124;
  undefined1 local_123 [248];
  undefined1 local_2b;
  undefined4 local_28;
  undefined1 local_24;
  uint local_14;
  char local_d;
  short *local_c;
  
  local_d = 2;
  local_c = param_1;
  FUN_600efcc6(auStack_12c,DAT_600c4568);
  local_126 = *(undefined1 *)(DAT_600c456c + 0x27a);
  local_125 = *(undefined1 *)(DAT_600c456c + 0x27b);
  local_124 = *(undefined1 *)(DAT_600c456c + 0x27c);
  if ((local_c == (short *)0x0) || (*local_c != 0)) {
    local_123[0] = 0;
  }
  else {
    uVar1 = local_c[4];
    if (0xf7 < uVar1) {
      uVar1 = 0xf8;
    }
    local_14 = (uint)uVar1;
    thunk_EXT_FUN_0000b572(local_123,local_c + 5,local_14);
    local_2b = 0;
  }
  local_d = *(char *)(DAT_600c456c + 0x27d);
  local_28 = *(undefined4 *)(DAT_600c456c + 0x280);
  if (local_d == '\n') {
    local_24 = *(undefined1 *)(DAT_600c456c + 0x284);
  }
  if (*(int *)(DAT_600c456c + 0xe8) != 0) {
    (**(code **)(DAT_600c456c + 0xe8))(local_d,auStack_12c);
  }
  return;
}


