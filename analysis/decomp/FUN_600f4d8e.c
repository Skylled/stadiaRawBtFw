// 600f4d8e  FUN_600f4d8e  size=250 bytes
// --- callers ---
//   600ad710 FUN_600ad710
//   600acf50 FUN_600acf50
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600ff986 FUN_600ff986
//   600f6a8a FUN_600f6a8a
//   600b001c FUN_600b001c
//   600b00b4 FUN_600b00b4


char FUN_600f4d8e(int param_1)

{
  undefined1 uStack_16;
  char local_15;
  undefined4 local_14;
  char local_d;
  int *local_c;
  
  local_c = (int *)((*(byte *)(param_1 + 0xf8) + 0x13) * 8 + param_1);
  local_14 = 0;
  local_15 = '\0';
  local_d = '\0';
  while ((((local_d == '\0' && (*(char *)(param_1 + 0xf8) != *(char *)(param_1 + 0xf9))) &&
          (*(char *)((int)local_c + 7) != '\0')) && (*local_c != 0))) {
    local_15 = FUN_600ff986(param_1,*local_c);
    if ((local_15 == '\0') || (local_15 == -0x71)) {
      local_d = '\x01';
      *(undefined1 *)((int)local_c + 7) = 0;
      *local_c = 0;
      if ((*(char *)((int)local_c + 6) == 'R') || (*(char *)((int)local_c + 6) == -0x2e)) {
        local_14 = FUN_600b001c(param_1,&uStack_16);
        if (local_15 == '\0') {
          local_d = '\0';
        }
        local_c = (int *)((*(byte *)(param_1 + 0xf8) + 0x13) * 8 + param_1);
        FUN_600b00b4(local_14,local_15,0);
      }
      else {
        FUN_600f6a8a(param_1);
      }
    }
    else {
      thunk_EXT_FUN_0000b5ba(local_c,0,8);
      *(char *)(param_1 + 0xf8) = *(char *)(param_1 + 0xf8) + '\x01';
      local_c = (int *)((*(byte *)(param_1 + 0xf8) + 0x13) * 8 + param_1);
    }
  }
  return local_d;
}


