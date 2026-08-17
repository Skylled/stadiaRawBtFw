// 600606b0  sai__600606b0  size=78 bytes
// src: sai.cc
// --- callers ---
// --- callees ---
//   600d4d56 FUN_600d4d56
//   6010165c FUN_6010165c
//   600cf8aa FUN_600cf8aa
//   60060500 FUN_60060500


/* src: sai.cc */

void sai__600606b0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  
  if (*(char *)(param_1 + 0x3e) == '\0') {
    FUN_6010165c(0x1e,DAT_60060704,0xe3,DAT_60060700);
    return;
  }
  puVar3 = param_1;
  uVar2 = FUN_600d4d56(*param_1);
  uVar1 = FUN_60060500(*(undefined1 *)*param_1,(int)((ulonglong)uVar2 >> 0x20),
                       (undefined1 *)*param_1 + 0xe4,(int)uVar2,puVar3,param_2,param_3);
  FUN_600cf8aa(uVar1,param_1 + 4);
  FUN_60060500(*(undefined1 *)*param_1);
  FUN_600cfa22();
  thunk_EXT_FUN_0000b5ba(param_1 + 9,0,0xa0);
  thunk_EXT_FUN_0000b5ba(param_1 + 0x31,0,0x20);
  thunk_EXT_FUN_0000b5ba(param_1 + 0x39,0,0x10);
  *(undefined1 *)(param_1 + 0x3d) = 0;
  *(undefined1 *)((int)param_1 + 0xf5) = 0;
  return;
}


