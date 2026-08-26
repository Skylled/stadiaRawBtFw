// 60101198  FUN_60101198  size=252 bytes
// --- callers ---
//   600d71c8 FUN_600d71c8
//   600d71a6 FUN_600d71a6
//   600d6ea8 FUN_600d6ea8
//   60066ba8 keys__60066ba8
//   600d722e FUN_600d722e
//   6006615c keys__6006615c
//   600d7184 FUN_600d7184
//   6005d714 trigger_bug_report__6005d714
//   600d7140 FUN_600d7140
//   6005b1c0 application_state__6005b1c0
//   600d71ea FUN_600d71ea
//   60061cc8 persistent_crash_register__60061cc8
//   600d720c FUN_600d720c
//   600d7162 FUN_600d7162
//   60051240 main__60051240
//   600d7250 FUN_600d7250
// --- callees ---
//   60100e08 FUN_60100e08
//   6013cef0 thunk_EXT_FUN_0000887a
//   60100e78 FUN_60100e78
//   60100b6a FUN_60100b6a
//   600cb428 key_value_store__600cb428
//   600db002 FUN_600db002
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   60100ffc FUN_60100ffc
//   60100b38 FUN_60100b38
//   60100be2 FUN_60100be2
//   600cb2fc key_value_store__600cb2fc
//   60100c48 FUN_60100c48


uint FUN_60101198(undefined4 *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *local_24 [2];
  
  if ((((param_2 == 0) || (param_3 == 0)) || (uVar1 = FUN_600db002(param_2,0x10), 0xe < uVar1 - 1))
     || (0xff0 < param_4)) {
    return 3;
  }
  local_24[0] = param_1 + 1;
  thunk_EXT_FUN_0000b4c2();
  if (*(char *)(param_1 + 0x16) == '\0') {
    uVar5 = 9;
    goto LAB_601011de;
  }
  iVar2 = FUN_60100e78(param_1,param_2);
  if (iVar2 != 100) {
    uVar5 = FUN_60100ffc(param_1,iVar2,param_3,param_4,0);
    goto LAB_601011de;
  }
  uVar3 = FUN_60100b6a(param_1,uVar1 & 0xffff,param_4);
  iVar2 = FUN_60100e08(param_1,uVar3);
  if (iVar2 == -1) {
LAB_60101222:
    uVar5 = 8;
  }
  else {
    uVar5 = FUN_60100b38(*param_1);
    if ((1 < uVar5) && (iVar4 = FUN_60100be2(param_1,iVar2), iVar4 != 0)) {
      uVar5 = key_value_store__600cb428(param_1);
      if ((uVar5 & 0xff) != 0) goto LAB_601011de;
      uVar3 = FUN_60100b6a(param_1,uVar1 & 0xffff,param_4);
      iVar2 = FUN_60100e08(param_1,uVar3);
      if ((iVar2 == -1) || (iVar4 = FUN_60100be2(param_1,iVar2), iVar4 != 0)) goto LAB_60101222;
    }
    uVar5 = FUN_60100c48(param_1,iVar2,param_2,param_3,param_4,0);
    if ((uVar5 & 0xff) == 0) {
      uVar5 = key_value_store__600cb2fc(param_1,param_2,iVar2,param_4,0);
    }
  }
LAB_601011de:
  thunk_EXT_FUN_0000887a(local_24);
  return uVar5;
}


