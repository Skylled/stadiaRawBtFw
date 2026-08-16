// 600912a8  ec_asn1__600912a8  size=132 bytes
// src: ec_asn1.c
// --- callers ---
//   600917a0 ec_asn1__600917a0
//   60085470 FUN_60085470
//   60085340 FUN_60085340
// --- callees ---
//   600ed1b4 FUN_600ed1b4
//   6008cbe0 FUN_6008cbe0
//   600ecfae FUN_600ecfae
//   600e0552 FUN_600e0552
//   600ed0de FUN_600ed0de
//   600ea7fe FUN_600ea7fe


/* src: ec_asn1.c */

bool ec_asn1__600912a8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_28 [20];
  
  iVar1 = FUN_600ea7fe(param_2);
  if (iVar1 == 0) {
    FUN_600e0552(0xf,0,0x7b,DAT_6009132c,0x16c);
  }
  else {
    iVar2 = FUN_6008cbe0();
    iVar3 = 0;
    do {
      if (*(int *)(iVar2 + iVar3 * 0x1c) == iVar1) {
        iVar1 = FUN_600ed1b4(param_1,auStack_28,6);
        if (iVar1 == 0) {
          return false;
        }
        iVar2 = iVar2 + iVar3 * 0x1c;
        iVar1 = FUN_600ed0de(auStack_28,*(undefined4 *)(iVar2 + 4),*(undefined1 *)(iVar2 + 8));
        if (iVar1 == 0) {
          return false;
        }
        iVar1 = FUN_600ecfae(param_1);
        return iVar1 != 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 4);
    FUN_600e0552(0xf,0,0x7b,DAT_6009132c,0x17b);
  }
  return false;
}


