// 60066284  keys__60066284  size=74 bytes
// src: keys.cc
// --- callers ---
//   600d74ce FUN_600d74ce
//   600d6e3c FUN_600d6e3c
// --- callees ---
//   60065ccc FUN_60065ccc
//   60101740 FUN_60101740
//   600ce2a0 FUN_600ce2a0


/* src: keys.cc */

undefined4 * keys__60066284(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_a8 [156];
  
  iVar2 = FUN_60065ccc(param_2);
  if (iVar2 == DAT_600662d0) {
    FUN_600ce2a0(auStack_a8,DAT_600662d8,DAT_600662d4,0x235);
    FUN_60101740(auStack_a8);
  }
  if (*(byte *)(iVar2 + 0xc) < 0xc) {
    iVar3 = (int)*(char *)(DAT_600662dc + (uint)*(byte *)(iVar2 + 0xc));
  }
  else {
    iVar3 = 0;
  }
  cVar1 = *(char *)(iVar2 + 0xf);
  *param_1 = *(undefined4 *)(iVar2 + 8);
  param_1[1] = iVar3;
  *(bool *)(param_1 + 2) = cVar1 == '\x01';
  return param_1;
}


