// 600f09d4  FUN_600f09d4  size=126 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600f09d4(char *param_1,short param_2,code *param_3)

{
  char local_20;
  undefined1 local_1f;
  short local_1e;
  undefined1 auStack_1c [16];
  undefined1 *local_c;
  
  local_c = auStack_1c;
  thunk_EXT_FUN_0000b5ba(&local_20,0,0x14);
  if ((param_3 != (code *)0x0) && (param_1 != (char *)0x0)) {
    local_20 = *param_1;
    if (local_20 == '\0') {
      if (param_2 == 0x2018) {
        local_1f = 8;
      }
      else {
        local_1f = 0x10;
      }
      local_1e = param_2;
      thunk_EXT_FUN_0000b572(local_c,param_1 + 1,local_1f);
    }
    if (param_3 != (code *)0x0) {
      (*param_3)(&local_20);
    }
  }
  return;
}


