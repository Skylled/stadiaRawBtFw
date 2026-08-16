// 60046ffc  FUN_60046ffc  size=60 bytes
// --- callers ---
//   60046f10 FUN_60046f10
// --- callees ---
//   60046fa4 FUN_60046fa4
//   60047678 queue__60047678
//   60047290 queue__60047290


undefined4 FUN_60046ffc(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  puVar1 = DAT_60047038;
  iVar2 = FUN_60046fa4();
  queue__60047678(*puVar1,0xffffffff);
  piVar3 = *(int **)(iVar2 + 0x2c);
  do {
    if (piVar3 == (int *)0x0) {
      uVar4 = 0;
LAB_60047024:
      queue__60047290(*puVar1,0,0);
      return uVar4;
    }
    if (piVar3[2] == param_1) {
      uVar4 = piVar3[3];
      goto LAB_60047024;
    }
    piVar3 = (int *)*piVar3;
  } while( true );
}


