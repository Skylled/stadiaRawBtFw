// 6008b570  bcm__6008b570  size=150 bytes
// src: bcm.c
// --- callers ---
//   600e94ca FUN_600e94ca
//   600e7766 FUN_600e7766
//   6008ba20 bcm__6008ba20
//   6008bf44 bcm__6008bf44
//   6008bbdc bcm__6008bbdc
//   600e932c FUN_600e932c
//   6008c5fc bcm__6008c5fc
//   600e89f8 FUN_600e89f8
//   6008e700 bcm__6008e700
//   600e98c6 FUN_600e98c6
//   6008d120 bcm__6008d120
//   6008c0d8 bcm__6008c0d8
//   600e99a2 FUN_600e99a2
//   6008b79c bcm__6008b79c
//   6008e264 bcm__6008e264
//   600e984a FUN_600e984a
//   6008e910 bcm__6008e910
//   600e957c FUN_600e957c
// --- callees ---
//   6008b384 bcm__6008b384
//   600e0ab2 FUN_600e0ab2
//   600e0be8 FUN_600e0be8
//   600e0aac FUN_600e0aac
//   600e0ab8 FUN_600e0ab8
//   600e0552 FUN_600e0552
//   600e6a22 FUN_600e6a22


/* src: bcm.c */

int bcm__6008b570(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if ((char)param_1[5] != '\0') {
    if (*(char *)((int)param_1 + 0x15) == '\0') {
      return 0;
    }
    FUN_600e0552(3,0,0x74,DAT_6008b608,0x9c,param_2,param_3);
    *(undefined1 *)((int)param_1 + 0x15) = 0;
    return 0;
  }
  if (*param_1 == 0) {
    iVar1 = FUN_600e0aac();
    *param_1 = iVar1;
    if (iVar1 == 0) {
      FUN_600e0552(3,0,0x41,DAT_6008b608,0xa5,param_2,param_3);
      goto LAB_6008b5b0;
    }
  }
  iVar2 = param_1[4];
  iVar1 = FUN_600e0ab2(*param_1);
  if ((iVar2 != iVar1) ||
     ((iVar1 = bcm__6008b384(), iVar1 != 0 && (iVar2 = FUN_600e0be8(*param_1,iVar1), iVar2 != 0))))
  {
    iVar1 = FUN_600e0ab8(*param_1,param_1[4]);
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 4) = 0;
    param_1[4] = param_1[4] + 1;
    return iVar1;
  }
  FUN_600e0552(3,0,0x74,DAT_6008b608,0xae,param_2,param_3);
  FUN_600e6a22(iVar1);
LAB_6008b5b0:
  *(undefined1 *)(param_1 + 5) = 1;
  return 0;
}


