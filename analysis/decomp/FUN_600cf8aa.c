// 600cf8aa  FUN_600cf8aa  size=52 bytes
// --- callers ---
//   600606b0 sai__600606b0
// --- callees ---
//   600cf6fc FUN_600cf6fc


void FUN_600cf8aa(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined1 uVar1;
  
  FUN_600cf6fc(param_1,param_3,param_4,param_5);
  if (*(uint *)(param_3 + 4) == 0x18) {
    uVar1 = 4;
  }
  else {
    uVar1 = (undefined1)(*(uint *)(param_3 + 4) >> 3);
  }
  *(undefined1 *)(param_2 + 5) = uVar1;
  *(undefined1 *)(param_2 + 6) = *(undefined1 *)(param_3 + 0x11);
  *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) & 0xfff0ffff;
  *(undefined1 *)(param_2 + 7) = *(undefined1 *)(param_3 + 0x10);
  return;
}


