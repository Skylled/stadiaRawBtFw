// 6007ec48  receiver__6007ec48  size=134 bytes
// src: receiver.cc
// --- callers ---
// --- callees ---
//   6007efc0 FUN_6007efc0
//   600d37ac FUN_600d37ac
//   6007f510 FUN_6007f510
//   6013d3c8 thunk_EXT_FUN_00001680
//   600debb4 FUN_600debb4
//   600d53ae FUN_600d53ae


/* src: receiver.cc */

void receiver__6007ec48(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 *local_98;
  undefined4 local_94;
  int iStack_90;
  undefined1 local_8c;
  undefined1 local_8b;
  undefined1 local_8a [114];
  undefined4 uStack_18;
  undefined4 uStack_14;
  int local_10;
  uint uStack_c;
  
  uStack_c = *(uint *)(DAT_6007ec5c + 4) & 0x1ff;
  if (uStack_c != 0) {
    iStack_90 = *DAT_6007f198;
    if (iStack_90 == 0) {
      local_a0 = DAT_6007f19c;
      local_8c = 0;
      local_9c = 0x6f;
      local_98 = local_8a;
      local_8b = 0;
      local_8a[0] = 0;
      local_94 = 0x80;
      FUN_600d37ac(&local_98,DAT_6007f1a0);
      FUN_600d53ae(&local_a0);
    }
    else {
      local_a0 = CONCAT31(local_a0._1_3_,2);
      FUN_6007efc0(*(undefined4 *)(iStack_90 + 0xb0),&local_a0);
    }
    return;
  }
  uStack_18 = param_1;
  uStack_14 = param_2;
  local_10 = param_3;
  FUN_6007f510(&local_10);
  if (local_10 != 0) {
    uStack_14 = CONCAT13(2,(undefined3)uStack_14);
    FUN_600debb4(local_10,(int)&uStack_14 + 3);
  }
  thunk_EXT_FUN_00001680(&uStack_c);
  return;
}


