// 600c9d88  event_groups__600c9d88  size=68 bytes
// src: event_groups.c
// --- callers ---
//   6006e854 FUN_6006e854
//   6006e9b0 FUN_6006e9b0
//   600d15f8 FUN_600d15f8
// --- callees ---
//   601016a2 FUN_601016a2
//   6013d2d0 thunk_EXT_FUN_0000713c
//   6013d180 thunk_EXT_FUN_000080d8
//   6013d2a8 thunk_EXT_FUN_000075ec
//   6013d0e0 thunk_EXT_FUN_0000728c


/* src: event_groups.c */

void event_groups__600c9d88(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_600c9dd0;
  uVar1 = DAT_600c9dcc;
  thunk_EXT_FUN_0000713c();
  while (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 0x10) == param_1 + 0xc) {
      FUN_601016a2(uVar2,0x263,uVar1);
    }
    thunk_EXT_FUN_000075ec(*(undefined4 *)(param_1 + 0x10),0x2000000);
  }
  if (*(char *)(param_1 + 0x1c) == '\0') {
    thunk_EXT_FUN_000080d8(param_1);
  }
  thunk_EXT_FUN_0000728c();
  return;
}


