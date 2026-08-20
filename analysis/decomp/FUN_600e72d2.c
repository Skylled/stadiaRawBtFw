// 600e72d2  FUN_600e72d2  size=32 bytes
// --- callers ---
//   600e75c2 FUN_600e75c2
//   6008b4b8 bcm__6008b4b8
//   6008b3d4 bcm__6008b3d4
//   6008b60c bcm__6008b60c
// --- callees ---


bool FUN_600e72d2(int *param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2 << 2;
  uVar3 = 0;
  for (; param_2 < (uint)param_1[1]; param_2 = param_2 + 1) {
    puVar1 = (uint *)(*param_1 + iVar2);
    iVar2 = iVar2 + 4;
    uVar3 = uVar3 | *puVar1;
  }
  return uVar3 == 0;
}


