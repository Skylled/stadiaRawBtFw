// 600e98c6  FUN_600e98c6  size=134 bytes
// --- callers ---
//   600e99a2 FUN_600e99a2
// --- callees ---
//   600e77c0 FUN_600e77c0
//   600e72fc FUN_600e72fc
//   600e9760 FUN_600e9760
//   600e7718 FUN_600e7718
//   600e7412 FUN_600e7412
//   6008b570 bcm__6008b570
//   6008b43c bcm__6008b43c


undefined4 FUN_600e98c6(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  uint uVar4;
  
  FUN_600e7718(param_4);
  puVar1 = (undefined4 *)bcm__6008b570(param_4);
  if (((puVar1 == (undefined4 *)0x0) || (iVar2 = FUN_600e72fc(param_1,param_2), iVar2 == 0)) ||
     (iVar2 = bcm__6008b43c(puVar1,param_1[1]), iVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    iVar2 = param_1[1];
    for (uVar4 = 0; (uint)(iVar2 << 5) >> (uVar4 & 0xff) != 0; uVar4 = uVar4 + 1) {
      FUN_600e9760(*puVar1,*param_1,1 << (uVar4 & 0xff),param_1[1]);
      FUN_600e7412(*param_1,-(param_3 >> (uVar4 & 0xff) & 1),*puVar1,*param_1,param_1[1]);
    }
    uVar3 = 1;
  }
  FUN_600e77c0(param_4,uVar3);
  return extraout_r1;
}


