// 600c556e  FUN_600c556e  size=2 bytes
// --- callers ---
// --- callees ---


void FUN_600c556e(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined1 param_4)

{
  int iVar1;
  byte bStack_11;
  code *pcStack_10;
  undefined1 uStack_9;
  
  uStack_9 = 0;
  pcStack_10 = (code *)0x0;
  bStack_11 = 0;
  while ((bStack_11 < *(byte *)(iRam600c5668 + 0xe4) &&
         ((iVar1 = FUN_600efcfe((uint)bStack_11 * 0x20 + iRam600c5668 + 4,2), iVar1 != 0 ||
          (*(char *)((uint)bStack_11 * 0x20 + iRam600c5668 + 0xc) != '\x01'))))) {
    bStack_11 = bStack_11 + 1;
  }
  if ((bStack_11 < *(byte *)(iRam600c5668 + 0xe4)) &&
     (iVar1 = FUN_600d9250((uint)bStack_11 * 0x20 + iRam600c5668 + 0x10), iVar1 != 0)) {
    pcStack_10 = *(code **)(iVar1 + 4);
    FUN_6006ddd8(iVar1,uRam600c566c,0x13e0);
  }
  switch(param_4) {
  case 0:
    break;
  default:
    uStack_9 = 1;
    break;
  case 2:
    uStack_9 = 3;
    break;
  case 3:
    uStack_9 = 4;
    break;
  case 6:
    uStack_9 = 5;
  }
  if (pcStack_10 != (code *)0x0) {
    (*pcStack_10)(2,param_2,uStack_9);
  }
  return;
}


