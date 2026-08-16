// 60047d80  tasks__60047d80  size=102 bytes
// src: tasks.c
// --- callers ---
//   60047548 FUN_60047548
//   600474a4 FUN_600474a4
//   60047678 queue__60047678
//   600473e4 queue__600473e4
//   60047290 queue__60047290
//   6004bc28 FUN_6004bc28
//   600471bc queue__600471bc
// --- callees ---
//   6004c084 thunk_FUN_601016a2
//   6004bb60 FUN_6004bb60
//   6004bb1a FUN_6004bb1a


/* src: tasks.c */

bool tasks__60047d80(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 0xc);
  if (iVar4 == 0) {
    thunk_FUN_601016a2(DAT_60047dec,0xcd8,DAT_60047de8,*(int *)(param_1 + 0xc),param_4);
  }
  iVar5 = iVar4 + 0x18;
  FUN_6004bb60(iVar5);
  iVar1 = DAT_60047e04;
  if (*DAT_60047df0 == 0) {
    iVar5 = iVar4 + 4;
    FUN_6004bb60(iVar5);
    uVar2 = *(uint *)(iVar4 + 0x2c);
    *DAT_60047df4 = 1 << (uVar2 & 0xff) | *DAT_60047df4;
    iVar1 = uVar2 * 0x14 + DAT_60047df8;
  }
  FUN_6004bb1a(iVar1,iVar5);
  uVar2 = *(uint *)(iVar4 + 0x2c);
  uVar3 = *(uint *)(*DAT_60047dfc + 0x2c);
  if (uVar3 < uVar2) {
    *DAT_60047e00 = 1;
  }
  return uVar3 < uVar2;
}


