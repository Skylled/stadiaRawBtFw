// 600f3b78  FUN_600f3b78  size=102 bytes
// --- callers ---
//   600c67ac FUN_600c67ac
//   600feba8 FUN_600feba8
//   600fe496 FUN_600fe496
// --- callees ---
//   600ffada FUN_600ffada
//   600aa3cc FUN_600aa3cc
//   600af7c8 FUN_600af7c8


undefined1 FUN_600f3b78(undefined2 param_1,undefined2 param_2)

{
  undefined2 local_14;
  undefined2 local_12;
  int local_10;
  undefined1 local_9;
  
  local_9 = 0x87;
  local_14 = param_2;
  local_12 = param_1;
  local_10 = FUN_600af7c8((char)((ushort)param_1 >> 8));
  if (local_10 != 0) {
    if (*(char *)(local_10 + 0x96) == '\0') {
      local_9 = 0;
    }
    else {
      FUN_600aa3cc(local_10 + 0xe0);
      local_9 = FUN_600ffada(local_10,0,0x1e,&local_14);
      *(undefined1 *)(local_10 + 0x96) = 0;
    }
  }
  return local_9;
}


