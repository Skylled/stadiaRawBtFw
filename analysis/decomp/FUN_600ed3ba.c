// 600ed3ba  FUN_600ed3ba  size=28 bytes
// --- callers ---
//   60090f78 FUN_60090f78
//   600ed682 FUN_600ed682
//   60091330 ec_asn1__60091330
//   60091580 ec_asn1__60091580
//   600ed722 FUN_600ed722
//   600ed462 FUN_600ed462
//   600ed3d6 FUN_600ed3d6
// --- callees ---


bool FUN_600ed3ba(undefined4 *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  if (iVar2 != 0) {
    puVar1 = (undefined1 *)*param_1;
    param_1[1] = iVar2 + -1;
    *param_1 = puVar1 + 1;
    *param_2 = *puVar1;
  }
  return iVar2 != 0;
}


