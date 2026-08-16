// 600ca9e8  tasks__600ca9e8  size=156 bytes
// src: tasks.c
// --- callers ---
// --- callees ---
//   601016a2 FUN_601016a2
//   6013d188 thunk_EXT_FUN_0000b2fe
//   6013d140 thunk_EXT_FUN_0000b344


/* src: tasks.c */

void tasks__600ca9e8(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x54) == 0) {
      FUN_601016a2(DAT_600caa88,0x111c,DAT_600caa84);
    }
    if (param_2 < *(uint *)(param_1 + 0x50)) {
      param_2 = *(uint *)(param_1 + 0x50);
    }
    if ((*(uint *)(param_1 + 0x2c) != param_2) && (*(int *)(param_1 + 0x54) == 1)) {
      if (*DAT_600caa8c == param_1) {
        FUN_601016a2(DAT_600caa88,0x1137,DAT_600caa84);
      }
      iVar4 = *(int *)(param_1 + 0x2c);
      *(uint *)(param_1 + 0x2c) = param_2;
      if (-1 < *(int *)(param_1 + 0x18)) {
        *(uint *)(param_1 + 0x18) = 0x20 - param_2;
      }
      iVar1 = DAT_600caa90;
      if (*(int *)(param_1 + 0x14) == iVar4 * 0x14 + DAT_600caa90) {
        iVar4 = thunk_EXT_FUN_0000b344(param_1 + 4);
        puVar2 = DAT_600caa94;
        uVar3 = *(uint *)(param_1 + 0x2c);
        if ((iVar4 == 0) && (*(int *)(iVar1 + uVar3 * 0x14) == 0)) {
          *DAT_600caa94 = *DAT_600caa94 & ~(1 << (uVar3 & 0xff));
        }
        *puVar2 = 1 << (uVar3 & 0xff) | *puVar2;
        thunk_EXT_FUN_0000b2fe(uVar3 * 0x14 + iVar1,param_1 + 4,uVar3,param_4);
        return;
      }
    }
  }
  return;
}


