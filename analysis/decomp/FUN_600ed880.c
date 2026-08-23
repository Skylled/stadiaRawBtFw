// 600ed880  FUN_600ed880  size=310 bytes
// --- callers ---
//   60085f2c pem_lib__60085f2c
// --- callees ---
//   6013d020 thunk_EXT_FUN_0000b070
//   600ea72a FUN_600ea72a
//   6013d298 thunk_EXT_FUN_0000b08e
//   6013d0d8 thunk_EXT_FUN_0000b068
//   6008cb7c bcm__6008cb7c
//   6013cfb0 thunk_EXT_FUN_0000ac52


int FUN_600ed880(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                uint param_6,undefined1 *param_7,undefined1 *param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int local_7c;
  undefined1 auStack_78 [16];
  undefined1 local_68 [68];
  
  iVar4 = 0;
  iVar3 = *(int *)(param_1 + 8);
  local_7c = 0;
  if (param_4 == 0) {
    return iVar3;
  }
  iVar5 = *(int *)(param_1 + 0xc);
  thunk_EXT_FUN_0000b068(auStack_78);
  while( true ) {
    iVar1 = bcm__6008cb7c(auStack_78,param_2,0);
    if (iVar1 == 0) {
      return 0;
    }
    if (((((iVar4 != 0) &&
          (iVar1 = thunk_EXT_FUN_0000b08e(auStack_78,local_68,local_7c), iVar1 == 0)) ||
         (iVar1 = thunk_EXT_FUN_0000b08e(auStack_78,param_4,param_5), iVar1 == 0)) ||
        ((param_3 != 0 && (iVar1 = thunk_EXT_FUN_0000b08e(auStack_78,param_3,8), iVar1 == 0)))) ||
       (iVar1 = FUN_600ea72a(auStack_78,local_68,&local_7c), iVar1 == 0)) break;
    for (uVar6 = 1; uVar6 < param_6; uVar6 = uVar6 + 1) {
      iVar1 = bcm__6008cb7c(auStack_78,param_2,0);
      if (((iVar1 == 0) ||
          (iVar1 = thunk_EXT_FUN_0000b08e(auStack_78,local_68,local_7c), iVar1 == 0)) ||
         (iVar1 = FUN_600ea72a(auStack_78,local_68,&local_7c), iVar1 == 0)) goto LAB_600ed8ce;
    }
    if (iVar3 != 0) {
      iVar1 = 0;
      do {
        iVar2 = iVar3 - iVar1;
        if (local_7c == iVar1) {
          if ((iVar5 != 0) || (iVar2 != 0)) goto LAB_600ed9a4;
          goto LAB_600ed95c;
        }
        if (param_7 != (undefined1 *)0x0) {
          *param_7 = local_68[iVar1];
          param_7 = param_7 + 1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar3 != iVar1);
    }
    while( true ) {
      if (iVar5 == 0) goto LAB_600ed95c;
      if (local_7c == iVar3) break;
      if (param_8 != (undefined1 *)0x0) {
        *param_8 = local_68[iVar3];
        param_8 = param_8 + 1;
      }
      iVar5 = iVar5 + -1;
      iVar3 = iVar3 + 1;
    }
    iVar2 = 0;
LAB_600ed9a4:
    iVar4 = iVar4 + 1;
    iVar3 = iVar2;
  }
LAB_600ed8ce:
  iVar3 = 0;
LAB_600ed8d0:
  thunk_EXT_FUN_0000b070(auStack_78);
  thunk_EXT_FUN_0000ac52(local_68,0x40);
  return iVar3;
LAB_600ed95c:
  iVar3 = *(int *)(param_1 + 8);
  goto LAB_600ed8d0;
}


