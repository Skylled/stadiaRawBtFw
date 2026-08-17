// 600aad90  FUN_600aad90  size=156 bytes
// --- callers ---
//   600d8920 FUN_600d8920
//   6009c914 FUN_6009c914
// --- callees ---
//   600a10e0 FUN_600a10e0
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600aad90(ushort param_1,undefined4 *param_2)

{
  byte local_d;
  int local_c;
  
  local_c = DAT_600aae2c;
  local_d = 0;
  while( true ) {
    if (3 < local_d) {
      return;
    }
    if (param_1 == *(ushort *)(local_c + 2)) break;
    local_d = local_d + 1;
    local_c = local_c + 0xc;
  }
  if (param_1 == 0x2a01) {
    *(undefined2 *)(local_c + 4) = *(undefined2 *)param_2;
    return;
  }
  if (param_1 < 0x2a02) {
    if (param_1 != 0x2a00) {
      return;
    }
    FUN_600a10e0(*param_2);
    return;
  }
  if (param_1 == 0x2a04) {
    thunk_EXT_FUN_0000b572(local_c + 4,param_2,8);
    return;
  }
  if (param_1 != 0x2aa6) {
    return;
  }
  *(undefined1 *)(local_c + 4) = *(undefined1 *)param_2;
  return;
}


