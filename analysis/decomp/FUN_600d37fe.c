// 600d37fe  FUN_600d37fe  size=48 bytes
// --- callers ---
//   600593f4 FUN_600593f4
// --- callees ---
//   60101b0c FUN_60101b0c
//   601019da FUN_601019da
//   60101ac8 FUN_60101ac8


int * FUN_600d37fe(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_1[2];
  iVar1 = FUN_60101ac8();
  if (iVar1 != 0) {
    uVar2 = FUN_60101b0c(param_2,param_2 >> 0x1f,param_1[2] + *param_1,param_1[1] - param_1[2]);
    FUN_601019da(param_1,uVar2,iVar3,0x5d);
  }
  return param_1;
}


