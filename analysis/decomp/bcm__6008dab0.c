// 6008dab0  bcm__6008dab0  size=82 bytes
// src: bcm.c
// --- callers ---
//   60085528 FUN_60085528
// --- callees ---
//   600eb450 FUN_600eb450
//   600ea802 FUN_600ea802
//   600e0552 FUN_600e0552
//   600eb428 FUN_600eb428


/* src: bcm.c */

bool bcm__6008dab0(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (*param_1 == 0) {
    uVar2 = 0x72;
    uVar3 = 0x10a;
  }
  else {
    if ((param_2 == (undefined4 *)0x0) ||
       (iVar1 = FUN_600eb428(*param_1,*param_2,param_3,param_4,param_1,param_2), iVar1 == 0)) {
      FUN_600ea802(param_1[1]);
      iVar1 = FUN_600eb450(param_2,*param_1);
      param_1[1] = iVar1;
      return iVar1 != 0;
    }
    uVar2 = 0x82;
    uVar3 = 0x10f;
  }
  FUN_600e0552(0xf,0,uVar2,DAT_6008db04,uVar3);
  return false;
}


