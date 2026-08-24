// 600eef06  FUN_600eef06  size=244 bytes
// --- callers ---
//   600ef6ec FUN_600ef6ec
//   600fe66a FUN_600fe66a
//   600fe500 FUN_600fe500
//   600feba8 FUN_600feba8
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600ef4ae FUN_600ef4ae
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 FUN_600eef06(int param_1,short param_2,undefined4 param_3,int param_4,int param_5)

{
  int local_14;
  int local_10;
  int local_c;
  
  local_c = *(int *)(param_1 + 0xc);
  local_14 = 0;
  thunk_EXT_FUN_0000b5ba(param_3,0,0x1c);
  thunk_EXT_FUN_0000b5ba(param_4,0,0x18);
  thunk_EXT_FUN_0000b5ba(param_5,0,0x18);
  while( true ) {
    if (local_c == 0) {
      return 0;
    }
    if (param_2 == *(short *)(local_c + 0x24)) break;
    for (local_10 = *(int *)(local_c + 0x1c); local_10 != 0; local_10 = *(int *)(local_10 + 4)) {
      if (*(char *)(local_10 + 0xe) == '\x01') {
        local_14 = local_10;
      }
      if (param_2 == *(short *)(local_10 + 10)) {
        thunk_EXT_FUN_0000b572(param_3,local_c,0x1c);
        if (*(char *)(local_10 + 0xe) == '\x02') {
          FUN_600ef4ae(local_10,param_5);
          *(undefined1 *)(param_5 + 0x14) = *(undefined1 *)(local_10 + 0xc);
          if (local_14 != 0) {
            FUN_600ef4ae(local_14,param_4);
            *(undefined1 *)(param_4 + 0x14) = *(undefined1 *)(local_14 + 0xc);
          }
        }
        else {
          FUN_600ef4ae(local_10,param_4);
          *(undefined1 *)(param_4 + 0x14) = *(undefined1 *)(local_10 + 0xc);
        }
        return 1;
      }
    }
    local_c = *(int *)(local_c + 0x28);
  }
  thunk_EXT_FUN_0000b572(param_3,local_c,0x1c);
  return 1;
}


