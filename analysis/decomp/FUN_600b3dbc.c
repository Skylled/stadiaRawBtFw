// 600b3dbc  FUN_600b3dbc  size=256 bytes
// --- callers ---
//   600ff694 FUN_600ff694
// --- callees ---
//   6006dbac FUN_6006dbac
//   600a9234 FUN_600a9234


bool FUN_600b3dbc(undefined1 param_1,undefined1 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x15,DAT_600b3ebc,0x9a4);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 0xd;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x6e;
    *(undefined1 *)(iVar1 + 9) = 0xc;
    *(undefined1 *)(iVar1 + 10) = 10;
    *(undefined1 *)(iVar1 + 0xb) = *param_2;
    *(char *)(iVar1 + 0xc) = (char)*(undefined2 *)(param_2 + 2);
    *(char *)(iVar1 + 0xd) = (char)((ushort)*(undefined2 *)(param_2 + 2) >> 8);
    *(char *)(iVar1 + 0xe) = (char)*(undefined2 *)(param_2 + 4);
    *(char *)(iVar1 + 0xf) = (char)((ushort)*(undefined2 *)(param_2 + 4) >> 8);
    *(char *)(iVar1 + 0x10) = (char)*(undefined2 *)(param_2 + 6);
    *(char *)(iVar1 + 0x11) = (char)((ushort)*(undefined2 *)(param_2 + 6) >> 8);
    *(char *)(iVar1 + 0x12) = (char)*(undefined2 *)(param_2 + 8);
    *(char *)(iVar1 + 0x13) = (char)((ushort)*(undefined2 *)(param_2 + 8) >> 8);
    *(undefined1 *)(iVar1 + 0x14) = param_2[10];
    FUN_600a9234(param_1,iVar1);
  }
  return iVar1 != 0;
}


