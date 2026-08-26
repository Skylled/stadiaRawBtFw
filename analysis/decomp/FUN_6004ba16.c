// 6004ba16  FUN_6004ba16  size=88 bytes
// --- callers ---
//   6004baa8 FUN_6004baa8
// --- callees ---
//   60047678 queue__60047678
//   6004c124 queue__600c9eac
//   60046fa4 FUN_60046fa4
//   60047f50 FUN_60047f50


undefined4 FUN_6004ba16(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  DataMemoryBarrier(0x1b);
  if (*param_1 - 1U < 0xfffffffc || *param_1 == -3) {
    iVar4 = *param_1;
    iVar1 = FUN_60046fa4();
    if ((iVar1 == *(int *)(iVar4 + 4)) && (*(int *)(iVar4 + 8) == 2)) {
      uVar3 = 0x2d;
    }
    else {
      iVar2 = FUN_60047f50();
      if ((iVar2 != 0) || (*(int *)(iVar4 + 4) != 0)) {
        if (*(int *)(iVar4 + 8) == 1) {
          iVar2 = queue__600c9eac();
        }
        else {
          iVar2 = queue__60047678(*(undefined4 *)(iVar4 + 0xc),param_2);
        }
        if (iVar2 != 1) {
          return 0x74;
        }
      }
      uVar3 = 0;
      *(int *)(iVar4 + 4) = iVar1;
    }
  }
  else {
    uVar3 = 0x16;
  }
  return uVar3;
}


