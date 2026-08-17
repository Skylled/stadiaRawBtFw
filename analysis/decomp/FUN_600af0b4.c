// 600af0b4  FUN_600af0b4  size=182 bytes
// --- callers ---
//   600f6516 FUN_600f6516
// --- callees ---
//   600af074 FUN_600af074
//   600f6158 FUN_600f6158
//   600f6b96 FUN_600f6b96
//   600aa3cc FUN_600aa3cc


void FUN_600af0b4(int param_1,undefined1 param_2)

{
  ushort local_1c;
  undefined2 local_1a;
  undefined4 local_18;
  char local_11;
  int local_10;
  byte local_9;
  
  local_1c = *(ushort *)(param_1 + 100);
  local_10 = DAT_600af16c;
  FUN_600aa3cc(param_1 + 0x74);
  if (local_1c != 0) {
    *(undefined2 *)(param_1 + 100) = 0;
    local_11 = FUN_600af074(param_1,local_1c);
    if (local_11 != '\0') {
      for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
        if (((*(char *)(local_10 + 0x25) != '\0') && (*(ushort *)(local_10 + 0x20) <= local_1c)) &&
           (local_1c <= *(ushort *)(local_10 + 0x22))) {
          local_18 = FUN_600f6158(param_1,param_2,local_1c);
          local_1a = CONCAT11(*(undefined1 *)(param_1 + 0xfb),*(undefined1 *)(local_10 + 0x24));
          FUN_600f6b96(local_1a,local_18,5,&local_1c);
        }
        local_10 = local_10 + 0x28;
      }
    }
  }
  return;
}


