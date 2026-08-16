// 6008ce70  bcm__6008ce70  size=66 bytes
// src: bcm.c
// --- callers ---
//   6008d120 bcm__6008d120
//   6008d300 bcm__6008d300
// --- callees ---
//   600e0552 FUN_600e0552
//   600e7554 FUN_600e7554


/* src: bcm.c */

undefined4 bcm__6008ce70(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_3 + 0xc) == 0) &&
     (iVar1 = FUN_600e7554(param_3,param_1 + 9,param_3,0,param_1,param_2), iVar1 < 0)) {
                    /* WARNING: Could not recover jumptable at 0x6008ce9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*param_1 + 0x2c))(param_1,param_2,param_3);
    return uVar2;
  }
  FUN_600e0552(0xf,0,0x65,DAT_6008ceb4,0x1b);
  return 0;
}


