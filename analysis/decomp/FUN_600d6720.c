// 600d6720  FUN_600d6720  size=48 bytes
// --- callers ---
//   600d6750 FUN_600d6750
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


uint FUN_600d6720(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_2[1] - *param_2;
  uVar2 = param_1[1] - *param_1;
  uVar1 = uVar2;
  if (uVar3 <= uVar2) {
    uVar1 = uVar3;
  }
  if ((uVar1 == 0) || (uVar1 = thunk_EXT_FUN_0000b554(*param_1), uVar1 == 0)) {
    uVar1 = (uint)(uVar2 < uVar3);
  }
  else {
    uVar1 = uVar1 >> 0x1f;
  }
  return uVar1;
}


