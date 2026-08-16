// 6006988c  adapter__6006988c  size=194 bytes
// src: adapter.cc
// --- callers ---
// --- callees ---
//   600d8994 FUN_600d8994
//   600d37b8 FUN_600d37b8
//   6010165c FUN_6010165c
//   60101832 FUN_60101832
//   60051120 FUN_60051120
//   600d37ac FUN_600d37ac


/* src: adapter.cc */

void adapter__6006988c(int param_1,undefined1 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined1 auStack_b4 [8];
  undefined1 auStack_ac [152];
  
  iVar2 = FUN_600d8994(param_1 + 0x110);
  if (iVar2 == 0) {
    FUN_6010165c(0x28,DAT_60069954,0x321,DAT_60069958,DAT_60069950);
  }
  else {
    *(undefined4 *)(param_1 + 0x1e70) = *(undefined4 *)(param_1 + 0x140);
    iVar3 = *(int *)(param_1 + 0x1ab4);
    iVar2 = *(int *)(param_1 + 0x1ab8) * 0x1994 + iVar3;
    for (; iVar2 != iVar3; iVar3 = iVar3 + 0x1994) {
      *(undefined1 *)(iVar3 + 0x248) = param_2;
    }
    puVar5 = (undefined4 *)(param_1 + 0x144);
    for (uVar4 = 0; uVar4 < *(uint *)(param_1 + 0x140); uVar4 = uVar4 + 1) {
      cVar1 = (*(code *)**(undefined4 **)*puVar5)((undefined4 *)*puVar5,param_1 + 0x13c);
      if (cVar1 != '\0') {
        FUN_60051120(auStack_b4,DAT_60069954,0x32b);
        FUN_600d37ac(auStack_ac,DAT_6006995c);
        FUN_600d37b8(auStack_b4);
        break;
      }
      puVar5 = puVar5 + 1;
    }
    if ((*(int *)(param_1 + 0x1e6c) == 0) && (*(int *)(param_1 + 0x1e70) == 0)) {
      FUN_6010165c(0x28,DAT_60069954,0x32e,DAT_60069960);
      FUN_60101832(param_1 + 0x1e78);
    }
  }
  return;
}


