// 6008d5e0  bcm__6008d5e0  size=212 bytes
// src: bcm.c
// --- callers ---
//   600eda9c FUN_600eda9c
// --- callees ---
//   6008cce0 bcm__6008cce0
//   600e7474 FUN_600e7474
//   600e0552 FUN_600e0552
//   600eb428 FUN_600eb428
//   600eb1d4 FUN_600eb1d4


/* src: bcm.c */

uint bcm__6008d5e0(int param_1,undefined4 *param_2,int param_3,char *param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 local_68;
  char acStack_64 [72];
  
  iVar1 = FUN_600eb428(param_1,*param_2);
  if (iVar1 == 0) {
    if ((param_3 != 2) && (param_3 != 4)) {
      FUN_600e0552(0xf,0,0x6f,DAT_6008d6b4,0x52);
      return 0;
    }
    iVar1 = FUN_600eb1d4(param_1,param_2 + 1);
    if (iVar1 == 0) {
      iVar1 = FUN_600e7474(param_1 + 0x24);
      uVar4 = iVar1 + 1;
      uVar6 = uVar4;
      if (param_3 == 4) {
        uVar6 = iVar1 + uVar4;
      }
      if (param_4 == (char *)0x0) {
        return uVar6;
      }
      if (param_5 < uVar6) {
        uVar3 = 100;
        uVar7 = 0x65;
      }
      else {
        pcVar5 = acStack_64;
        if (param_3 != 2) {
          pcVar5 = param_4 + uVar4;
        }
        iVar2 = bcm__6008cce0(param_1,param_4 + 1,pcVar5,&local_68,iVar1,param_2 + 1);
        if (iVar2 == 0) {
          return 0;
        }
        if (iVar1 == local_68) {
          if (param_3 == 2) {
            *param_4 = (acStack_64[iVar1 + -1] & 1U) + 2;
            return uVar6;
          }
          *param_4 = (char)param_3;
          return uVar6;
        }
        uVar3 = 0x44;
        uVar7 = 0x73;
      }
    }
    else {
      uVar3 = 0x77;
      uVar7 = 0x57;
    }
  }
  else {
    uVar3 = 0x6a;
    uVar7 = 0xe2;
  }
  FUN_600e0552(0xf,0,uVar3,DAT_6008d6b4,uVar7);
  return 0;
}


