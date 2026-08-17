// 60091098  dsa__60091098  size=64 bytes
// src: dsa.c
// --- callers ---
//   60091160 FUN_60091160
// --- callees ---
//   600e0c4a FUN_600e0c4a
//   600e092c FUN_600e092c
//   600edb24 FUN_600edb24
//   600e0552 FUN_600e0552
//   6013cf90 thunk_EXT_FUN_0000b5ba


/* src: dsa.c */

int dsa__60091098(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_600e092c(0x68);
  if (iVar1 == 0) {
    FUN_600e0552(10,0,0x41,DAT_600910d8,0x5d,param_2);
  }
  else {
    thunk_EXT_FUN_0000b5ba(iVar1,0,0x68);
    *(undefined4 *)(iVar1 + 0x60) = 1;
    FUN_600e0c4a(iVar1 + 0x20);
    FUN_600edb24(iVar1 + 100);
  }
  return iVar1;
}


