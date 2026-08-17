// 600850bc  p_dsa_asn1__600850bc  size=164 bytes
// src: p_dsa_asn1.c
// --- callers ---
// --- callees ---
//   60090e6c bn_asn1__60090e6c
//   600ed1b4 FUN_600ed1b4
//   600ecfae FUN_600ecfae
//   600ed266 FUN_600ed266
//   600911d4 FUN_600911d4
//   600e0552 FUN_600e0552
//   600ed0de FUN_600ed0de


/* src: p_dsa_asn1.c */

undefined4 p_dsa_asn1__600850bc(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [20];
  
  iVar3 = *(int *)(param_2 + 8);
  if ((iVar3 == 0) || (*(int *)(iVar3 + 0x14) == 0)) {
    uVar2 = 0x76;
    uVar5 = 0xac;
  }
  else {
    uVar4 = FUN_600ed1b4(param_1,auStack_50,DAT_60085164);
    if (((((((int)uVar4 != 0) &&
           (iVar1 = FUN_600ed266(auStack_50,(int)((ulonglong)uVar4 >> 0x20),0,0), iVar1 != 0)) &&
          (iVar1 = FUN_600ed1b4(auStack_50,auStack_40,DAT_60085164), iVar1 != 0)) &&
         ((iVar1 = FUN_600ed1b4(auStack_40,auStack_30,6), iVar1 != 0 &&
          (iVar1 = FUN_600ed0de(auStack_30,DAT_60085168,7), iVar1 != 0)))) &&
        ((iVar1 = FUN_600911d4(auStack_40,iVar3), iVar1 != 0 &&
         ((iVar1 = FUN_600ed1b4(auStack_50,auStack_20,4), iVar1 != 0 &&
          (iVar3 = bn_asn1__60090e6c(auStack_20,*(undefined4 *)(iVar3 + 0x14)), iVar3 != 0)))))) &&
       (iVar3 = FUN_600ecfae(param_1), iVar3 != 0)) {
      return 1;
    }
    uVar2 = 0x69;
    uVar5 = 0xbb;
  }
  FUN_600e0552(6,0,uVar2,DAT_60085160,uVar5);
  return 0;
}


