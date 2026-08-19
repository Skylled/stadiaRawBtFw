// 600d398a  FUN_600d398a  size=48 bytes
// --- callers ---
//   600593f4 FUN_600593f4
// --- callees ---
//   60050c18 FUN_60050c18
//   601019da FUN_601019da
//   60101ac8 FUN_60101ac8


int * FUN_600d398a(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_1[2];
  iVar1 = FUN_60101ac8();
  if (iVar1 != 0) {
    uVar2 = FUN_60050c18(param_2,0,param_1[2] + *param_1,param_1[1] - param_1[2]);
    FUN_601019da(param_1,uVar2,iVar3,0x5d);
  }
  return param_1;
}


