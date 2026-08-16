// 600480cc  FUN_600480cc  size=98 bytes
// --- callers ---
// --- callees ---
//   600478cc FUN_600478cc
//   600485c8 FUN_600485c8
//   60048580 FUN_60048580


int FUN_600480cc(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_60048130;
  FUN_60048580();
  if (*(int *)(*piVar1 + 0xc4) == 0) {
    *(undefined1 *)(*piVar1 + 200) = 1;
    if (param_2 != 0) {
      FUN_600478cc(param_2);
      *DAT_60048134 = 0x10000000;
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
    }
  }
  FUN_600485c8();
  FUN_60048580();
  iVar3 = *(int *)(*piVar1 + 0xc4);
  if (iVar3 != 0) {
    if (param_1 == 0) {
      iVar2 = iVar3 + -1;
    }
    else {
      iVar2 = 0;
    }
    *(int *)(*piVar1 + 0xc4) = iVar2;
  }
  *(undefined1 *)(*piVar1 + 200) = 0;
  FUN_600485c8();
  return iVar3;
}


