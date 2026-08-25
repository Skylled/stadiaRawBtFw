// 600fab0c  FUN_600fab0c  size=50 bytes
// --- callers ---
// --- callees ---
//   600f2080 FUN_600f2080
//   600c1b74 FUN_600c1b74
//   6009ff18 FUN_6009ff18


void FUN_600fab0c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  undefined4 extraout_r3;
  undefined4 uVar3;
  
  iVar1 = FUN_6009ff18(param_1 + 0x1d);
  uVar3 = 0;
  uVar2 = extraout_r2;
  if (iVar1 != 0) {
    FUN_600f2080(iVar1);
    uVar3 = extraout_r3;
    uVar2 = extraout_r2_00;
  }
  FUN_600c1b74(1,param_1,uVar2,uVar3,param_2);
  return;
}


