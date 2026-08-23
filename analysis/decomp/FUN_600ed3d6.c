// 600ed3d6  FUN_600ed3d6  size=86 bytes
// --- callers ---
//   60090f78 FUN_60090f78
//   60090fd0 FUN_60090fd0
// --- callees ---
//   600ed3ba FUN_600ed3ba


uint FUN_600ed3d6(undefined4 param_1,uint *param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uStack_1c;
  uint uStack_18;
  
  uVar3 = 0;
  uVar4 = 0;
  uVar5 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  while( true ) {
    iVar2 = FUN_600ed3ba(param_1,(int)&uStack_1c + 3,param_3,param_4,uVar5);
    if (iVar2 == 0) {
      return 0;
    }
    if (uVar4 >> 0x19 != 0) break;
    uVar1 = (uint)uStack_1c >> 0x18;
    if ((uVar3 == 0 && uVar4 == 0) && (uVar1 == 0x80)) {
      return uVar4;
    }
    param_3 = uVar3 << 7;
    uVar4 = uVar4 << 7 | uVar3 >> 0x19;
    uVar3 = param_3 | uVar1 & 0x7f;
    param_4 = uVar1 << 0x18;
    if (-1 < param_4) {
      *param_2 = uVar3;
      param_2[1] = uVar4;
      return 1;
    }
  }
  return 0;
}


