// 600a10e0  FUN_600a10e0  size=110 bytes
// --- callers ---
//   600aad90 FUN_600aad90
//   600fcf42 FUN_600fcf42
// --- callees ---
//   6004cb28 FUN_6004cb28
//   601024d8 FUN_601024d8
//   600b34ac FUN_600b34ac


undefined4 FUN_600a10e0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 == 0) || (uVar1 = FUN_6004cb28(param_1), iVar2 = DAT_600a1150, 0xf8 < uVar1)) {
    uVar3 = 5;
  }
  else if ((*(char *)(DAT_600a1150 + 0x881) == '\0') || (*(char *)(DAT_600a1150 + 0x881) == '\x01'))
  {
    uVar3 = 0xc;
  }
  else {
    if (DAT_600a1150 != param_1) {
      FUN_601024d8(DAT_600a1150,param_1,0xf8);
      *(undefined1 *)(DAT_600a1150 + 0xf8) = 0;
    }
    iVar2 = FUN_600b34ac(iVar2);
    if (iVar2 == 0) {
      uVar3 = 3;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}


