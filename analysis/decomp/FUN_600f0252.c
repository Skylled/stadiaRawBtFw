// 600f0252  FUN_600f0252  size=232 bytes
// --- callers ---
//   600a6d70 FUN_600a6d70
//   60093a30 FUN_60093a30
//   600fd03a FUN_600fd03a
//   60099c0c FUN_60099c0c
//   600c2d5c FUN_600c2d5c
// --- callees ---
//   600b2f80 FUN_600b2f80
//   600a1354 FUN_600a1354
//   60098ec8 FUN_60098ec8


undefined4 FUN_600f0252(undefined4 param_1,ushort *param_2)

{
  byte *pbVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  pbVar1 = (byte *)FUN_600a1354();
  if (*param_2 != 0) {
    if (((*param_2 & 1) != 0) && ((*pbVar1 & 0x20) == 0)) {
      *param_2 = *param_2 & 0xfffe;
    }
    if (((*param_2 & 2) != 0) && ((*pbVar1 & 0x40) == 0)) {
      *param_2 = *param_2 & 0xfffd;
    }
    if (((*param_2 & 4) != 0) && (-1 < (char)*pbVar1)) {
      *param_2 = *param_2 & 0xfffb;
    }
    if (((*param_2 & 8) != 0) && ((pbVar1[1] & 1) == 0)) {
      *param_2 = *param_2 & 0xfff7;
    }
  }
  puVar2 = (undefined2 *)FUN_60098ec8(param_1,1);
  if (puVar2 == (undefined2 *)0x0) {
    uVar4 = 7;
  }
  else {
    iVar3 = FUN_600b2f80(*puVar2,*param_2);
    if (iVar3 == 0) {
      uVar4 = 3;
    }
    else {
      uVar4 = 1;
    }
  }
  return uVar4;
}


