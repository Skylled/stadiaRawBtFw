// 600aa3cc  FUN_600aa3cc  size=96 bytes
// --- callers ---
//   600a0f7c FUN_600a0f7c
//   600fca7c FUN_600fca7c
//   600a2338 FUN_600a2338
//   600b6900 FUN_600b6900
//   600a0e08 FUN_600a0e08
//   600f7d88 FUN_600f7d88
//   600b89b8 FUN_600b89b8
//   600b02e0 FUN_600b02e0
//   600ba1c4 FUN_600ba1c4
//   600bf374 FUN_600bf374
//   600a99cc FUN_600a99cc
//   6009a254 FUN_6009a254
//   600a943c FUN_600a943c
//   600acf50 FUN_600acf50
//   6009dc14 FUN_6009dc14
//   6009decc FUN_6009decc
//   6009a1dc FUN_6009a1dc
//   600c1864 FUN_600c1864
//   6009a2c8 FUN_6009a2c8
//   600f3b78 FUN_600f3b78
//   600b6d30 FUN_600b6d30
//   600b5ec8 FUN_600b5ec8
//   600a30f0 FUN_600a30f0
//   600a0bc4 FUN_600a0bc4
//   6009980c FUN_6009980c
//   600bc880 FUN_600bc880
//   600a068c FUN_600a068c
//   6009a154 FUN_6009a154
//   600a957c FUN_600a957c
//   600c1b74 FUN_600c1b74
//   600bb15c FUN_600bb15c
//   6009daac FUN_6009daac
//   600fa0d6 FUN_600fa0d6
//   6009a3d4 FUN_6009a3d4
//   600bc00c FUN_600bc00c
//   600a046c FUN_600a046c
//   600a0e88 FUN_600a0e88
//   600a8108 FUN_600a8108
//   600a11c0 FUN_600a11c0
//   600a32d4 FUN_600a32d4
//   600b5540 FUN_600b5540
//   6009bb50 FUN_6009bb50
//   600af0b4 FUN_600af0b4
//   6009a4a4 FUN_6009a4a4
//   600a9b04 FUN_600a9b04
//   6009e70c FUN_6009e70c
//   600a0600 FUN_600a0600
//   600a05ac FUN_600a05ac
//   600bb534 FUN_600bb534
//   6009e768 FUN_6009e768
//   600a0730 FUN_600a0730
//   600a65f4 FUN_600a65f4
// --- callees ---
//   6006e594 FUN_6006e594
//   6006e2d0 FUN_6006e2d0
//   6006de78 FUN_6006de78
//   6006dbac FUN_6006dbac
//   6006e160 FUN_6006e160


void FUN_600aa3cc(undefined4 param_1)

{
  int iVar1;
  undefined2 *puVar2;
  
  FUN_6006e2d0(DAT_600aa42c,param_1);
  iVar1 = FUN_6006e594();
  if (iVar1 == 1) {
    if (*(int *)(DAT_600aa434 + 0x4c) == 0) {
      FUN_6006e160(0);
    }
  }
  else {
    puVar2 = (undefined2 *)FUN_6006dbac(8,DAT_600aa430,0x35a);
    if (puVar2 != (undefined2 *)0x0) {
      *puVar2 = 0x3d00;
      FUN_6006de78(1,0,puVar2,DAT_600aa430,0x35d);
    }
  }
  return;
}


