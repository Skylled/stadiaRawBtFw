// 60083568  private_heap__60083568  size=56 bytes
// src: private_heap.cc
// --- callers ---
//   600835ac private_heap__600835ac
//   60055704 FUN_60055704
// --- callees ---
//   601016a2 FUN_601016a2
//   600dfd6a FUN_600dfd6a


/* src: private_heap.cc */

void private_heap__60083568(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 8) != 0x10) && (*(int *)(param_1 + 8) != 1)) {
    FUN_601016a2(DAT_600835a4,0x3c,DAT_600835a0,param_1);
  }
  iVar1 = FUN_600dfd6a(param_1);
  if (*(int *)(param_1 + 0xc) != iVar1) {
    FUN_601016a2(DAT_600835a4,0x3f,DAT_600835a8,param_1);
    return;
  }
  return;
}


