// 600eb400  FUN_600eb400  size=40 bytes
// --- callers ---
//   60091580 ec_asn1__60091580
// --- callees ---
//   600eb3a4 FUN_600eb3a4


undefined4 FUN_600eb400(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == param_2) {
LAB_600eb41e:
    uVar1 = 0;
  }
  else {
    if (param_1[7] == param_2[7]) {
      if (param_1[7] != 0) goto LAB_600eb41e;
      if (*param_1 == *param_2) {
        uVar1 = FUN_600eb3a4();
        return uVar1;
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}


