// 601025a8  FUN_601025a8  size=180 bytes
// --- callers ---
//   600cddc8 FUN_600cddc8
// --- callees ---
//   600d3594 FUN_600d3594
//   6013d238 thunk_EXT_FUN_0000b588
//   600d35a0 FUN_600d35a0
//   600d359a FUN_600d359a
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 FUN_601025a8(undefined4 *param_1,int *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if ((uint)param_2[2] <= param_4) {
    uVar3 = param_2[2];
    if ((*(ushort *)(param_2 + 3) & 0x480) != 0) {
      iVar4 = *param_2 - param_2[4];
      uVar3 = (param_2[5] * 3) / 2;
      uVar2 = param_4 + 1 + iVar4;
      if (uVar3 < uVar2) {
        uVar3 = uVar2;
      }
      if ((int)((uint)*(ushort *)(param_2 + 3) << 0x15) < 0) {
        iVar1 = FUN_600d3594(param_1,uVar3);
        if (iVar1 == 0) {
LAB_601025ee:
          *param_1 = 0xc;
          *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x40;
          return 0xffffffff;
        }
        thunk_EXT_FUN_0000b572(iVar1,param_2[4],iVar4);
        *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xfb7f | 0x80;
      }
      else {
        iVar1 = FUN_600d35a0(param_1,param_2[4],uVar3);
        if (iVar1 == 0) {
          FUN_600d359a(param_1,param_2[4]);
          goto LAB_601025ee;
        }
      }
      param_2[4] = iVar1;
      param_2[5] = uVar3;
      *param_2 = iVar1 + iVar4;
      param_2[2] = uVar3 - iVar4;
      uVar3 = param_4;
    }
    if (uVar3 <= param_4) goto LAB_6010262c;
  }
  uVar3 = param_4;
LAB_6010262c:
  thunk_EXT_FUN_0000b588(*param_2,param_3,uVar3);
  param_2[2] = param_2[2] - uVar3;
  *param_2 = uVar3 + *param_2;
  return 0;
}


