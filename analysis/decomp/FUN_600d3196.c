// 600d3196  FUN_600d3196  size=40 bytes
// --- callers ---
//   6005663c FUN_6005663c
//   600d31be FUN_600d31be
//   600d31cc FUN_600d31cc
// --- callees ---
//   600d3386 FUN_600d3386
//   600d32a2 FUN_600d32a2


bool FUN_600d3196(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  *(short *)(*(int *)(param_2 + 0x1c) + 6) = (short)param_4;
  uVar3 = *(undefined4 *)(param_1 + 0x418);
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_2 + 4) = param_3;
  *(undefined4 *)(param_2 + 8) = param_4;
  iVar2 = FUN_600d32a2(uVar1,uVar3,param_2,param_4,param_4);
  if (iVar2 != 0) {
    FUN_600d3386(*(undefined4 *)(param_1 + 4),param_2);
  }
  return iVar2 != 0;
}


