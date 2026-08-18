// 600cec26  FUN_600cec26  size=144 bytes
// --- callers ---
//   600cf8de FUN_600cf8de
// --- callees ---


void FUN_600cec26(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 param_4,
                 uint param_5,uint param_6,uint param_7,char param_8)

{
  undefined1 uVar1;
  
  *param_1 = param_2;
  param_1[1] = param_4;
  param_1[4] = param_6;
  param_1[5] = param_7 / param_6;
  if (param_3 == 4) {
    uVar1 = 2;
LAB_600cec74:
    *(undefined1 *)(param_1 + 2) = uVar1;
  }
  else {
    if (4 < param_3) {
      if (param_3 == 0x10) {
        uVar1 = 4;
      }
      else {
        if (param_3 != 0x20) goto LAB_600cec4c;
        uVar1 = 5;
      }
      goto LAB_600cec74;
    }
    if (param_3 == 1) {
      uVar1 = 0;
      goto LAB_600cec74;
    }
    if (param_3 == 2) {
      uVar1 = 1;
      goto LAB_600cec74;
    }
  }
LAB_600cec4c:
  if (param_5 == 4) {
    uVar1 = 2;
  }
  else if (param_5 < 5) {
    if (param_5 == 1) {
      uVar1 = 0;
    }
    else {
      if (param_5 != 2) goto LAB_600cec5a;
      uVar1 = 1;
    }
  }
  else if (param_5 == 0x10) {
    uVar1 = 4;
  }
  else {
    if (param_5 != 0x20) goto LAB_600cec5a;
    uVar1 = 5;
  }
  *(undefined1 *)((int)param_1 + 9) = uVar1;
LAB_600cec5a:
  if (param_8 == '\x01') {
    *(short *)(param_1 + 3) = (short)param_5;
    *(undefined2 *)((int)param_1 + 10) = 0;
  }
  else {
    if (param_8 == '\0') {
      *(short *)(param_1 + 3) = (short)param_5;
    }
    else {
      if (param_8 != '\x02') {
        return;
      }
      *(undefined2 *)(param_1 + 3) = 0;
    }
    *(short *)((int)param_1 + 10) = (short)param_3;
  }
  return;
}


