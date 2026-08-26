// 60101aa4  FUN_60101aa4  size=36 bytes
// --- callers ---
//   60059280 FUN_60059280
//   600cbb7c FUN_600cbb7c
//   6007694c FUN_6007694c
//   6005e020 power_rpcs__6005e020
//   60059360 FUN_60059360
//   600593f4 FUN_600593f4
//   6005e810 FUN_6005e810
//   600d38c8 FUN_600d38c8
// --- callees ---
//   6010196e FUN_6010196e
//   600cc3cc FUN_600cc3cc
//   60101a12 FUN_60101a12


int FUN_60101aa4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 8);
  iVar1 = FUN_600cc3cc();
  if (iVar1 != 0) {
    FUN_60101a12(param_1,param_3,uVar2);
    FUN_6010196e(param_1,0x7d);
  }
  return param_1;
}


