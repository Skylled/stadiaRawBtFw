// 600c5574  FUN_600c5574  size=214 bytes
// --- callers ---
// --- callees ---
//   600efcfe FUN_600efcfe
//   6006ddd8 FUN_6006ddd8
//   600d9250 FUN_600d9250


void FUN_600c5574(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined1 param_4)

{
  int iVar1;
  byte local_11;
  code *local_10;
  undefined1 local_9;
  
  local_9 = 0;
  local_10 = (code *)0x0;
  local_11 = 0;
  while ((local_11 < *(byte *)(DAT_600c5668 + 0xe4) &&
         ((iVar1 = FUN_600efcfe((uint)local_11 * 0x20 + DAT_600c5668 + 4,param_1), iVar1 != 0 ||
          (*(char *)((uint)local_11 * 0x20 + DAT_600c5668 + 0xc) != '\x01'))))) {
    local_11 = local_11 + 1;
  }
  if ((local_11 < *(byte *)(DAT_600c5668 + 0xe4)) &&
     (iVar1 = FUN_600d9250((uint)local_11 * 0x20 + DAT_600c5668 + 0x10), iVar1 != 0)) {
    local_10 = *(code **)(iVar1 + 4);
    FUN_6006ddd8(iVar1,DAT_600c566c,0x13e0);
  }
  switch(param_4) {
  case 0:
    break;
  default:
    local_9 = 1;
    break;
  case 2:
    local_9 = 3;
    break;
  case 3:
    local_9 = 4;
    break;
  case 6:
    local_9 = 5;
  }
  if (local_10 != (code *)0x0) {
    (*local_10)(param_1,param_2,local_9);
  }
  return;
}


