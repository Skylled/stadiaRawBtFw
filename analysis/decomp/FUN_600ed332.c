// 600ed332  FUN_600ed332  size=72 bytes
// --- callers ---
//   60090fd0 FUN_60090fd0
// --- callees ---
//   600ed0de FUN_600ed0de
//   6004c814 FUN_6004c814


void FUN_600ed332(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char extraout_r2;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  char acStack_31 [29];
  
  lVar4 = CONCAT44(param_4,param_3);
  iVar1 = 0x17;
  do {
    iVar2 = iVar1;
    uVar3 = (undefined4)((ulonglong)lVar4 >> 0x20);
    FUN_6004c814((int)lVar4,uVar3,10,0);
    acStack_31[iVar2] = extraout_r2 + '0';
    lVar4 = FUN_6004c814((int)lVar4,uVar3,10,0);
    iVar1 = iVar2 + -1;
  } while (lVar4 != 0);
  FUN_600ed0de(param_1,acStack_31 + iVar2,0x17 - (iVar2 + -1));
  return;
}


