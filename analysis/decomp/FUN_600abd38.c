// 600abd38  FUN_600abd38  size=104 bytes
// --- callers ---
//   600f3f70 FUN_600f3f70
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined1 FUN_600abd38(undefined4 param_1,short *param_2)

{
  undefined1 local_9;
  
  local_9 = 0x80;
  if (*(short *)(DAT_600abda0 + 0x1550) != *param_2) {
    if (*param_2 == *DAT_600abda4) {
      if (((ushort)param_2[2] < 3) && (param_2[2] != 0)) {
        thunk_EXT_FUN_0000b572(DAT_600abda8,param_2 + 3,param_2[2]);
        local_9 = 0;
      }
      else {
        local_9 = 0xd;
      }
    }
    else {
      local_9 = 10;
    }
  }
  return local_9;
}


