// 600b9358  FUN_600b9358  size=168 bytes
// --- callers ---
//   600a96d8 FUN_600a96d8
//   600f2a7a FUN_600f2a7a
// --- callees ---
//   600bc5c4 FUN_600bc5c4
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600bb6dc FUN_600bb6dc


void FUN_600b9358(int param_1,undefined1 param_2,char param_3)

{
  undefined1 auStack_1c [6];
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  int local_10;
  char *local_c;
  
  if (param_1 != 0) {
    local_c = (char *)FUN_600bb6dc(param_1,1);
    if (((local_c != (char *)0x0) && (*(undefined1 *)((int)local_c + 10) = param_2, param_3 == '\0')
        ) && (*(int *)(DAT_600b9400 + 0xd4) != 0)) {
      thunk_EXT_FUN_0000b572(auStack_1c,param_1,6);
      local_14 = *(undefined1 *)((int)local_c + 0x29);
      local_16 = *(undefined1 *)((int)local_c + 0x28);
      local_15 = 1;
      (**(code **)(DAT_600b9400 + 0xd4))(8,auStack_1c);
    }
  }
  local_c = DAT_600b9404;
  for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
    if ((*local_c != '\0') && (local_c[1] == '\x02')) {
      FUN_600bc5c4(local_c);
    }
    local_c = local_c + 0xa4;
  }
  return;
}


