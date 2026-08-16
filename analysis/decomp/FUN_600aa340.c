// 600aa340  FUN_600aa340  size=128 bytes
// --- callers ---
//   600b6378 FUN_600b6378
//   600a0300 FUN_600a0300
//   600b6900 FUN_600b6900
//   600f8aea FUN_600f8aea
//   600a01c4 FUN_600a01c4
//   600a027c FUN_600a027c
//   600b674c FUN_600b674c
//   600f8664 FUN_600f8664
//   600b89b8 FUN_600b89b8
//   600a0298 FUN_600a0298
//   600f6ab0 FUN_600f6ab0
//   600f9d16 FUN_600f9d16
//   600a99cc FUN_600a99cc
//   6009a254 FUN_6009a254
//   600a943c FUN_600a943c
//   6009dc14 FUN_6009dc14
//   600f6ad6 FUN_600f6ad6
//   600bc5c4 FUN_600bc5c4
//   6009a1dc FUN_6009a1dc
//   600c1864 FUN_600c1864
//   600a02d8 FUN_600a02d8
//   600a0260 FUN_600a0260
//   600b6d30 FUN_600b6d30
//   600b5ec8 FUN_600b5ec8
//   600a02b4 FUN_600a02b4
//   600a957c FUN_600a957c
//   600b6550 FUN_600b6550
//   60098c14 FUN_60098c14
//   600a3014 FUN_600a3014
//   600c1b74 FUN_600c1b74
//   600bb15c FUN_600bb15c
//   600b9408 FUN_600b9408
//   6009daac FUN_6009daac
//   600fa5c6 FUN_600fa5c6
//   6009de30 FUN_6009de30
//   600fa0d6 FUN_600fa0d6
//   600a031c FUN_600a031c
//   600be060 FUN_600be060
//   600f89ea FUN_600f89ea
//   600a6d70 FUN_600a6d70
//   600a0244 FUN_600a0244
//   600b8f0c FUN_600b8f0c
//   600f6a8a FUN_600f6a8a
//   600a8108 FUN_600a8108
//   600a020c FUN_600a020c
//   600b8888 FUN_600b8888
//   600a0228 FUN_600a0228
//   6009bb50 FUN_6009bb50
//   600f8122 FUN_600f8122
//   600b9e28 FUN_600b9e28
//   600a01f0 FUN_600a01f0
//   600bc480 FUN_600bc480
//   600f8bd4 FUN_600f8bd4
//   600a9b04 FUN_600a9b04
//   600a85b8 FUN_600a85b8
//   600b8d7c FUN_600b8d7c
//   600b5dd0 FUN_600b5dd0
//   600b61c4 FUN_600b61c4
//   6009dd74 FUN_6009dd74
//   600b59ec FUN_600b59ec
//   600b643a FUN_600b643a
//   600bdf3c FUN_600bdf3c
//   600a65f4 FUN_600a65f4
//   600a6720 FUN_600a6720
// --- callees ---
//   6006e594 FUN_6006e594
//   6006e2d0 FUN_6006e2d0
//   6006e214 FUN_6006e214
//   6006de78 FUN_6006de78
//   6006e3b0 FUN_6006e3b0
//   6006dbac FUN_6006dbac


void FUN_600aa340(int param_1,undefined2 param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 *puVar2;
  
  if (*(int *)(DAT_600aa3c0 + 0x4c) == 0) {
    iVar1 = FUN_6006e594();
    if (iVar1 == 1) {
      FUN_6006e3b0(0,1000,1);
    }
    else {
      puVar2 = (undefined2 *)FUN_6006dbac(8,DAT_600aa3c4,0x325);
      if (puVar2 != (undefined2 *)0x0) {
        *puVar2 = 0x3c00;
        FUN_6006de78(1,0,puVar2,DAT_600aa3c4,0x328);
      }
    }
  }
  FUN_6006e2d0(DAT_600aa3c8,param_1);
  *(undefined2 *)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  FUN_6006e214(DAT_600aa3c8,param_1);
  return;
}


