// 600dfbac  FUN_600dfbac  size=102 bytes
// --- callers ---
//   6005a1b0 device_info__6005a1b0
// --- callees ---
//   60065dd8 FUN_60065dd8
//   600653f0 FUN_600653f0
//   6013d378 thunk_EXT_FUN_0000b532
//   60067d14 gotham__60067d14
//   60061964 FUN_60061964


undefined4 FUN_600dfbac(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int *local_1c;
  undefined4 uStack_18;
  
  uVar6 = param_1;
  local_1c = param_2;
  uStack_18 = param_3;
  piVar1 = (int *)FUN_600653f0();
  iVar5 = 0;
  do {
    if (piVar1[1] == iVar5) {
      iVar5 = 0;
LAB_600dfbd2:
      uVar2 = FUN_60065dd8(0x39);
      piVar1 = (int *)thunk_EXT_FUN_0000b532(0x1c);
      FUN_60061964(piVar1,iVar5,uVar2,0x800,uVar6);
      local_1c = piVar1;
      gotham__60067d14(param_1,&local_1c);
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 4))();
      }
      return param_1;
    }
    piVar4 = *(int **)(*piVar1 + iVar5 * 4);
    iVar3 = *piVar4;
    if ((*(char *)(iVar3 + 8) == '\x05') && (*(char *)(iVar3 + 9) == '\x01')) {
      iVar5 = piVar4[2];
      goto LAB_600dfbd2;
    }
    iVar5 = iVar5 + 1;
  } while( true );
}


