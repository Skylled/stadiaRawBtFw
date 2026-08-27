// 6005f8c0  FUN_6005f8c0  size=140 bytes
// --- callers ---
//   600cbebc logger__600cbebc
//   600cc124 FUN_600cc124
// --- callees ---
//   60061cc8 persistent_crash_register__60061cc8
//   6013d088 thunk_EXT_FUN_00007734
//   6005ea2c FUN_6005ea2c
//   60061c1c FUN_60061c1c
//   600d4d2e FUN_600d4d2e
//   60061bb0 FUN_60061bb0
//   6005e884 FUN_6005e884
//   600d51c2 FUN_600d51c2
//   6005f664 FUN_6005f664


void FUN_6005f8c0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int unaff_r4;
  undefined8 uVar6;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined1 auStack_6c [104];
  
  local_70 = 0;
  local_78 = 0;
  uStack_74 = 0;
  FUN_6005f664(0x1b,0,&local_78,param_2,param_3);
  FUN_60061bb0(DAT_6005f94c,0x1b,&local_78);
  FUN_600d51c2(DAT_6005f94c,auStack_6c,100);
  iVar2 = thunk_EXT_FUN_00007734();
  if (iVar2 != 2) goto LAB_6005f940;
  if ((*(uint *)(DAT_6005f950 + 4) & 0x1ff) != 0) goto LAB_6005f940;
  FUN_6005e884(auStack_6c);
  cVar1 = FUN_6005ea2c();
  if (cVar1 != '\0') goto LAB_6005f940;
  iVar3 = *(int *)(DAT_6005f954 + 0x437c);
  unaff_r4 = *(int *)(DAT_6005f954 + 0x4378);
  iVar2 = 0;
  do {
    if (iVar3 == iVar2) {
      iVar2 = 0;
LAB_6005f934:
      persistent_crash_register__60061cc8(DAT_6005f94c,iVar2);
      FUN_60061c1c(DAT_6005f94c);
LAB_6005f940:
      uVar6 = FUN_600d4d2e();
    }
    else {
      piVar5 = *(int **)(unaff_r4 + iVar2 * 4);
      iVar4 = *piVar5;
      uVar6 = CONCAT44(iVar3,iVar2);
      if ((*(char *)(iVar4 + 8) == '\t') &&
         (uVar6 = CONCAT44(iVar3,iVar2), *(char *)(iVar4 + 9) == '\x01')) {
        iVar2 = piVar5[2];
        goto LAB_6005f934;
      }
    }
    iVar3 = (int)((ulonglong)uVar6 >> 0x20);
    iVar2 = (int)uVar6 + 1;
  } while( true );
}


