// 600aa534  FUN_600aa534  size=114 bytes
// --- callers ---
//   600aa4f4 FUN_600aa4f4
//   6006ba0c FUN_6006ba0c
// --- callees ---
//   60096930 FUN_60096930
//   600d932a FUN_600d932a
//   600bb2ac FUN_600bb2ac
//   6006e2d0 FUN_6006e2d0


void FUN_600aa534(int *param_1)

{
  short sVar1;
  int iVar2;
  
  FUN_600d932a(param_1,1);
  while ((*param_1 != 0 && (*(int *)(*param_1 + 0xc) == 0))) {
    iVar2 = *param_1;
    FUN_6006e2d0(param_1,iVar2);
    sVar1 = *(short *)(iVar2 + 0x14);
    if (sVar1 == 0x26) {
      FUN_60096930();
    }
    else if ((sVar1 == 0x2a) || (sVar1 == 3)) {
      FUN_600bb2ac(iVar2);
    }
    else if (*(int *)(DAT_600aa5a8 + 0xd4) != 0) {
      (**(code **)(DAT_600aa5a8 + 0xd4))(6,iVar2);
    }
  }
  return;
}


