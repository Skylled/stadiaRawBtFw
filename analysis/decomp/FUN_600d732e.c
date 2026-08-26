// 600d732e  FUN_600d732e  size=62 bytes
// --- callers ---
//   600666f0 keys__600666f0
// --- callees ---
//   600d72b8 FUN_600d72b8
//   600d72ec FUN_600d72ec
//   600d6e14 FUN_600d6e14
//   60065c68 FUN_60065c68


uint FUN_600d732e(undefined4 param_1,uint param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint local_14;
  undefined4 uStack_10;
  
  local_14 = param_2;
  uStack_10 = param_3;
  iVar2 = FUN_600d6e14();
  if (iVar2 == 0) {
    uVar3 = FUN_600d72ec(param_1,&local_14);
    if ((uVar3 & 0xff) != 0) {
      return uVar3;
    }
    uVar3 = local_14 & 0xff;
  }
  else {
    bVar1 = FUN_600d72b8(param_1);
    if (bVar1 != 0) {
      return (uint)bVar1;
    }
    uVar3 = 0;
    if (local_14 != 0) {
      uVar3 = 1;
    }
  }
  iVar2 = FUN_60065c68(param_2,uVar3);
  return (uint)*(byte *)(iVar2 + 0xc);
}


