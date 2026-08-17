// 60083534  private_heap__60083534  size=42 bytes
// src: private_heap.cc
// --- callers ---
//   600835ac private_heap__600835ac
//   600dfd7e FUN_600dfd7e
//   60055704 FUN_60055704
// --- callees ---
//   601016a2 FUN_601016a2
//   600dfd6a FUN_600dfd6a


/* src: private_heap.cc */

int private_heap__60083534(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) == -1) {
    param_1 = 0;
  }
  else {
    iVar1 = FUN_600dfd6a();
    if (*(int *)(param_1 + 0xc) != iVar1) {
      FUN_601016a2(DAT_60083564,0x23,DAT_60083560);
    }
    param_1 = *(int *)(param_1 + 4) + 0x10 + param_1;
  }
  return param_1;
}


