// 60134018  FUN_60134018  size=48 bytes
// --- callers ---
// --- callees ---
//   60105c84 FUN_60105c84


uint FUN_60134018(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if (param_2 == 2) {
    iVar2 = FUN_60105c84();
    if (iVar2 == 0) {
      iVar2 = 0x58;
    }
    else {
      iVar2 = 0x78;
    }
    uVar1 = (uint)(iVar2 + param_1 * 8) >> 1;
  }
  else {
    uVar1 = param_1 * 8 + 0x50;
  }
  return (uVar1 + 0x369) / 0x271;
}


