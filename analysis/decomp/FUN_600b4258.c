// 600b4258  FUN_600b4258  size=240 bytes
// --- callers ---
//   600ff764 FUN_600ff764
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b4258(undefined1 param_1,undefined1 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x14,DAT_600b4348,0xa09);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 0xc;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x71;
    *(undefined1 *)(iVar1 + 9) = 0xc;
    *(undefined1 *)(iVar1 + 10) = 9;
    *(undefined1 *)(iVar1 + 0xb) = *param_2;
    *(char *)(iVar1 + 0xc) = (char)*(undefined4 *)(param_2 + 4);
    *(char *)(iVar1 + 0xd) = (char)((uint)*(undefined4 *)(param_2 + 4) >> 8);
    *(char *)(iVar1 + 0xe) = (char)((uint)*(undefined4 *)(param_2 + 4) >> 0x10);
    *(char *)(iVar1 + 0xf) = (char)((uint)*(undefined4 *)(param_2 + 4) >> 0x18);
    *(char *)(iVar1 + 0x10) = (char)*(undefined4 *)(param_2 + 8);
    *(char *)(iVar1 + 0x11) = (char)((uint)*(undefined4 *)(param_2 + 8) >> 8);
    *(char *)(iVar1 + 0x12) = (char)((uint)*(undefined4 *)(param_2 + 8) >> 0x10);
    *(char *)(iVar1 + 0x13) = (char)((uint)*(undefined4 *)(param_2 + 8) >> 0x18);
    FUN_600a9234(param_1,iVar1);
  }
  return iVar1 != 0;
}


