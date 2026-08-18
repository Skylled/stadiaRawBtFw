// 600cf876  FUN_600cf876  size=52 bytes
// --- callers ---
//   600605dc sai__600605dc
// --- callees ---
//   600cf65e FUN_600cf65e


void FUN_600cf876(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined1 uVar1;
  
  FUN_600cf65e(param_1,param_3,param_4,param_5);
  if (*(uint *)(param_3 + 4) == 0x18) {
    uVar1 = 4;
  }
  else {
    uVar1 = (undefined1)(*(uint *)(param_3 + 4) >> 3);
  }
  *(undefined1 *)(param_2 + 5) = uVar1;
  *(undefined1 *)(param_2 + 6) = *(undefined1 *)(param_3 + 0x11);
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfff0ffff;
  *(char *)(param_2 + 7) = ' ' - *(char *)(param_3 + 0x10);
  return;
}


