// 600f8aea  FUN_600f8aea  size=190 bytes
// --- callers ---
//   600bb2ac FUN_600bb2ac
// --- callees ---
//   600b5e00 FUN_600b5e00
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600aa340 FUN_600aa340


void FUN_600f8aea(int param_1)

{
  undefined1 auStack_1c [6];
  undefined1 local_16;
  int local_c;
  
  if (*(char *)(param_1 + 0xa3) != '\0') {
    for (local_c = *(int *)(param_1 + 0x5c); local_c != 0; local_c = *(int *)(local_c + 0x124)) {
      if ((*(char *)(local_c + 4) == '\x01') || (*(char *)(local_c + 4) == '\x02')) {
        FUN_600aa340(param_1 + 0x68,0x2b,3);
        return;
      }
    }
    if (*(char *)(param_1 + 0x16) == '\0') {
      *(undefined1 *)(param_1 + 0xa3) = 0;
      if (((*(char *)(param_1 + 1) != '\0') && (*(char *)(param_1 + 1) != '\x05')) &&
         (*(int *)(param_1 + 0x5c) != 0)) {
        local_16 = 0;
        thunk_EXT_FUN_0000b572(auStack_1c,param_1 + 4,6);
        for (local_c = *(int *)(param_1 + 0x5c); local_c != 0; local_c = *(int *)(local_c + 0x124))
        {
          FUN_600b5e00(local_c,0x13,auStack_1c);
        }
      }
    }
    else {
      FUN_600aa340(param_1 + 0x68,0x2b,3);
    }
  }
  return;
}


