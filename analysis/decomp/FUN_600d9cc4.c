// 600d9cc4  FUN_600d9cc4  size=152 bytes
// --- callers ---
//   600723b4 FUN_600723b4
// --- callees ---
//   60071478 FUN_60071478


int FUN_600d9cc4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,uint param_8,
                undefined1 param_9,undefined4 param_10,undefined1 *param_11,undefined1 *param_12,
                undefined1 *param_13,undefined4 *param_14)

{
  undefined2 uVar1;
  
  FUN_60071478(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,*param_11,
               *param_12,*param_13,*param_14);
  switch(param_7) {
  case 1:
    if (param_8 < 0x10) {
      uVar1 = 0x50;
    }
    else {
      uVar1 = 0x51;
    }
    break;
  case 2:
    if (param_8 < 0x10) {
      uVar1 = 0x52;
    }
    else {
      uVar1 = 0x53;
    }
    break;
  case 3:
    if (param_8 < 0x10) {
      uVar1 = 0x54;
    }
    else {
      uVar1 = 0x55;
    }
    break;
  case 4:
    if (param_8 < 0x10) {
      uVar1 = 0x56;
    }
    else {
      uVar1 = 0x57;
    }
    break;
  case 5:
    if (param_8 < 0x10) {
      uVar1 = 0x58;
    }
    else {
      uVar1 = 0x59;
    }
    break;
  default:
    uVar1 = 0xff80;
  }
  *(undefined2 *)(param_1 + 0x2c) = uVar1;
  *(uint *)(param_1 + 0x38) = param_8;
  *(undefined4 *)(param_1 + 0x30) = 5;
  *(undefined4 *)(param_1 + 0x34) = param_7;
  return param_1;
}


