// 600dc216  FUN_600dc216  size=50 bytes
// --- callers ---
//   6007b9d4 FUN_6007b9d4
//   6007c4c8 FUN_6007c4c8
//   6007ba54 FUN_6007ba54
//   6007c3e0 FUN_6007c3e0
// --- callees ---
//   60101fd8 FUN_60101fd8


uint FUN_600dc216(int *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1[1] - *param_1 >> 2;
  if (param_2 <= 0x3fffffff - uVar2) {
    if (param_2 < uVar2) {
      param_2 = uVar2;
    }
    uVar1 = 0x3fffffff;
    if ((!CARRY4(uVar2,param_2)) && (uVar1 = uVar2 + param_2, 0x3ffffffe < uVar2 + param_2)) {
      uVar1 = 0x3fffffff;
    }
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_60101fd8(param_3);
}


