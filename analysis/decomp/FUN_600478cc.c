// 600478cc  FUN_600478cc  size=110 bytes
// --- callers ---
//   60047d3c tasks__60047d3c
//   600480cc FUN_600480cc
//   60047ce4 tasks__60047ce4
//   60047cac tasks__60047cac
//   60047b98 tasks__60047b98
// --- callees ---
//   6004bb60 FUN_6004bb60
//   6004bb32 FUN_6004bb32
//   6004bb1a FUN_6004bb1a


void FUN_600478cc(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  piVar1 = DAT_60047940;
  uVar3 = *DAT_6004793c;
  iVar2 = FUN_6004bb60(*DAT_60047940 + 4);
  if (iVar2 == 0) {
    *DAT_60047944 = *DAT_60047944 & ~(1 << (*(uint *)(*piVar1 + 0x2c) & 0xff));
  }
  if ((param_1 == 0xffffffff) && (param_2 != 0)) {
    FUN_6004bb1a(DAT_60047948,*piVar1 + 4,0,param_4);
    return;
  }
  uVar4 = uVar3 + param_1;
  *(uint *)(*piVar1 + 4) = uVar4;
  if (CARRY4(uVar3,param_1)) {
    FUN_6004bb32(*DAT_6004794c,*piVar1 + 4,DAT_6004794c,param_4);
    return;
  }
  FUN_6004bb32(*DAT_60047950,*piVar1 + 4);
  if (uVar4 < *DAT_60047954) {
    *DAT_60047954 = uVar4;
  }
  return;
}


