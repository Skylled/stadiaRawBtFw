// 6010112c  FUN_6010112c  size=108 bytes
// --- callers ---
//   600661fc keys__600661fc
//   60061cc8 persistent_crash_register__60061cc8
// --- callees ---
//   6013cef0 thunk_EXT_FUN_0000887a
//   60100e78 FUN_60100e78
//   600db002 FUN_600db002
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   60100ffc FUN_60100ffc


undefined4 FUN_6010112c(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_14 [2];
  
  if ((param_2 == 0) || (iVar1 = FUN_600db002(param_2,0x10), 0xe < iVar1 - 1U)) {
    uVar2 = 3;
  }
  else {
    local_14[0] = param_1 + 4;
    thunk_EXT_FUN_0000b4c2();
    if (*(char *)(param_1 + 0x58) == '\0') {
      uVar2 = 9;
    }
    else {
      iVar1 = FUN_60100e78(param_1,param_2);
      if ((iVar1 == 100) || (*(char *)(iVar1 * 0x18 + param_1 + 0x16e) != '\0')) {
        uVar2 = 5;
      }
      else {
        uVar2 = FUN_60100ffc(param_1,iVar1,0,0,1);
      }
    }
    thunk_EXT_FUN_0000887a(local_14);
  }
  return uVar2;
}


