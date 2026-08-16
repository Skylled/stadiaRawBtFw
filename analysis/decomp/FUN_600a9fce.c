// 600a9fce  FUN_600a9fce  size=524 bytes
// --- callers ---
// --- callees ---
//   600aa5ac FUN_600aa5ac
//   600aa4f4 FUN_600aa4f4
//   600ad710 FUN_600ad710
//   600961e0 FUN_600961e0
//   6009623c FUN_6009623c
//   6006df58 FUN_6006df58
//   6006e2d0 FUN_6006e2d0
//   6006e3b0 FUN_6006e3b0
//   6006e160 FUN_6006e160
//   6006ddd8 FUN_6006ddd8
//   600d932a FUN_600d932a
//   600a9234 FUN_600a9234


undefined4 FUN_600a9fce(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  ushort uVar3;
  int unaff_r7;
  
code_r0x600a9fce:
  FUN_6006ddd8(*(undefined4 *)(unaff_r7 + 0x18),DAT_600aa22c,param_3);
  FUN_600aa5ac();
LAB_600aa0d0:
  while( true ) {
    while( true ) {
      uVar2 = FUN_6006df58(0);
      *(undefined4 *)(unaff_r7 + 0x18) = uVar2;
      if (*(int *)(unaff_r7 + 0x18) != 0) break;
      do {
        if ((*(ushort *)(unaff_r7 + 0x1c) & 0x10) != 0) {
          FUN_600d932a(DAT_600aa234,1);
          while ((*(int *)(DAT_600aa33c + 0x4c) != 0 &&
                 (*(int *)(*(int *)(DAT_600aa33c + 0x4c) + 0xc) == 0))) {
            *(undefined4 *)(unaff_r7 + 0x10) = *(undefined4 *)(DAT_600aa230 + 0x4c);
            FUN_6006e2d0(DAT_600aa234,*(undefined4 *)(unaff_r7 + 0x10));
            switch(*(undefined2 *)(*(int *)(unaff_r7 + 0x10) + 0x14)) {
            case 1:
              FUN_600a0344(*(undefined4 *)(unaff_r7 + 0x10));
              break;
            case 2:
            case 3:
            case 4:
            case 0x2a:
            case 0x2b:
              FUN_600bb2ac(*(undefined4 *)(unaff_r7 + 0x10));
              break;
            case 5:
              FUN_600fa5a6(*(undefined4 *)(*(int *)(unaff_r7 + 0x10) + 0x10));
              break;
            default:
              *(undefined1 *)(unaff_r7 + 0x1f) = 0;
              *(undefined1 *)(unaff_r7 + 0x1e) = 0;
              while ((*(char *)(unaff_r7 + 0x1e) == '\0' && (*(byte *)(unaff_r7 + 0x1f) < 2))) {
                if ((*(int *)((uint)*(byte *)(unaff_r7 + 0x1f) * 8 + DAT_600aa33c + 4) != 0) &&
                   (*(int *)(unaff_r7 + 0x10) ==
                    *(int *)(DAT_600aa33c + (uint)*(byte *)(unaff_r7 + 0x1f) * 8))) {
                  (**(code **)((uint)*(byte *)(unaff_r7 + 0x1f) * 8 + DAT_600aa33c + 4))
                            (*(undefined4 *)(unaff_r7 + 0x10));
                  *(undefined1 *)(unaff_r7 + 0x1e) = 1;
                }
                *(char *)(unaff_r7 + 0x1f) = *(char *)(unaff_r7 + 0x1f) + '\x01';
              }
              break;
            case 7:
              FUN_60099f04(*(undefined4 *)(unaff_r7 + 0x10));
              break;
            case 8:
              FUN_600a3294();
              break;
            case 0xd:
              *(undefined4 *)(unaff_r7 + 0xc) = *(undefined4 *)(*(int *)(unaff_r7 + 0x10) + 0x10);
              (**(code **)(unaff_r7 + 0xc))(*(undefined4 *)(unaff_r7 + 0x10));
              break;
            case 0x2c:
              func_0x600a9c4c((char)*(undefined2 *)(*(int *)(unaff_r7 + 0x10) + 0x14) + -0x2c);
              break;
            case 0x2f:
            case 0x30:
            case 0x33:
            case 0x37:
            case 0x38:
              func_0x6009e9e4(*(undefined4 *)(unaff_r7 + 0x10));
              break;
            case 0x31:
              func_0x600f6afc(*(undefined4 *)(unaff_r7 + 0x10));
              break;
            case 0x32:
              FUN_600c1c04(*(undefined4 *)(unaff_r7 + 0x10));
              break;
            case 0x35:
              func_0x600f6b16(*(undefined4 *)(unaff_r7 + 0x10));
            }
          }
          if (*(int *)(DAT_600aa33c + 0x4c) == 0) {
            FUN_6006e160(0);
          }
        }
        if ((*(ushort *)(unaff_r7 + 0x1c) & 0x40) != 0) {
          FUN_600aa4f4();
        }
        if ((*(ushort *)(unaff_r7 + 0x1c) & 4) != 0) {
          while( true ) {
            uVar2 = FUN_6006df58(2);
            *(undefined4 *)(unaff_r7 + 0x18) = uVar2;
            if (*(int *)(unaff_r7 + 0x18) == 0) break;
            FUN_600961e0(*(undefined4 *)(unaff_r7 + 0x18));
          }
        }
        if ((*(ushort *)(unaff_r7 + 0x1c) & 0x20) != 0) {
          FUN_6009623c();
        }
        if (*(short *)(unaff_r7 + 0x1c) < 0) {
          return 0;
        }
        uVar1 = FUN_6006e5bc(0xffff,0);
        *(undefined2 *)(unaff_r7 + 0x1c) = uVar1;
      } while ((*(ushort *)(unaff_r7 + 0x1c) & 1) == 0);
    }
    uVar3 = **(ushort **)(unaff_r7 + 0x18) & 0xff00;
    if (uVar3 != 0x1900) break;
    FUN_600b9d94(*(undefined4 *)(unaff_r7 + 0x18));
  }
  if (uVar3 < 0x1901) {
    if (uVar3 == 0x1100) {
      FUN_600b9e28(*(undefined4 *)(unaff_r7 + 0x18));
      goto LAB_600aa0d0;
    }
    if (uVar3 < 0x1101) {
      if (uVar3 == 0x1000) goto LAB_600a9fbc;
    }
    else {
      if (uVar3 == 0x1200) goto LAB_600a9fbc;
      if (uVar3 == 0x1600) {
        FUN_600a9234((char)**(undefined2 **)(unaff_r7 + 0x18),*(undefined4 *)(unaff_r7 + 0x18));
        goto LAB_600aa0d0;
      }
    }
  }
  else {
    if (uVar3 == 0x3d00) {
      if (*(int *)(DAT_600aa230 + 0x4c) == 0) {
        FUN_6006e160(0);
      }
      FUN_6006ddd8(*(undefined4 *)(unaff_r7 + 0x18),DAT_600aa22c,0x1b8);
      goto LAB_600aa0d0;
    }
    if (0x3d00 < uVar3) {
      if (uVar3 == 0x3e00) {
        FUN_6006e3b0(2,100,1);
        FUN_6006ddd8(*(undefined4 *)(unaff_r7 + 0x18),DAT_600aa22c,0x1be);
      }
      else {
        if (uVar3 != 0x7100) goto LAB_600aa04e;
        FUN_600ad710(*(undefined4 *)(unaff_r7 + 0x18));
        FUN_6006ddd8(*(undefined4 *)(unaff_r7 + 0x18),DAT_600aa22c,0x1c5);
      }
      goto LAB_600aa0d0;
    }
    if (uVar3 == 0x3c00) {
      FUN_6006e3b0(0,1000,1);
      FUN_6006ddd8(*(undefined4 *)(unaff_r7 + 0x18),DAT_600aa22c,0x1b0);
      goto LAB_600aa0d0;
    }
  }
LAB_600aa04e:
  *(undefined1 *)(unaff_r7 + 0x1f) = 0;
  *(ushort *)(unaff_r7 + 0x16) = **(ushort **)(unaff_r7 + 0x18) & 0xff00;
  *(undefined1 *)(unaff_r7 + 0x1e) = 0;
  while ((*(char *)(unaff_r7 + 0x1e) == '\0' && (*(byte *)(unaff_r7 + 0x1f) < 6))) {
    if ((*(int *)((*(byte *)(unaff_r7 + 0x1f) + 2) * 8 + DAT_600aa230 + 4) != 0) &&
       ((*(short *)(unaff_r7 + 0x16) ==
         *(short *)(DAT_600aa230 + (*(byte *)(unaff_r7 + 0x1f) + 2) * 8) &&
        (*(int *)((*(byte *)(unaff_r7 + 0x1f) + 2) * 8 + DAT_600aa230 + 4) != 0)))) {
      (**(code **)((*(byte *)(unaff_r7 + 0x1f) + 2) * 8 + DAT_600aa230 + 4))
                (*(undefined4 *)(unaff_r7 + 0x18));
      *(undefined1 *)(unaff_r7 + 0x1e) = 1;
    }
    *(char *)(unaff_r7 + 0x1f) = *(char *)(unaff_r7 + 0x1f) + '\x01';
  }
  if (*(char *)(unaff_r7 + 0x1e) == '\0') {
    FUN_6006ddd8(*(undefined4 *)(unaff_r7 + 0x18),DAT_600aa22c,0x1de);
  }
  goto LAB_600aa0d0;
LAB_600a9fbc:
  FUN_600a89f0((char)**(undefined2 **)(unaff_r7 + 0x18),*(undefined4 *)(unaff_r7 + 0x18));
  param_3 = 0x122;
  goto code_r0x600a9fce;
}


