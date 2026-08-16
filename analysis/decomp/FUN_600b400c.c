// 600b400c  FUN_600b400c  size=584 bytes
// --- callers ---
//   600ff718 FUN_600ff718
// --- callees ---
//   600a9234 FUN_600a9234
//   6006dbac FUN_6006dbac


bool FUN_600b400c(undefined1 param_1,undefined2 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_6006dbac(0x29,DAT_600b4254,0x9e4);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 2) = 0x21;
    *(undefined2 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 8) = 0x70;
    *(undefined1 *)(iVar1 + 9) = 0xc;
    *(undefined1 *)(iVar1 + 10) = 0x1e;
    *(char *)(iVar1 + 0xb) = (char)*param_2;
    *(char *)(iVar1 + 0xc) = (char)((ushort)*param_2 >> 8);
    *(char *)(iVar1 + 0xd) = (char)param_2[1];
    *(char *)(iVar1 + 0xe) = (char)((ushort)param_2[1] >> 8);
    *(char *)(iVar1 + 0xf) = (char)param_2[2];
    *(char *)(iVar1 + 0x10) = (char)((ushort)param_2[2] >> 8);
    *(char *)(iVar1 + 0x11) = (char)param_2[3];
    *(char *)(iVar1 + 0x12) = (char)((ushort)param_2[3] >> 8);
    *(char *)(iVar1 + 0x13) = (char)param_2[4];
    *(char *)(iVar1 + 0x14) = (char)((ushort)param_2[4] >> 8);
    *(char *)(iVar1 + 0x15) = (char)param_2[5];
    *(char *)(iVar1 + 0x16) = (char)((ushort)param_2[5] >> 8);
    *(char *)(iVar1 + 0x17) = (char)param_2[6];
    *(char *)(iVar1 + 0x18) = (char)((ushort)param_2[6] >> 8);
    *(char *)(iVar1 + 0x19) = (char)param_2[7];
    *(char *)(iVar1 + 0x1a) = (char)((ushort)param_2[7] >> 8);
    *(char *)(iVar1 + 0x1b) = (char)param_2[8];
    *(char *)(iVar1 + 0x1c) = (char)((ushort)param_2[8] >> 8);
    *(char *)(iVar1 + 0x1d) = (char)param_2[9];
    *(char *)(iVar1 + 0x1e) = (char)((ushort)param_2[9] >> 8);
    *(char *)(iVar1 + 0x1f) = (char)param_2[10];
    *(char *)(iVar1 + 0x20) = (char)((ushort)param_2[10] >> 8);
    *(char *)(iVar1 + 0x21) = (char)param_2[0xb];
    *(char *)(iVar1 + 0x22) = (char)((ushort)param_2[0xb] >> 8);
    *(char *)(iVar1 + 0x23) = (char)param_2[0xc];
    *(char *)(iVar1 + 0x24) = (char)((ushort)param_2[0xc] >> 8);
    *(char *)(iVar1 + 0x25) = (char)param_2[0xd];
    *(char *)(iVar1 + 0x26) = (char)((ushort)param_2[0xd] >> 8);
    *(char *)(iVar1 + 0x27) = (char)param_2[0xe];
    *(char *)(iVar1 + 0x28) = (char)((ushort)param_2[0xe] >> 8);
    FUN_600a9234(param_1,iVar1);
  }
  return iVar1 != 0;
}


