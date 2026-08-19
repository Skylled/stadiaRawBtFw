// 600d93a8  FUN_600d93a8  size=58 bytes
// --- callers ---
//   60096e38 FUN_60096e38
// --- callees ---
//   6006ea38 FUN_6006ea38
//   6006ea44 FUN_6006ea44
//   600d9380 FUN_600d9380


uint FUN_600d93a8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar3 = 100;
    while (iVar1 = FUN_6006ea38(), iVar1 != 1) {
      if (iVar3 == 0) {
        return 0;
      }
      iVar3 = iVar3 + -1;
      FUN_600d9380(5);
    }
    if ((iVar3 != 0) && (uVar2 = FUN_6006ea44(param_2,param_3), 0 < (int)uVar2)) {
      return uVar2 & 0xffff;
    }
  }
  return 0;
}


