// 600a1394  FUN_600a1394  size=86 bytes
// --- callers ---
//   600f0048 FUN_600f0048
//   6009f428 FUN_6009f428
//   6009f3c0 FUN_6009f3c0
//   60098284 FUN_60098284
//   600979e4 FUN_600979e4
//   600fcf7c FUN_600fcf7c
//   600f00cc FUN_600f00cc
//   60098820 FUN_60098820
//   60098718 FUN_60098718
//   60097200 FUN_60097200
//   60097f5c FUN_60097f5c
//   60098c3c FUN_60098c3c
//   60098a24 FUN_60098a24
//   60097904 FUN_60097904
//   60097b20 FUN_60097b20
//   60098530 FUN_60098530
//   60098c14 FUN_60098c14
//   60098be8 FUN_60098be8
//   60098d2c FUN_60098d2c
//   6006c088 FUN_6006c088
//   6009f2ec FUN_6009f2ec
//   6009f6c0 FUN_6009f6c0
//   600effba FUN_600effba
//   60097dc8 FUN_60097dc8
//   6009746c FUN_6009746c
//   600977fc FUN_600977fc
// --- callees ---
//   6006dbac FUN_6006dbac
//   600f752a FUN_600f752a


undefined4 FUN_600a1394(undefined2 param_1,byte param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_6006dbac(param_2 + 0xf,DAT_600a13ec,0x8b3);
  if (iVar1 == 0) {
    uVar2 = 3;
  }
  else {
    FUN_600f752a(iVar1,param_1,param_2,param_3,param_4);
    if (param_4 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}


