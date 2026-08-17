// 600b5dd0  FUN_600b5dd0  size=38 bytes
// --- callers ---
//   60134420 FUN_60134420
// --- callees ---
//   600aa340 FUN_600aa340


void FUN_600b5dd0(void)

{
  int unaff_r7;
  
  do {
    FUN_600aa340(*(int *)(unaff_r7 + 0xc) + 0x44,2,2);
    do {
      do {
        *(short *)(unaff_r7 + 0x14) = *(short *)(unaff_r7 + 0x14) + 1;
        *(int *)(unaff_r7 + 0xc) = *(int *)(unaff_r7 + 0xc) + 0xa4;
        if (3 < *(ushort *)(unaff_r7 + 0x14)) {
          return;
        }
      } while ((**(char **)(unaff_r7 + 0xc) == '\0') ||
              (*(char *)(*(int *)(unaff_r7 + 0xc) + 0x32) != '\x02'));
      if (*(char *)(*(int *)(unaff_r7 + 0xc) + 0x28) == '\x01') {
        *(undefined2 *)(*(int *)(unaff_r7 + 0xc) + 0x1a) = *(undefined2 *)(unaff_r7 + 6);
      }
      else {
        if ((*(short *)(*(int *)(unaff_r7 + 0xc) + 0x1a) != 0) && (*(short *)(unaff_r7 + 0x16) == 0)
           ) {
          *(short *)(DAT_600b5df8 + 0xf52) =
               *(short *)(*(int *)(unaff_r7 + 0xc) + 0xa0) + *(short *)(DAT_600b5df8 + 0xf52);
        }
        *(undefined2 *)(*(int *)(unaff_r7 + 0xc) + 0x1a) = *(undefined2 *)(unaff_r7 + 0x16);
        if (*(short *)(unaff_r7 + 0x12) != 0) {
          *(short *)(*(int *)(unaff_r7 + 0xc) + 0x1a) =
               *(short *)(*(int *)(unaff_r7 + 0xc) + 0x1a) + 1;
          *(short *)(unaff_r7 + 0x12) = *(short *)(unaff_r7 + 0x12) + -1;
        }
      }
    } while (((*(char *)(*(int *)(unaff_r7 + 0xc) + 1) != '\x04') ||
             (*(short *)(*(int *)(unaff_r7 + 0xc) + 0x88) == 0)) ||
            (*(ushort *)(*(int *)(unaff_r7 + 0xc) + 0x1a) <=
             *(ushort *)(*(int *)(unaff_r7 + 0xc) + 0xa0)));
  } while( true );
}


