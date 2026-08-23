// 600ed73c  FUN_600ed73c  size=34 bytes
// --- callers ---
// --- callees ---
//   600ed656 FUN_600ed656
//   6013d148 thunk_EXT_FUN_0000b09a


undefined4
FUN_600ed73c(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  undefined4 uStack_c;
  
  uStack_c = param_2;
  iVar1 = thunk_EXT_FUN_0000b09a(param_1,(int)&uStack_c + 2,param_3,param_4,param_1);
  uVar2 = 0;
  if ((iVar1 != 0) && (iVar1 = FUN_600ed656(uStack_c._2_2_), uVar2 = 0, iVar1 != 0)) {
    uVar2 = 1;
    *param_2 = extraout_r2;
  }
  return uVar2;
}


