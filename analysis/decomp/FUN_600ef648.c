// 600ef648  FUN_600ef648  size=164 bytes
// --- callers ---
//   600c67ac FUN_600c67ac
// --- callees ---
//   60094f58 FUN_60094f58
//   600f3e00 FUN_600f3e00
//   600efcfe FUN_600efcfe
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600ef648(undefined2 param_1)

{
  int iVar1;
  undefined1 uStack_1a;
  undefined1 local_19;
  undefined1 auStack_18 [8];
  int local_10;
  byte local_9;
  
  iVar1 = FUN_600f3e00(param_1,&local_19,auStack_18,&uStack_1a);
  if (iVar1 != 0) {
    local_10 = FUN_60094f58(local_19);
    if (local_10 != 0) {
      for (local_9 = 0; local_9 < 4; local_9 = local_9 + 1) {
        if ((*(char *)((uint)local_9 * 0x3c + local_10 + 0x1c) != '\0') &&
           (iVar1 = FUN_600efcfe((uint)local_9 * 0x3c + local_10 + 0x1d,auStack_18), iVar1 == 0)) {
          thunk_EXT_FUN_0000b5ba((uint)local_9 * 0x3c + local_10 + 0x1c,0,0x3c);
        }
      }
    }
  }
  return;
}


