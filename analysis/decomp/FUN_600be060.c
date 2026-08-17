// 600be060  FUN_600be060  size=154 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600aa340 FUN_600aa340
//   600f7912 FUN_600f7912
//   600bf2d8 FUN_600bf2d8


void FUN_600be060(undefined2 param_1,short *param_2)

{
  undefined1 auStack_54 [36];
  undefined1 local_30;
  undefined1 *local_c;
  
  local_c = (undefined1 *)FUN_600bf2d8(param_1);
  if (local_c != (undefined1 *)0x0) {
    if (*param_2 == 0) {
      local_c[1] = local_c[1] | 4;
      if (((local_c[1] & 2) != 0) && (*local_c = 3, (local_c[1] & 1) == 0)) {
        FUN_600aa340(local_c + 8,5,0x1e);
      }
    }
    else if ((char)param_2[0x12] != '\0') {
      thunk_EXT_FUN_0000b572(auStack_54,DAT_600be0fc,0x48);
      local_30 = 0;
      FUN_600f7912(param_1,auStack_54);
    }
  }
  return;
}


