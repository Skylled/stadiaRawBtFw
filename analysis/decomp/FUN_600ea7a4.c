// 600ea7a4  FUN_600ea7a4  size=64 bytes
// --- callers ---
//   6008d7ac bcm__6008d7ac
//   600ea802 FUN_600ea802
//   60085528 FUN_60085528
//   6008ce00 FUN_6008ce00
//   60091580 ec_asn1__60091580
// --- callees ---
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600867c8 FUN_600867c8
//   600e92f0 FUN_600e92f0
//   600e6a22 FUN_600e6a22


void FUN_600ea7a4(int *param_1)

{
  int iVar1;
  
  if (((param_1 != (int *)0x0) && (param_1[7] == 0)) &&
     (iVar1 = FUN_600867c8(param_1 + 0x43), iVar1 != 0)) {
    if (*(code **)(*param_1 + 4) != (code *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
    if (param_1[1] != 0) {
      thunk_EXT_FUN_0000ac5e();
    }
    FUN_600e6a22(param_1 + 2);
    FUN_600e92f0(param_1[8]);
    thunk_EXT_FUN_0000ac5e(param_1);
    return;
  }
  return;
}


