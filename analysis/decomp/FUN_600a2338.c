// 600a2338  FUN_600a2338  size=362 bytes
// --- callers ---
//   600a00bc FUN_600a00bc
// --- callees ---
//   600a2578 FUN_600a2578
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600a25f8 FUN_600a25f8
//   600aa3cc FUN_600aa3cc


void FUN_600a2338(void)

{
  undefined1 local_116;
  undefined1 local_115;
  undefined2 local_114;
  undefined1 auStack_112 [261];
  char local_d;
  int *local_c;
  
  local_c = DAT_600a24a4;
  FUN_600aa3cc(DAT_600a24a4 + 0x12);
  if (*(char *)((int)local_c + 0x61e) != '\0') {
    local_d = *(char *)((int)local_c + 0x61e);
    *(undefined1 *)((int)local_c + 0x61e) = 0;
    if (((local_d == '\x02') || (local_d == '\x01')) && (local_c[0xd] != 0)) {
      local_115 = 0;
      (*(code *)local_c[0xd])(&local_115);
    }
  }
  if (*(char *)((int)local_c + 0x32) != '\0') {
    FUN_600aa3cc(local_c + 1);
    *(undefined1 *)((int)local_c + 0x32) = 0;
    thunk_EXT_FUN_0000b5ba(local_c + 0xb,0,6);
    thunk_EXT_FUN_0000b572(auStack_112,local_c + 0xb,6);
    if (*local_c != 0) {
      local_114 = 0xc;
      (*(code *)*local_c)(&local_114);
      *local_c = 0;
    }
  }
  if ((*(char *)((int)local_c + 0x61a) != '\0') &&
     (*(undefined1 *)((int)local_c + 0x61a) = 0, local_c[0xf] != 0)) {
    local_116 = 0xc;
    (*(code *)local_c[0xf])(&local_116);
  }
  *(undefined1 *)((int)local_c + 0x61d) = 0;
  *(undefined1 *)((int)local_c + 0x61b) = 0;
  local_c[0xe] = 0;
  FUN_600a2578(0);
  FUN_600a25f8();
  *(undefined2 *)(local_c + 7) = 0;
  *(undefined2 *)((int)local_c + 0x1e) = 0;
  *(undefined2 *)((int)local_c + 0x2a) = 0;
  *(undefined2 *)(local_c + 10) = 0;
  *(short *)(local_c + 7) = (short)local_c[7];
  *(undefined2 *)((int)local_c + 0x1e) = *(undefined2 *)((int)local_c + 0x1e);
  return;
}


