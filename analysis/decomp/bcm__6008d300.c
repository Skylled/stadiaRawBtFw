// 6008d300  bcm__6008d300  size=76 bytes
// src: bcm.c
// --- callers ---
//   6008d730 bcm__6008d730
// --- callees ---
//   6013cf28 thunk_EXT_FUN_0000af88
//   600e0552 FUN_600e0552
//   6008ce70 bcm__6008ce70


/* src: bcm.c */

undefined4 bcm__6008d300(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_3 == 0) || (param_4 == 0)) {
    FUN_600e0552(0xf,0,0x43,DAT_6008d34c,0xc6,param_2);
  }
  else {
    iVar1 = bcm__6008ce70();
    if ((iVar1 != 0) && (iVar1 = bcm__6008ce70(param_1,param_2 + 0x44,param_4), iVar1 != 0)) {
      thunk_EXT_FUN_0000af88(param_2 + 0x88,param_1 + 0x114,0x44);
      return 1;
    }
  }
  return 0;
}


