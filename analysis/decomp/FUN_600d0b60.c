// 600d0b60  FUN_600d0b60  size=104 bytes
// --- callers ---
// --- callees ---
//   600d1134 FUN_600d1134
//   600d109c FUN_600d109c
//   600d1090 FUN_600d1090


void FUN_600d0b60(undefined4 param_1,byte *param_2,int param_3,uint param_4,undefined4 *param_5,
                 uint *param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_3 == 5) {
    if (((*param_2 & 0x60) == 0) || ((int)((uint)*param_2 << 0x18) < 0)) {
      param_4 = 1;
    }
    else if (*(short *)(param_2 + 6) == 0) {
      param_4 = 1;
    }
    FUN_600d1134(param_1,(param_4 & 1) << 7);
    return;
  }
  uVar2 = *param_5;
  if ((uint)*(ushort *)(param_2 + 6) < *param_6) {
    *param_6 = (uint)*(ushort *)(param_2 + 6);
  }
  iVar1 = FUN_600d1090(param_1,0,uVar2,*param_6);
  if ((iVar1 == 0) && ((char)*param_2 < '\0')) {
    FUN_600d109c(param_1,0,0,0);
    return;
  }
  return;
}


