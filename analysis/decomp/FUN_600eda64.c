// 600eda64  FUN_600eda64  size=56 bytes
// --- callers ---
//   60091330 ec_asn1__60091330
// --- callees ---
//   600ed398 FUN_600ed398
//   600ed39c FUN_600ed39c


uint FUN_600eda64(undefined4 param_1)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  iVar1 = FUN_600ed39c();
  if (iVar1 != 0) {
    pbVar2 = (byte *)FUN_600ed398(param_1);
    if (-1 < (int)((uint)*pbVar2 << 0x18)) {
      if ((*pbVar2 == 0) && (uVar3 = FUN_600ed39c(param_1), 1 < uVar3)) {
        iVar1 = FUN_600ed398(param_1);
        return (uint)(int)*(char *)(iVar1 + 1) >> 0x1f;
      }
      return 1;
    }
  }
  return 0;
}


