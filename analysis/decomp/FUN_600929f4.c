// 600929f4  FUN_600929f4  size=754 bytes
// --- callers ---
// --- callees ---
//   6004cb28 FUN_6004cb28
//   6006ddd8 FUN_6006ddd8
//   60098b70 FUN_60098b70
//   60098bc4 FUN_60098bc4
//   601024b4 FUN_601024b4
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60098820 FUN_60098820


undefined4 FUN_600929f4(undefined2 *param_1)

{
  ushort uVar1;
  int iVar2;
  
  switch(*param_1) {
  case 0x2a00:
    thunk_EXT_FUN_0000b5ba(DAT_60092c90,0,0x20);
    *(undefined1 *)((int)DAT_60092c90 + 0x1b) = *(undefined1 *)(param_1 + 8);
    *DAT_60092c90 = *(int *)(param_1 + 4);
    DAT_60092c90[3] = *(int *)(param_1 + 10);
    DAT_60092c90[4] = -1;
    if (*(int *)(param_1 + 6) == 0) {
      *(undefined1 *)(DAT_60092c90 + 7) = 1;
      *(undefined1 *)((int)DAT_60092c90 + 0x1a) = 3;
      DAT_60092c90[5] = 0;
      FUN_60098820(DAT_60092c94,1,DAT_60092c90[3],0);
    }
    else {
      *(undefined1 *)(DAT_60092c90 + 7) = 0;
      *(undefined1 *)((int)DAT_60092c90 + 0x1a) = 1;
      uVar1 = FUN_6004cb28(*(undefined4 *)(param_1 + 6));
      iVar2 = FUN_601024b4((uVar1 - 4) + *(int *)(param_1 + 6),DAT_60092c98,4);
      if (iVar2 == 0) {
        *(undefined1 *)((int)DAT_60092c90 + 0x1d) = 1;
        *(undefined2 *)(DAT_60092c90 + 6) = 0x104;
      }
      else {
        *(undefined1 *)((int)DAT_60092c90 + 0x1d) = 0;
        *(undefined2 *)(DAT_60092c90 + 6) = 0xfa;
      }
      iVar2 = FUN_6006dbac((short)DAT_60092c90[6],DAT_60092c9c,0x97);
      DAT_60092c90[5] = iVar2;
      FUN_6006ddd8(*(undefined4 *)(param_1 + 6),DAT_60092c9c,0x99);
    }
    break;
  case 0x2a01:
    if (param_1[4] == 0) {
      *(undefined1 *)((int)DAT_60092c90 + 0x1a) = 3;
      DAT_60092c90[1] = *(int *)(param_1 + 6);
      DAT_60092c90[4] = *(int *)(param_1 + 8);
      FUN_60098820(DAT_60092c94,0,DAT_60092c90[3],*(undefined1 *)((int)DAT_60092c90 + 0x1d));
    }
    else {
      if (DAT_60092c90[5] != 0) {
        FUN_6006ddd8(DAT_60092c90[5],DAT_60092c9c,0xad);
      }
      if (*DAT_60092c90 != 0) {
        (*(code *)*DAT_60092c90)(1);
      }
    }
    break;
  case 0x2a02:
    DAT_60092c90[2] = DAT_60092c90[2] + (uint)(ushort)param_1[8];
    if (param_1[8] != 3) {
      if (-1 < DAT_60092c90[4]) {
        DAT_60092c90[4] = -1;
      }
      if (DAT_60092c90[5] != 0) {
        FUN_6006ddd8(DAT_60092c90[5],DAT_60092c9c,0x100);
      }
      if (*DAT_60092c90 != 0) {
        (*(code *)*DAT_60092c90)(1);
      }
    }
    break;
  case 0x2a03:
    DAT_60092c90[2] = DAT_60092c90[2] + (uint)(ushort)param_1[8];
    *(undefined1 *)((int)DAT_60092c90 + 0x1a) = 3;
    if (param_1[8] == 0) {
      if ((param_1[8] == 0) && (param_1[4] == 4)) {
        if (-1 < DAT_60092c90[4]) {
          DAT_60092c90[4] = -1;
        }
        FUN_60098bc4();
      }
      else if (param_1[4] == 1) {
        if (-1 < DAT_60092d3c[4]) {
          DAT_60092d3c[4] = -1;
        }
        if (DAT_60092d3c[5] != 0) {
          FUN_6006ddd8(DAT_60092d3c[5],DAT_60092d40,0x127);
        }
        if (*DAT_60092d3c != 0) {
          (*(code *)*DAT_60092d3c)(1);
        }
      }
    }
    else {
      FUN_60098b70(DAT_60092c90[5],param_1[8]);
    }
    break;
  case 0x2a04:
    if (DAT_60092c90[5] != 0) {
      thunk_EXT_FUN_0000b5ba(DAT_60092c90[5],0,(short)DAT_60092c90[6]);
    }
    *(undefined1 *)((int)DAT_60092c90 + 0x1a) = 2;
    if (DAT_60092c90[2] == DAT_60092c90[1]) {
      *(undefined1 *)((int)DAT_60092c90 + 0x1a) = 3;
      if (-1 < DAT_60092c90[4]) {
        DAT_60092c90[4] = -1;
      }
      FUN_60098bc4();
    }
    break;
  case 0x2a05:
    if (DAT_60092c90[5] != 0) {
      FUN_6006ddd8(DAT_60092c90[5],DAT_60092c9c,0xb7);
    }
    if (*DAT_60092c90 != 0) {
      (*(code *)*DAT_60092c90)(0);
    }
    thunk_EXT_FUN_0000b5ba(DAT_60092c90,0,0x20);
    DAT_60092c90[4] = -1;
    break;
  case 0x2a06:
    if (DAT_60092d3c[5] != 0) {
      FUN_6006ddd8(DAT_60092d3c[5],DAT_60092d40,0x13b);
    }
    if (*DAT_60092d3c != 0) {
      (*(code *)*DAT_60092d3c)(1);
    }
    thunk_EXT_FUN_0000b5ba(DAT_60092d3c,0,0x20);
    DAT_60092d3c[4] = -1;
  }
  return 1;
}


