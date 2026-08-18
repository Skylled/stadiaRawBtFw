// 600afc84  FUN_600afc84  size=158 bytes
// --- callers ---
//   600ab424 FUN_600ab424
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba


byte FUN_600afc84(int param_1)

{
  undefined2 uVar1;
  int *local_10;
  byte local_9;
  
  local_9 = 0;
  local_10 = DAT_600afd24;
  while( true ) {
    if (9 < local_9) {
      return local_9;
    }
    if (*(char *)((int)local_10 + 0x25) == '\0') break;
    local_9 = local_9 + 1;
    local_10 = local_10 + 10;
  }
  thunk_EXT_FUN_0000b5ba(local_10,0,0x28);
  *(undefined1 *)((int)local_10 + 0x25) = 1;
  thunk_EXT_FUN_0000b572(local_10 + 1,param_1 + 8,0x14);
  *(undefined2 *)(local_10 + 7) = *(undefined2 *)(param_1 + 0x30);
  if (*(char *)(param_1 + 0x36) == '\0') {
    uVar1 = 0x2801;
  }
  else {
    uVar1 = 0x2800;
  }
  *(undefined2 *)((int)local_10 + 0x1e) = uVar1;
  *(undefined2 *)(local_10 + 8) = *(undefined2 *)(param_1 + 0x32);
  *(undefined2 *)((int)local_10 + 0x22) = *(undefined2 *)(param_1 + 0x34);
  *local_10 = param_1 + 0x38;
  return local_9;
}


