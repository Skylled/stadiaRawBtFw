// 600679d4  gotham__600679d4  size=104 bytes
// src: gotham.cc
// --- callers ---
//   60074658 timer__60074658
// --- callees ---
//   600e02ee FUN_600e02ee
//   600e0300 FUN_600e0300
//   60084cf0 FUN_60084cf0
//   600e02d0 FUN_600e02d0
//   600e02dc FUN_600e02dc
//   600e02d6 FUN_600e02d6
//   600e02ae FUN_600e02ae
//   600e02e8 FUN_600e02e8
//   600e02e2 FUN_600e02e2
//   6010165c FUN_6010165c


/* src: gotham.cc */

undefined4 gotham__600679d4(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 in_r3;
  
  piVar1 = DAT_60067a3c;
  if (*DAT_60067a3c == 0) {
    uVar2 = FUN_60084cf0();
    iVar3 = FUN_600e02ae(uVar2,DAT_60067a40);
    *piVar1 = iVar3;
    if (iVar3 == 0) {
      FUN_6010165c(0x28,DAT_60067a48,0x9c,DAT_60067a44,in_r3);
      uVar2 = 10;
    }
    else {
      FUN_600e02e2(iVar3,DAT_60067a4c);
      FUN_600e02e8(*piVar1,DAT_60067a50);
      FUN_600e02dc(*piVar1,DAT_60067a54);
      FUN_600e0300(*piVar1,DAT_60067a58);
      FUN_600e02ee(*piVar1,DAT_60067a5c);
      FUN_600e02d0(*piVar1,DAT_60067a60);
      FUN_600e02d6(*piVar1,DAT_60067a64);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 9;
  }
  return uVar2;
}


