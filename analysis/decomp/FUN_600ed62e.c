// 600ed62e  FUN_600ed62e  size=40 bytes
// --- callers ---
//   60091330 ec_asn1__60091330
// --- callees ---
//   600ed58a FUN_600ed58a
//   600ed556 FUN_600ed556


undefined4
FUN_600ed62e(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600ed58a(param_1,param_4,param_3,param_4,param_4);
  uVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = FUN_600ed556(param_1,param_2,param_4);
    if (iVar1 == 0) {
      return 0;
    }
    uVar2 = 1;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = uVar2;
  }
  return 1;
}


