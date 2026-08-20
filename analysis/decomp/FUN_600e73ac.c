// 600e73ac  FUN_600e73ac  size=102 bytes
// --- callers ---
//   6008c334 bcm__6008c334
// --- callees ---
//   6013cee8 thunk_EXT_FUN_0000af90
//   600e1e54 FUN_600e1e54
//   6008b43c bcm__6008b43c


undefined4 FUN_600e73ac(int *param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int extraout_r2;
  
  iVar1 = bcm__6008b43c();
  uVar2 = 0;
  if (iVar1 != 0) {
    thunk_EXT_FUN_0000af90(*param_1,0,param_2 * 4);
    uVar3 = 0;
    while ((int)uVar3 < 1 << (param_5 & 0xff)) {
      uVar3 = FUN_600e1e54(uVar3 ^ param_4);
      for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
        *(uint *)(*param_1 + iVar1 * 4) =
             *(uint *)(*param_1 + iVar1 * 4) | uVar3 & *(uint *)(param_3 + iVar1 * 4);
      }
      param_3 = param_3 + param_2 * 4;
      uVar3 = extraout_r2 + 1;
    }
    uVar2 = 1;
    param_1[1] = param_2;
  }
  return uVar2;
}


