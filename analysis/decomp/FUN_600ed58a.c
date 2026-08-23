// 600ed58a  FUN_600ed58a  size=42 bytes
// --- callers ---
//   600ed62e FUN_600ed62e
//   60091330 ec_asn1__60091330
//   60091580 ec_asn1__60091580
// --- callees ---
//   60090f78 FUN_60090f78


bool FUN_600ed58a(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  int local_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  if (param_1[1] == 0) {
    bVar2 = false;
  }
  else {
    local_10 = *param_1;
    uStack_c = param_1[1];
    local_14 = param_2;
    iVar1 = FUN_60090f78(&local_10,&local_14,param_3,&local_10,param_1);
    bVar2 = false;
    if (iVar1 != 0) {
      bVar2 = local_14 == param_2;
    }
  }
  return bVar2;
}


