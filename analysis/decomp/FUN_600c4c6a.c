// 600c4c6a  FUN_600c4c6a  size=110 bytes
// --- callers ---
// --- callees ---
//   6006dbac FUN_6006dbac
//   600962dc FUN_600962dc
//   600efcc6 FUN_600efcc6
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600c4c6a(void)

{
  int iVar1;
  int *unaff_r7;
  
  iVar1 = FUN_6006dbac(0x18,DAT_600c4cd8);
  unaff_r7[5] = iVar1;
  if (unaff_r7[5] != 0) {
    thunk_EXT_FUN_0000b5ba(unaff_r7[5],0,0x18);
    FUN_600efcc6(unaff_r7[5] + 0xc,unaff_r7[3]);
    *(char *)(unaff_r7[5] + 10) = (char)unaff_r7[8];
    *(short *)(unaff_r7[5] + 0x14) = (short)unaff_r7[9];
    *(char *)(unaff_r7[5] + 0x16) = (char)unaff_r7[10];
    if (((*unaff_r7 != 0) && (*(char *)*unaff_r7 == -1)) && ((char)unaff_r7[8] == '\0')) {
      *(undefined1 *)(unaff_r7[5] + 8) = 4;
    }
    *(undefined2 *)unaff_r7[5] = 0x109;
    FUN_600962dc(unaff_r7[5]);
  }
  return;
}


