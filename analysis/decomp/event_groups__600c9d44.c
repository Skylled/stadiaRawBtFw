// 600c9d44  event_groups__600c9d44  size=60 bytes
// src: event_groups.c
// --- callers ---
//   6006e854 FUN_6006e854
//   600765a4 FUN_600765a4
//   60055730 FUN_60055730
//   6005cd20 FUN_6005cd20
// --- callees ---
//   601016a2 FUN_601016a2
//   6013d060 thunk_EXT_FUN_0000b2e8


/* WARNING: Removing unreachable block (ram,0x600c9d5e) */
/* src: event_groups.c */

undefined4 *
event_groups__600c9d44(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 == (undefined4 *)0x0) {
    FUN_601016a2(DAT_600c9d84,0x62,DAT_600c9d80,param_4,0,param_2);
  }
  else {
    *param_1 = 0;
    thunk_EXT_FUN_0000b2e8(param_1 + 1);
    *(undefined1 *)(param_1 + 7) = 1;
  }
  return param_1;
}


