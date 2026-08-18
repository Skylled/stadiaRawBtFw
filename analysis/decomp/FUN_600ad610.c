// 600ad610  FUN_600ad610  size=224 bytes
// --- callers ---
//   600f31c6 FUN_600f31c6
// --- callees ---
//   600f75c0 FUN_600f75c0
//   600b507c FUN_600b507c
//   600abf08 FUN_600abf08
//   600f1996 FUN_600f1996
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600d9246 FUN_600d9246


void FUN_600ad610(void)

{
  undefined *local_24;
  undefined *local_20;
  undefined *local_1c;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  
  thunk_EXT_FUN_0000b5ba(DAT_600ad6f0,0,0x15b4);
  thunk_EXT_FUN_0000b5ba(&local_24,0,0x1c);
  *(undefined1 *)(DAT_600ad6f0 + 0x1498) = *DAT_600ad6f4;
  *(undefined2 *)(DAT_600ad6f0 + 0x149a) = 0x17;
  FUN_600d9246(DAT_600ad6f8);
  local_18 = 0;
  local_16 = 0xff;
  local_14 = 2000;
  local_12 = 12000;
  local_10 = 0x29e;
  local_17 = 1;
  local_24 = PTR_FUN_600f5bfc_1_600ad6fc;
  local_20 = PTR_FUN_600ad868_1_600ad700;
  local_1c = PTR_FUN_600f5ce2_1_600ad704;
  local_e = 0xffff;
  FUN_600b507c(4,&local_24);
  FUN_600f75c0(0x1f,PTR_DAT_600ad708);
  FUN_600f1996(1,PTR_LAB_600ad70c,0x28,0,0x1f,0,0);
  FUN_600f1996(0,PTR_LAB_600ad70c,0x28,0,0x1f,0,0);
  *(undefined2 *)(DAT_600ad6f0 + 0x155c) = 1;
  *(undefined2 *)(DAT_600ad6f0 + 0x155e) = 0x14;
  *(undefined2 *)(DAT_600ad6f0 + 0x1560) = 0x28;
  FUN_600abf08();
  return;
}


