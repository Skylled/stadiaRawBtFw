// 600c611c  FUN_600c611c  size=498 bytes
// --- callers ---
//   60094dc4 FUN_60094dc4
// --- callees ---
//   600ab9b8 FUN_600ab9b8
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600962dc FUN_600962dc
//   600ab8d4 FUN_600ab8d4
//   600c60cc FUN_600c60cc
//   6006dbac FUN_6006dbac
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600c611c(char *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  undefined1 local_2cc;
  char local_2cb;
  undefined2 *local_1c;
  int local_18;
  byte local_11;
  
  local_18 = param_2 + 8;
  thunk_EXT_FUN_0000b5ba(&local_2cc,0,0x2b0);
  local_2cc = 0x80;
  if (*param_1 == '\0') {
    FUN_600c60cc(param_1);
  }
  local_11 = 0;
  do {
    if (3 < local_11) {
LAB_600c62ea:
      if (*(int *)(param_2 + 0x1c) != 0) {
        (**(code **)(param_2 + 0x1c))(0,&local_2cc);
      }
      return;
    }
    if (param_1[(uint)local_11 * 0x10c + 100] == '\0') {
      if (local_18 != 0) {
        uVar2 = (uint)local_11;
        cVar1 = FUN_600ab8d4(local_18,DAT_600c6310);
        param_1[uVar2 * 0x10c + 0x65] = cVar1;
        if (param_1[uVar2 * 0x10c + 0x65] != '\0') {
          param_1[(uint)local_11 * 0x10c + 100] = '\x01';
          *(undefined4 *)(param_1 + (uint)local_11 * 0x10c + 0x60) = *(undefined4 *)(param_2 + 0x1c)
          ;
          thunk_EXT_FUN_0000b572(param_1 + (uint)local_11 * 0x10c + 0x68,local_18,0x14);
          local_2cb = param_1[(uint)local_11 * 0x10c + 0x65];
          local_1c = (undefined2 *)FUN_6006dbac(10,DAT_600c6314,0xcb);
          if (local_1c == (undefined2 *)0x0) {
            FUN_600ab9b8(param_1[(uint)local_11 * 0x10c + 0x65]);
            local_2cc = 0x80;
            thunk_EXT_FUN_0000b5ba(param_1 + (uint)local_11 * 0x10c + 0x60,0,0x10c);
          }
          else {
            *local_1c = 0x1d16;
            *(char *)(local_1c + 4) = param_1[(uint)local_11 * 0x10c + 0x65];
            FUN_600962dc(local_1c);
            local_2cc = 0;
          }
          goto LAB_600c62ea;
        }
      }
      local_2cc = 0x85;
    }
    local_11 = local_11 + 1;
  } while( true );
}


