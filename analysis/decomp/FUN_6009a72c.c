// 6009a72c  FUN_6009a72c  size=132 bytes
// --- callers ---
//   600a730c FUN_600a730c
//   600a59d0 FUN_600a59d0
//   600a6d70 FUN_600a6d70
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600a9234 FUN_600a9234
//   600d9250 FUN_600d9250
//   600f1746 FUN_600f1746


void FUN_6009a72c(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 auStack_24 [5];
  undefined1 local_1f [3];
  int local_1c;
  int local_18;
  undefined1 *local_14;
  
  local_18 = FUN_600d9250(DAT_6009a7b0);
  if (local_18 == 0) {
    *(undefined1 *)(DAT_6009a7bc + 0x1acc) = 0;
  }
  else {
    puVar1 = local_1f;
    local_14 = (undefined1 *)((uint)*(ushort *)(local_18 + 4) + local_18 + 0xb);
    for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
      *puVar1 = *local_14;
      puVar1 = puVar1 + -1;
      local_14 = local_14 + 1;
    }
    local_1c = FUN_600f1746(auStack_24);
    thunk_EXT_FUN_0000b572(DAT_6009a7b4,local_1c + 0x10,6);
    thunk_EXT_FUN_0000b572(DAT_6009a7b8,local_1c + 0x16,3);
    FUN_600a9234(0,local_18);
  }
  return;
}


