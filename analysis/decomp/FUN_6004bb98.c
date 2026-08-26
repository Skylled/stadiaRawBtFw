// 6004bb98  FUN_6004bb98  size=102 bytes
// --- callers ---
//   600473e4 queue__600473e4
//   60047290 queue__60047290
// --- callees ---
//   60048014 tasks__60048014
//   6004bd8e FUN_6004bd8e


undefined4 FUN_6004bb98(uint *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1[0xe];
  if (param_1[0x10] == 0) {
    if (*param_1 == 0) {
      uVar1 = tasks__60048014(param_1[1]);
      param_1[1] = 0;
      goto LAB_6004bbb0;
    }
  }
  else if (param_3 == 0) {
    FUN_6004bd8e(param_1[2]);
    uVar2 = param_1[2];
    param_1[2] = uVar2 + param_1[0x10];
    if (param_1[1] <= uVar2 + param_1[0x10]) {
      param_1[2] = *param_1;
    }
  }
  else {
    FUN_6004bd8e(param_1[3]);
    uVar2 = param_1[3] + -param_1[0x10];
    param_1[3] = uVar2;
    if (uVar2 < *param_1) {
      param_1[3] = -param_1[0x10] + param_1[1];
    }
    if (param_3 == 2) {
      if (uVar3 == 0) {
        uVar1 = 0;
        goto LAB_6004bbb0;
      }
      uVar3 = uVar3 - 1;
    }
  }
  uVar1 = 0;
LAB_6004bbb0:
  param_1[0xe] = uVar3 + 1;
  return uVar1;
}


