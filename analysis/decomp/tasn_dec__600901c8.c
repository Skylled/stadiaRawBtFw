// 600901c8  tasn_dec__600901c8  size=278 bytes
// src: tasn_dec.c
// --- callers ---
//   6008fa18 tasn_dec__6008fa18
// --- callees ---
//   6008ffc0 tasn_dec__6008ffc0
//   6008f370 tasn_dec__6008f370
//   600e0552 FUN_600e0552
//   600eca08 FUN_600eca08
//   600ec740 FUN_600ec740


/* src: tasn_dec.c */

undefined4
tasn_dec__600901c8(int param_1,int *param_2,undefined4 param_3,uint *param_4,undefined1 param_5,
                  undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char local_32;
  char local_31;
  int local_30;
  int local_2c [2];
  
  if (param_1 == 0) {
    return 0;
  }
  local_2c[0] = *param_2;
  if ((*param_4 & 0x10) == 0) {
    uVar4 = tasn_dec__6008ffc0();
    return uVar4;
  }
  iVar1 = tasn_dec__6008f370(&local_30,0,0,&local_32,&local_31,local_2c,param_3,param_4[1],
                             *param_4 & 0xc0,param_5,param_6);
  iVar2 = local_2c[0];
  if (iVar1 == 0) {
    uVar4 = 0x23b;
  }
  else {
    if (iVar1 == -1) {
      return 0xffffffff;
    }
    if (local_31 == '\0') {
      uVar3 = 0x78;
      uVar4 = 0x240;
      goto LAB_6009023e;
    }
    iVar1 = tasn_dec__6008ffc0(param_1,local_2c,local_30,param_4,0,param_6,param_7);
    if (iVar1 != 0) {
      local_30 = local_30 - (local_2c[0] - iVar2);
      if (local_32 == '\0') {
        if (local_30 == 0) goto LAB_600902b0;
        uVar4 = 0x77;
        uVar3 = 0x256;
      }
      else {
        if ((1 < local_30) && (iVar2 = FUN_600ec740(local_2c), iVar2 != 0)) {
LAB_600902b0:
          *param_2 = local_2c[0];
          return 1;
        }
        uVar4 = 0x99;
        uVar3 = 0x24e;
      }
      FUN_600e0552(0xc,0,uVar4,DAT_600902e0,uVar3);
      FUN_600eca08(param_1,param_4);
      return 0;
    }
    uVar4 = 0x246;
  }
  uVar3 = 0x9e;
LAB_6009023e:
  FUN_600e0552(0xc,0,uVar3,DAT_600902e0,uVar4);
  return 0;
}


