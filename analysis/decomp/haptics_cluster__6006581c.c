// 6006581c  haptics_cluster__6006581c  size=130 bytes
// src: haptics_cluster.cc
// --- callers ---
//   60074658 timer__60074658
// --- callees ---
//   600d37ac FUN_600d37ac
//   6007060c FUN_6007060c
//   600d37b8 FUN_600d37b8
//   60051120 FUN_60051120
//   6009267c FUN_6009267c
//   600d6c76 FUN_600d6c76


/* src: haptics_cluster.cc */

undefined1 haptics_cluster__6006581c(char *param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_ac;
  char *pcStack_a8;
  undefined1 auStack_a4 [144];
  undefined1 local_14;
  
  if (*param_1 == '\0') {
    param_1[8] = '\0';
    param_1[9] = '\0';
    param_1[0x10] = '\0';
    param_1[0x11] = '\0';
    FUN_6009267c(1);
    *(undefined4 *)(param_1 + 0x68) = DAT_600658a0;
    *(char **)(param_1 + 0x6c) = param_1;
    local_ac = DAT_600658a4;
    pcStack_a8 = param_1;
    FUN_6007060c(DAT_600658a4,param_1);
    cVar1 = FUN_600d6c76(*(undefined4 *)(param_1 + 4));
    if (cVar1 == '\0') {
      uVar2 = FUN_600d6c76(*(undefined4 *)(param_1 + 0xc));
      if ((uVar2 & 0xff) == 0) {
        *param_1 = '\x01';
        return 0;
      }
      FUN_60051120(&local_ac,DAT_600658a8,0x26,uVar2);
      uVar3 = DAT_600658b0;
    }
    else {
      FUN_60051120(&local_ac,DAT_600658a8,0x25);
      uVar3 = DAT_600658ac;
    }
    FUN_600d37ac(auStack_a4,uVar3);
    FUN_600d37b8(&local_ac);
  }
  else {
    local_14 = 0;
  }
  return local_14;
}


