// 60085f2c  pem_lib__60085f2c  size=258 bytes
// src: pem_lib.c
// --- callers ---
//   60086508 FUN_60086508
// --- callees ---
//   600e9fe2 FUN_600e9fe2
//   600e0552 FUN_600e0552
//   6008cbc4 FUN_6008cbc4
//   600e9dfa FUN_600e9dfa
//   6013cfb0 thunk_EXT_FUN_0000ac52
//   600ed880 FUN_600ed880
//   600e0a14 FUN_600e0a14
//   600e9f1c FUN_600e9f1c
//   6008c728 bcm__6008c728
//   600e9e02 FUN_600e9e02


/* src: pem_lib.c */

undefined4 pem_lib__60085f2c(int *param_1,int param_2,int *param_3,code *param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_4f8;
  int local_4f4;
  undefined1 auStack_4f0 [64];
  undefined1 auStack_4b0 [136];
  undefined1 auStack_428 [1028];
  
  local_4f8 = 0;
  if (*param_1 != 0) {
    if (param_4 == (code *)0x0) {
      param_4 = DAT_60086030;
    }
    iVar3 = *param_3;
    iVar1 = (*param_4)(auStack_428,0x400,0,param_5);
    if (iVar1 < 1) {
      FUN_600e0552(9,0,0x68,DAT_60086034,0x184);
      return 0;
    }
    iVar4 = *param_1;
    uVar2 = FUN_6008cbc4();
    iVar1 = FUN_600ed880(iVar4,uVar2,param_1 + 1,auStack_428,iVar1,1,auStack_4f0,0);
    if (iVar1 == 0) {
      return 0;
    }
    local_4f4 = iVar3;
    FUN_600e9dfa(auStack_4b0);
    iVar1 = FUN_600e9fe2(auStack_4b0,*param_1,0,auStack_4f0,param_1 + 1);
    if ((iVar1 == 0) ||
       (iVar1 = FUN_600e9f1c(auStack_4b0,param_2,&local_4f8,param_2,local_4f4), iVar1 == 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = bcm__6008c728(auStack_4b0,local_4f8 + param_2,&local_4f4);
    }
    FUN_600e9e02(auStack_4b0);
    thunk_EXT_FUN_0000ac52(auStack_428,0x400);
    thunk_EXT_FUN_0000ac52(auStack_4f0,0x40);
    if (iVar1 == 0) {
      FUN_600e0552(9,0,0x65,DAT_60086034,0x197);
      return 0;
    }
    *param_3 = local_4f4 + local_4f8;
  }
  return 1;
}


