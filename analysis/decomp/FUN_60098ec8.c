// 60098ec8  FUN_60098ec8  size=104 bytes
// --- callers ---
//   600f045e FUN_600f045e
//   600f0406 FUN_600f0406
//   6009bf1c FUN_6009bf1c
//   600f0252 FUN_600f0252
//   6009a254 FUN_6009a254
//   600f1b72 FUN_600f1b72
//   60099dd0 FUN_60099dd0
//   60099fdc FUN_60099fdc
//   600a6d70 FUN_600a6d70
//   600a5760 FUN_600a5760
//   600b5844 FUN_600b5844
//   600f7ca0 FUN_600f7ca0
//   600f0910 FUN_600f0910
//   600f061a FUN_600f061a
//   6009ac8c FUN_6009ac8c
//   600f7b48 FUN_600f7b48
//   600f048a FUN_600f048a
//   600f103a FUN_600f103a
//   600f05da FUN_600f05da
//   6009a82c FUN_6009a82c
//   60099204 FUN_60099204
//   600f04ba FUN_600f04ba
//   600eff14 FUN_600eff14
//   600a59d0 FUN_600a59d0
//   60098f88 FUN_60098f88
//   6009931c FUN_6009931c
//   6009a1dc FUN_6009a1dc
//   600a44bc FUN_600a44bc
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


int FUN_60098ec8(int param_1,char param_2)

{
  int iVar1;
  ushort local_e;
  int local_c;
  
  local_c = DAT_60098f30;
  if (param_1 != 0) {
    for (local_e = 0; local_e < 4; local_e = local_e + 1) {
      if (((*(char *)(local_c + 0x128) != '\0') &&
          (iVar1 = thunk_EXT_FUN_0000b554(local_c + 6,param_1,6), iVar1 == 0)) &&
         (param_2 == *(char *)(local_c + 0x12e))) {
        return local_c;
      }
      local_c = local_c + 0x14c;
    }
  }
  return 0;
}


