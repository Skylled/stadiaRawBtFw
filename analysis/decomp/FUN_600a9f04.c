// 600a9f04  FUN_600a9f04  size=724 bytes
// --- callers ---
// --- callees ---
//   600d932a FUN_600d932a
//   60095df4 FUN_60095df4
//   600aa5ac FUN_600aa5ac
//   600f31c6 FUN_600f31c6
//   6006ddd8 FUN_6006ddd8
//   600a9234 FUN_600a9234
//   6006e5bc FUN_6006e5bc
//   600b9d94 FUN_600b9d94
//   600d9380 FUN_600d9380
//   6006e160 FUN_6006e160
//   600a89f0 FUN_600a89f0
//   6006e3b0 FUN_6006e3b0
//   6006df58 FUN_6006df58
//   6006e6a8 FUN_6006e6a8
//   6006be9c FUN_6006be9c
//   600d908e FUN_600d908e
//   6006e2d0 FUN_6006e2d0
//   600b9e28 FUN_600b9e28
//   600ad710 FUN_600ad710


undefined4 FUN_600a9f04(void)

{
  bool bVar1;
  ushort uVar2;
  ushort *puVar3;
  int iVar4;
  ushort uVar5;
  byte bStack_9;
  
  FUN_6006e5bc(0xffff,0);
  FUN_6006be9c(DAT_600aa228,DAT_600aa224);
  FUN_600d9380(10);
  FUN_600f31c6();
  FUN_600d908e();
  FUN_60095df4();
  FUN_6006e6a8(5,1);
  while (uVar2 = FUN_6006e5bc(0xffff,0), (uVar2 & 1) == 0) {
LAB_600aa0e0:
    if ((uVar2 & 0x10) != 0) {
      FUN_600d932a(DAT_600aa234,1);
      while ((*(int *)(DAT_600aa33c + 0x4c) != 0 &&
             (*(int *)(*(int *)(DAT_600aa33c + 0x4c) + 0xc) == 0))) {
        iVar4 = *(int *)(DAT_600aa230 + 0x4c);
        FUN_6006e2d0(DAT_600aa234,iVar4);
        switch(*(undefined2 *)(iVar4 + 0x14)) {
        case 1:
          FUN_600a0344(iVar4);
          break;
        case 2:
        case 3:
        case 4:
        case 0x2a:
        case 0x2b:
          FUN_600bb2ac(iVar4);
          break;
        case 5:
          FUN_600fa5a6(*(undefined4 *)(iVar4 + 0x10));
          break;
        default:
          bVar1 = false;
          for (bStack_9 = 0; (!bVar1 && (bStack_9 < 2)); bStack_9 = bStack_9 + 1) {
            if ((*(int *)((uint)bStack_9 * 8 + DAT_600aa33c + 4) != 0) &&
               (iVar4 == *(int *)(DAT_600aa33c + (uint)bStack_9 * 8))) {
              (**(code **)((uint)bStack_9 * 8 + DAT_600aa33c + 4))(iVar4);
              bVar1 = true;
            }
          }
          break;
        case 7:
          FUN_60099f04(iVar4);
          break;
        case 8:
          FUN_600a3294();
          break;
        case 0xd:
          (**(code **)(iVar4 + 0x10))(iVar4);
          break;
        case 0x2c:
          FUN_600a9c4c((char)*(undefined2 *)(iVar4 + 0x14) + -0x2c);
          break;
        case 0x2f:
        case 0x30:
        case 0x33:
        case 0x37:
        case 0x38:
          FUN_6009e9e4(iVar4);
          break;
        case 0x31:
          FUN_600f6afc(iVar4);
          break;
        case 0x32:
          FUN_600c1c04(iVar4);
          break;
        case 0x35:
          FUN_600f6b16(iVar4);
        }
      }
      if (*(int *)(DAT_600aa33c + 0x4c) == 0) {
        FUN_6006e160(0);
      }
    }
    if ((uVar2 & 0x40) != 0) {
      FUN_600aa4f4();
    }
    if ((uVar2 & 4) != 0) {
      while (iVar4 = FUN_6006df58(2), iVar4 != 0) {
        FUN_600961e0(iVar4);
      }
    }
    if ((uVar2 & 0x20) != 0) {
      FUN_6009623c();
    }
    if ((short)uVar2 < 0) {
      return 0;
    }
  }
LAB_600aa0d0:
  do {
    puVar3 = (ushort *)FUN_6006df58(0);
    if (puVar3 == (ushort *)0x0) goto LAB_600aa0e0;
    uVar5 = *puVar3 & 0xff00;
    if (uVar5 != 0x1900) {
      if (uVar5 < 0x1901) {
        if (uVar5 == 0x1100) {
          FUN_600b9e28(puVar3);
          goto LAB_600aa0d0;
        }
        if (uVar5 < 0x1101) {
          if (uVar5 == 0x1000) {
LAB_600a9fbc:
            FUN_600a89f0((char)*puVar3,puVar3);
            FUN_6006ddd8(puVar3,DAT_600aa22c,0x122);
            FUN_600aa5ac();
            goto LAB_600aa0d0;
          }
        }
        else {
          if (uVar5 == 0x1200) goto LAB_600a9fbc;
          if (uVar5 == 0x1600) {
            FUN_600a9234((char)*puVar3,puVar3);
            goto LAB_600aa0d0;
          }
        }
      }
      else {
        if (uVar5 == 0x3d00) {
          if (*(int *)(DAT_600aa230 + 0x4c) == 0) {
            FUN_6006e160(0);
          }
          FUN_6006ddd8(puVar3,DAT_600aa22c,0x1b8);
          goto LAB_600aa0d0;
        }
        if (uVar5 < 0x3d01) {
          if (uVar5 != 0x3c00) goto LAB_600aa04e;
          FUN_6006e3b0(0,1000,1);
          FUN_6006ddd8(puVar3,DAT_600aa22c,0x1b0);
          goto LAB_600aa0d0;
        }
        if (uVar5 == 0x3e00) {
          FUN_6006e3b0(2,100,1);
          FUN_6006ddd8(puVar3,DAT_600aa22c,0x1be);
          goto LAB_600aa0d0;
        }
        if (uVar5 == 0x7100) {
          FUN_600ad710(puVar3);
          FUN_6006ddd8(puVar3,DAT_600aa22c,0x1c5);
          goto LAB_600aa0d0;
        }
      }
LAB_600aa04e:
      bStack_9 = 0;
      uVar5 = *puVar3;
      bVar1 = false;
      for (; (!bVar1 && (bStack_9 < 6)); bStack_9 = bStack_9 + 1) {
        if ((*(int *)((bStack_9 + 2) * 8 + DAT_600aa230 + 4) != 0) &&
           (((uVar5 & 0xff00) == *(ushort *)(DAT_600aa230 + (bStack_9 + 2) * 8) &&
            (*(int *)((bStack_9 + 2) * 8 + DAT_600aa230 + 4) != 0)))) {
          (**(code **)((bStack_9 + 2) * 8 + DAT_600aa230 + 4))(puVar3);
          bVar1 = true;
        }
      }
      if (!bVar1) {
        FUN_6006ddd8(puVar3,DAT_600aa22c,0x1de);
      }
      goto LAB_600aa0d0;
    }
    FUN_600b9d94(puVar3);
  } while( true );
}


