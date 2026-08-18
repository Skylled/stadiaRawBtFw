// 600abf08  FUN_600abf08  size=254 bytes
// --- callers ---
//   600ad610 FUN_600ad610
// --- callees ---
//   600ab8d4 FUN_600ab8d4
//   600f35ae FUN_600f35ae
//   600ab424 FUN_600ab424
//   600abb14 FUN_600abb14
//   600f3620 FUN_600f3620
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600ab110 FUN_600ab110


void FUN_600abf08(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 local_34;
  undefined2 local_30;
  undefined2 uStack_2e;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_a;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_20 = 0x10;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_34 = 2;
  local_30 = 0x1801;
  uStack_2e = 0;
  local_a = 0;
  thunk_EXT_FUN_0000b5ba(&local_1c,0x81,0x10);
  uVar1 = FUN_600ab8d4(&local_20,DAT_600ac008);
  *(undefined1 *)(DAT_600ac00c + 0xc20) = uVar1;
  FUN_600abb14(*(undefined1 *)(DAT_600ac00c + 0xc20));
  local_a = FUN_600ab110(*(undefined1 *)(DAT_600ac00c + 0xc20),&local_34,0,5,1);
  *(undefined2 *)(DAT_600ac00c + 0xc1a) = 0x2a05;
  local_30 = *(undefined2 *)(DAT_600ac00c + 0xc1a);
  *(undefined4 *)(DAT_600ac00c + 0xc1c) = 0;
  uVar2 = FUN_600f35ae(local_a,&local_34,0,0x20);
  *(undefined2 *)(DAT_600ac00c + 0x1550) = uVar2;
  *(undefined2 *)(DAT_600ac00c + 0xc18) = *(undefined2 *)(DAT_600ac00c + 0x1550);
  _local_30 = CONCAT22(uStack_2e,0x2902);
  uVar2 = FUN_600f3620(local_a,0x11,&local_34);
  *DAT_600ac010 = uVar2;
  FUN_600ab424(*(undefined1 *)(DAT_600ac00c + 0xc20),local_a,2);
  return;
}


