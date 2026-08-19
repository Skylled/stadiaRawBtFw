// 600deaea  FUN_600deaea  size=80 bytes
// --- callers ---
// --- callees ---
//   600da48a FUN_600da48a
//   6007f510 FUN_6007f510
//   6013d3c8 thunk_EXT_FUN_00001680
//   6007f454 receiver__6007f454


void FUN_600deaea(void)

{
  int local_20;
  undefined1 auStack_1c [4];
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  FUN_6007f510(&local_20);
  if (local_20 != 0) {
    *(undefined4 *)(local_20 + 0x9a0) = 0;
    local_18 = 0;
    uStack_14 = 0;
    local_10 = 0;
    uStack_c = 0;
    FUN_600da48a(local_20 + 0x9a4,&uStack_14);
    *(undefined4 *)(local_20 + 0x9a8) = local_10;
    FUN_600da48a(local_20 + 0x9ac,&uStack_c);
    thunk_EXT_FUN_00001680(&uStack_c);
    thunk_EXT_FUN_00001680(&uStack_14);
  }
  receiver__6007f454();
  thunk_EXT_FUN_00001680(auStack_1c);
  return;
}


