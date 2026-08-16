// 6008b9f0  bcm__6008b9f0  size=44 bytes
// src: bcm.c
// --- callers ---
//   600e94ca FUN_600e94ca
//   6008ba20 bcm__6008ba20
//   600e99a2 FUN_600e99a2
//   6008eb24 bcm__6008eb24
// --- callees ---
//   600e0552 FUN_600e0552
//   600e89f8 FUN_600e89f8


/* src: bcm.c */

undefined4 bcm__6008b9f0(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_2 + 0xc) == 0) && (*(int *)(param_3 + 0xc) == 0)) {
    uVar1 = FUN_600e89f8();
    return uVar1;
  }
  FUN_600e0552(3,0,0x6d,DAT_6008ba1c,0x28d,param_2,param_3);
  return 0;
}


