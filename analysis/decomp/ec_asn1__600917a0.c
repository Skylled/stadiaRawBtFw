// 600917a0  ec_asn1__600917a0  size=280 bytes
// src: ec_asn1.c
// --- callers ---
//   60085340 FUN_60085340
// --- callees ---
//   600ed12a FUN_600ed12a
//   600eda9c FUN_600eda9c
//   600ed1b4 FUN_600ed1b4
//   600ea88a FUN_600ea88a
//   600e7474 FUN_600e7474
//   600912a8 ec_asn1__600912a8
//   600e0552 FUN_600e0552
//   600ece3c FUN_600ece3c
//   600ed266 FUN_600ed266
//   600ea7fa FUN_600ea7fa
//   600ecfae FUN_600ecfae


/* src: ec_asn1.c */

undefined4 ec_asn1__600917a0(undefined4 param_1,int *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined1 auStack_58 [16];
  undefined1 auStack_48 [16];
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [20];
  
  if (((param_2 == (int *)0x0) || (*param_2 == 0)) || (param_2[2] == 0)) {
    uVar2 = 0x43;
    uVar4 = 0xc3;
    goto LAB_600917bc;
  }
  uVar3 = FUN_600ed1b4(param_1,auStack_58,DAT_600918bc);
  if ((((int)uVar3 == 0) ||
      (iVar1 = FUN_600ed266(auStack_58,(int)((ulonglong)uVar3 >> 0x20),1,0), iVar1 == 0)) ||
     (iVar1 = FUN_600ed1b4(auStack_58,auStack_48,4), iVar1 == 0)) {
LAB_600917d6:
    uVar4 = 0xce;
  }
  else {
    FUN_600ea7fa(*param_2);
    uVar2 = FUN_600e7474();
    uVar4 = FUN_600ea88a(param_2);
    iVar1 = FUN_600ece3c(auStack_48,uVar2,uVar4);
    if (iVar1 == 0) goto LAB_600917d6;
    if (((int)(param_3 << 0x1f) < 0) ||
       (((iVar1 = FUN_600ed1b4(auStack_58,auStack_28,0xa0000000), iVar1 != 0 &&
         (iVar1 = ec_asn1__600912a8(auStack_28,*param_2), iVar1 != 0)) &&
        (iVar1 = FUN_600ecfae(auStack_58), iVar1 != 0)))) {
      if ((((param_3 & 2) != 0) || (param_2[1] == 0)) ||
         (((iVar1 = FUN_600ed1b4(auStack_58,auStack_38,DAT_600918c0), iVar1 != 0 &&
           (((iVar1 = FUN_600ed1b4(auStack_38,auStack_28,3), iVar1 != 0 &&
             (iVar1 = FUN_600ed12a(auStack_28,0), iVar1 != 0)) &&
            (iVar1 = FUN_600eda9c(auStack_28,*param_2,param_2[1],(char)param_2[5],0), iVar1 != 0))))
          && (iVar1 = FUN_600ecfae(auStack_58), iVar1 != 0)))) {
        iVar1 = FUN_600ecfae(param_1);
        if (iVar1 == 0) {
          FUN_600e0552(0xf,0,0x81,DAT_600918b8,0xed);
          return 0;
        }
        return 1;
      }
      uVar4 = 0xe7;
    }
    else {
      uVar4 = 0xd7;
    }
  }
  uVar2 = 0x81;
LAB_600917bc:
  FUN_600e0552(0xf,0,uVar2,DAT_600918b8,uVar4);
  return 0;
}


