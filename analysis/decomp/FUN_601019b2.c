// 601019b2  FUN_601019b2  size=40 bytes
// --- callers ---
//   6005dafc FUN_6005dafc
// --- callees ---
//   60101984 FUN_60101984


void FUN_601019b2(int param_1,uint param_2)

{
  undefined1 uVar1;
  
  if ((int)param_2 < 0) {
    uVar1 = 3;
  }
  else {
    if (param_2 < *(int *)(param_1 + 4) + 1U) {
      uVar1 = 0;
      *(uint *)(param_1 + 8) = param_2;
      goto LAB_601019c6;
    }
    uVar1 = 8;
  }
  FUN_60101984(param_1);
LAB_601019c6:
  *(undefined1 *)(param_1 + 0xc) = uVar1;
  *(undefined1 *)(param_1 + 0xd) = uVar1;
  return;
}


