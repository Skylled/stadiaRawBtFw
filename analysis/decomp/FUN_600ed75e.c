// 600ed75e  FUN_600ed75e  size=24 bytes
// --- callers ---
//   60091ddc FUN_60091ddc
// --- callees ---
//   600ed656 FUN_600ed656
//   600ed42c FUN_600ed42c


undefined4 FUN_600ed75e(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600ed42c();
  uVar2 = 0;
  if ((iVar1 != 0) && (iVar1 = FUN_600ed656(*param_2), uVar2 = 0, iVar1 != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}


