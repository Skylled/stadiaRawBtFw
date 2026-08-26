// 600d48d8  FUN_600d48d8  size=42 bytes
// --- callers ---
// --- callees ---
//   6005fa0c flash_lut__6005fa0c


uint FUN_600d48d8(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (iVar2 == param_3) {
      return 0;
    }
    uVar1 = flash_lut__6005fa0c(param_1,*(int *)(param_1 + 4) * iVar2 + param_2);
    if ((uVar1 & 0xff) != 0) break;
    iVar2 = iVar2 + 1;
  }
  return uVar1;
}


