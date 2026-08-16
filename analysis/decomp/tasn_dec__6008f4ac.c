// 6008f4ac  tasn_dec__6008f4ac  size=292 bytes
// src: tasn_dec.c
// --- callers ---
//   6008f4ac tasn_dec__6008f4ac
//   6008f794 tasn_dec__6008f794
// --- callees ---
//   600ecea2 thunk_FUN_600ece78
//   6008f370 tasn_dec__6008f370
//   600e0552 FUN_600e0552
//   6008f4ac tasn_dec__6008f4ac
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600ec740 FUN_600ec740


/* src: tasn_dec.c */

undefined4 tasn_dec__6008f4ac(int *param_1,int *param_2,int param_3,uint param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  char local_32;
  undefined1 local_31;
  int local_30;
  int local_2c [2];
  
  local_30 = *param_2;
  do {
    iVar1 = local_30;
    if (param_3 < 1) {
      if ((param_4 & 1) == 0) {
LAB_6008f5c6:
        uVar4 = 1;
        *param_2 = local_30;
      }
      else {
        uVar4 = 0x99;
        uVar6 = 0x45e;
LAB_6008f4f6:
        FUN_600e0552(0xc,0,uVar4,DAT_6008f5d0,uVar6);
        uVar4 = 0;
      }
      return uVar4;
    }
    if ((param_3 != 1) && (iVar2 = FUN_600ec740(&local_30), iVar2 != 0)) {
      if ((param_4 & 1) != 0) goto LAB_6008f5c6;
      uVar4 = 0xb4;
      uVar6 = 0x444;
      goto LAB_6008f4f6;
    }
    iVar3 = tasn_dec__6008f370(local_2c,0,0,&local_31,&local_32,&local_30,param_3,0xffffffff,0,0,0);
    iVar2 = local_2c[0];
    if (iVar3 == 0) {
      uVar4 = 0x9e;
      uVar6 = 0x44d;
LAB_6008f53a:
      FUN_600e0552(0xc,0,uVar4,DAT_6008f5d0,uVar6);
      return 0;
    }
    if (local_32 == '\0') {
      if (local_2c[0] != 0) {
        iVar5 = *param_1;
        iVar3 = thunk_FUN_600ece78(param_1,iVar5 + local_2c[0]);
        if (iVar3 == 0) {
          uVar4 = 0x41;
          uVar6 = 0x46b;
          goto LAB_6008f53a;
        }
        thunk_EXT_FUN_0000b572(param_1[1] + iVar5,local_30,iVar2);
        local_30 = local_30 + iVar2;
      }
    }
    else {
      if (param_5 == 5) {
        uVar4 = 0x9f;
        uVar6 = 0x454;
        goto LAB_6008f4f6;
      }
      iVar2 = tasn_dec__6008f4ac(param_1,&local_30,local_2c[0],local_31,param_5 + 1);
      if (iVar2 == 0) {
        return 0;
      }
    }
    param_3 = param_3 - (local_30 - iVar1);
  } while( true );
}


