// 60065d1c  keys__60065d1c  size=80 bytes
// src: keys.cc
// --- callers ---
//   60066070 keys__60066070
//   60065df0 keys__60065df0
// --- callees ---
//   6010209a FUN_6010209a
//   6010165c FUN_6010165c
//   6004cb28 FUN_6004cb28


/* src: keys.cc */

undefined4 keys__60065d1c(undefined4 *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  
  switch(*(undefined1 *)(param_1 + 1)) {
  case 0:
    if (*(char *)(param_1 + 4) != '\0') {
      uVar1 = FUN_6004cb28(param_1[2]);
      *param_2 = uVar1;
      return 0;
    }
                    /* WARNING: Subroutine does not return */
    FUN_6010209a();
  case 1:
  case 7:
  case 0xb:
    uVar1 = 1;
    break;
  case 2:
  case 3:
  case 5:
  case 9:
    uVar1 = 4;
    break;
  case 4:
  case 8:
    uVar1 = 8;
    break;
  case 6:
  case 10:
    uVar1 = 2;
    break;
  default:
    FUN_6010165c(0x28,DAT_60065d78,0x22d,DAT_60065d7c,*param_1,param_2);
    return 0xd;
  }
  *param_2 = uVar1;
  return 0;
}


