// 6004820c  FUN_6004820c  size=50 bytes
// --- callers ---
//   600482a8 FUN_600482a8
// --- callees ---
//   6004bb32 FUN_6004bb32


undefined4 FUN_6004820c(int param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  
  *(uint *)(param_1 + 4) = param_2;
  *(int *)(param_1 + 0x10) = param_1;
  if (param_3 < param_2) {
    puVar1 = DAT_60048244;
    if ((param_3 < param_4) && (param_4 <= param_2)) {
      return 1;
    }
  }
  else {
    param_3 = param_3 - param_4;
    puVar1 = DAT_60048240;
    if (*(uint *)(param_1 + 0x18) <= param_3) {
      return 1;
    }
  }
  FUN_6004bb32(*puVar1,param_1 + 4,param_3,puVar1,param_4);
  return 0;
}


