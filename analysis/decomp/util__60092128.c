// 60092128  util__60092128  size=132 bytes
// src: util.cc
// --- callers ---
//   600dfcf2 FUN_600dfcf2
// --- callees ---
//   6010165c FUN_6010165c
//   600edc9c FUN_600edc9c


/* src: util.cc */

undefined4
util__60092128(char *param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 != 0) {
    if (*param_1 != '\x01') {
      return 3;
    }
    iVar1 = 0;
    for (iVar2 = 1; iVar2 != param_2; iVar2 = iVar2 + 1) {
      iVar3 = *(int *)(param_1 + 0x1c);
      if (iVar1 == 0) {
        iVar1 = FUN_600edc9c(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                             *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),param_3
                             ,param_4);
        if (iVar1 != 0) {
          if (iVar3 != 1) {
            if (iVar3 == 0) {
              FUN_6010165c(0x1e,DAT_600921b0,0x97,DAT_600921ac,param_4);
              if (param_5 == (int *)0x0) {
                return 0;
              }
              goto LAB_6009217a;
            }
            FUN_6010165c(0x1e,DAT_600921b0,0x9f,DAT_600921b4,param_4);
          }
          if (param_5 == (int *)0x0) {
            return 0;
          }
          iVar2 = iVar2 + 1;
LAB_6009217a:
          *param_5 = iVar2;
          return 0;
        }
      }
      else {
        iVar3 = iVar1 + -1 + iVar3;
      }
      iVar1 = iVar3;
      param_1 = param_1 + 0x10;
    }
  }
  return 5;
}


