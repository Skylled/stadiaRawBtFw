// 600d3938  FUN_600d3938  size=48 bytes
// --- callers ---
//   60059280 FUN_60059280
// --- callees ---
//   60101b0c FUN_60101b0c
//   601019da FUN_601019da
//   600cc3cc FUN_600cc3cc


int * FUN_600d3938(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_1[2];
  iVar1 = FUN_600cc3cc();
  if (iVar1 != 0) {
    uVar2 = FUN_60101b0c(param_3,param_3 >> 0x1f,param_1[2] + *param_1,param_1[1] - param_1[2]);
    FUN_601019da(param_1,uVar2,iVar3,0x7d);
  }
  return param_1;
}


