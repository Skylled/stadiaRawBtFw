// 600ec6fc  FUN_600ec6fc  size=36 bytes
// --- callers ---
// --- callees ---
//   6008f2c0 asn1_lib__6008f2c0


undefined4 FUN_600ec6fc(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_2 != (undefined4 *)0x0) {
    uVar3 = param_2[1];
    uVar2 = *param_2;
    *(undefined4 *)(param_1 + 4) = uVar3;
    iVar1 = asn1_lib__6008f2c0(param_1,param_2[2],uVar2,uVar3,param_4);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0xc) = param_2[3];
      return 1;
    }
  }
  return 0;
}


