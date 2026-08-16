// 60069570  adapter__60069570  size=98 bytes
// src: adapter.cc
// --- callers ---
// --- callees ---
//   600d3b3a FUN_600d3b3a
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600d37ac FUN_600d37ac
//   60101740 FUN_60101740


/* src: adapter.cc */

undefined4 * adapter__60069570(undefined4 *param_1,short *param_2)

{
  undefined1 *puVar1;
  short *psVar2;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [144];
  short *psVar3;
  
  if (*param_2 == 2) {
    *(short *)(param_1 + 1) = param_2[2];
    *param_1 = 0;
  }
  else {
    if (*param_2 != 0x10) {
      local_a8 = DAT_600695d4;
      local_a4 = 0x203;
      FUN_600d3b3a(auStack_a0);
      FUN_600d37ac(auStack_a0,DAT_600695d8);
      FUN_60101740(&local_a8);
    }
    *param_1 = 1;
    thunk_EXT_FUN_0000b5ba(param_1 + 1,0,0x10);
    puVar1 = (undefined1 *)((int)param_1 + 3);
    psVar3 = param_2 + 2;
    do {
      psVar2 = (short *)((int)psVar3 + 1);
      puVar1 = puVar1 + 1;
      *puVar1 = (char)*psVar3;
      psVar3 = psVar2;
    } while (param_2 + 10 != psVar2);
  }
  return param_1;
}


