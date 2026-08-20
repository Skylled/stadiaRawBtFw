// 600e9a8e  FUN_600e9a8e  size=102 bytes
// --- callers ---
//   600e9af4 FUN_600e9af4
// --- callees ---
//   6008b544 FUN_6008b544
//   6008b50c bcm__6008b50c
//   600e9a40 FUN_600e9a40
//   6008b4b8 bcm__6008b4b8
//   6008bbdc bcm__6008bbdc
//   6008b970 bcm__6008b970


bool FUN_600e9a8e(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = param_3;
  iVar1 = bcm__6008b970();
  if (iVar1 == 0) {
LAB_600e9a9a:
    bVar4 = false;
  }
  else {
    if (param_3 == 0) {
      param_3 = bcm__6008b50c();
      iVar1 = param_3;
      if (param_3 == 0) goto LAB_600e9a9a;
    }
    else {
      iVar1 = 0;
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    iVar2 = FUN_600e9a40(param_1,*(int *)(param_1 + 0x18) << 6);
    if ((iVar2 == 0) ||
       (iVar3 = bcm__6008bbdc(0,param_1,param_1,param_1 + 0x14,param_3,param_2,iVar3), iVar3 == 0))
    {
      bVar4 = false;
    }
    else {
      iVar3 = bcm__6008b4b8(param_1,*(undefined4 *)(param_1 + 0x18));
      bVar4 = iVar3 != 0;
    }
    FUN_6008b544(iVar1);
  }
  return bVar4;
}


