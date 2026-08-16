// 600bc9e4  FUN_600bc9e4  size=256 bytes
// --- callers ---
//   601323f6 FUN_601323f6
// --- callees ---
//   600bc00c FUN_600bc00c


void FUN_600bc9e4(void)

{
  int iVar1;
  int unaff_r7;
  char in_NG;
  undefined1 in_ZR;
  char in_OV;
  
  do {
    if ((!(bool)in_ZR && in_NG == in_OV) && (*(int *)(unaff_r7 + 0xc) + 4 < 7)) goto LAB_600bca0a;
    while( true ) {
      *(int *)(unaff_r7 + 0xc) = *(int *)(unaff_r7 + 0xc) + 1;
      if (3 < *(int *)(unaff_r7 + 0xc)) {
        return;
      }
      if (*(char *)(*(int *)(unaff_r7 + 4) + 0x32) == '\x02') break;
      if (((*(char *)(*(int *)(unaff_r7 + 4) + 0x32) != '\x01') ||
          (*(int *)(unaff_r7 + 0xc) + 4 < 4)) || (6 < *(int *)(unaff_r7 + 0xc) + 4)) {
LAB_600bca0a:
        if (*(int *)(*(int *)(unaff_r7 + 0xc) * 0x1c + DAT_600bcae4 + 0xed0) != 0) {
          if (((int)(uint)*(byte *)(unaff_r7 + 0xb) >> (*(int *)(unaff_r7 + 0xc) + 4U & 0xff) & 1U)
              == 0) {
            (**(code **)(*(int *)(unaff_r7 + 0xc) * 0x1c + DAT_600bcae4 + 0xed0))
                      (*(int *)(unaff_r7 + 4) + 4,0,*(undefined2 *)(*(int *)(unaff_r7 + 4) + 0x30),
                       *(undefined1 *)(*(int *)(unaff_r7 + 4) + 0x32));
            if (*(int *)(*(int *)(unaff_r7 + 4) + (*(int *)(unaff_r7 + 0xc) + 0x24) * 4) != 0) {
              FUN_600bc00c(*(undefined4 *)
                            (*(int *)(unaff_r7 + 4) + (*(int *)(unaff_r7 + 0xc) + 0x24) * 4));
              *(undefined4 *)(*(int *)(unaff_r7 + 4) + (*(int *)(unaff_r7 + 0xc) + 0x24) * 4) = 0;
            }
          }
          else {
            if (*(int *)(*(int *)(unaff_r7 + 4) + (*(int *)(unaff_r7 + 0xc) + 0x24) * 4) != 0) {
              *(undefined1 *)
               (*(int *)(*(int *)(unaff_r7 + 4) + (*(int *)(unaff_r7 + 0xc) + 0x24) * 4) + 4) = 6;
            }
            (**(code **)(*(int *)(unaff_r7 + 0xc) * 0x1c + DAT_600bcae4 + 0xed0))
                      (*(int *)(unaff_r7 + 4) + 4,1,0,*(undefined1 *)(*(int *)(unaff_r7 + 4) + 0x32)
                      );
          }
        }
      }
    }
    iVar1 = *(int *)(unaff_r7 + 0xc) + 4;
    in_OV = SBORROW4(iVar1,3);
    in_NG = *(int *)(unaff_r7 + 0xc) + 1 < 0;
    in_ZR = iVar1 == 3;
  } while( true );
}


