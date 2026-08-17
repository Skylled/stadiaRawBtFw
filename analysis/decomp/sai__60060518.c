// 60060518  sai__60060518  size=94 bytes
// src: sai.cc
// --- callers ---
//   600718e8 FUN_600718e8
// --- callees ---
//   6013d1d0 thunk_EXT_FUN_0000080c
//   601016a2 FUN_601016a2


/* src: sai.cc */

void sai__60060518(char *param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  undefined4 uVar3;
  
  uVar3 = DAT_60060584;
  uVar1 = DAT_6006057c;
  if (*param_1 == '\0') {
    *DAT_60060578 = *DAT_60060578 & 0xfffff3ff | 0x800;
    puVar2 = DAT_60060580;
    *DAT_60060580 = *DAT_60060580 & 0xfffffe3f;
    *puVar2 = *puVar2 | 0x3f;
    uVar3 = uVar1;
  }
  else {
    if (*param_1 != '\x01') {
      FUN_601016a2(DAT_60060590,0x5c,DAT_6006058c);
      return;
    }
    *DAT_60060578 = *DAT_60060578 & 0xffffcfff | 0x2000;
    puVar2 = DAT_60060588;
    *DAT_60060588 = *DAT_60060588 & 0xfffffe3f;
    *puVar2 = *puVar2 | 0x3f;
  }
  thunk_EXT_FUN_0000080c(uVar3,1);
  return;
}


