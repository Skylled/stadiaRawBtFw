// 600df70c  FUN_600df70c  size=82 bytes
// --- callers ---
//   60081ea4 FUN_60081ea4
//   600df8a0 FUN_600df8a0
//   600820d8 FUN_600820d8
//   600df7f0 FUN_600df7f0
// --- callees ---
//   60081d50 FUN_60081d50


void FUN_600df70c(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte local_24 [16];
  
  if (param_4 == 0 && param_3 < 0x80) {
    local_24[0] = (byte)param_3;
    iVar3 = 1;
  }
  else {
    iVar3 = 0;
    do {
      iVar2 = iVar3;
      bVar1 = (byte)param_3;
      uVar4 = param_4 >> 7;
      local_24[iVar2] = bVar1 | 0x80;
      param_3 = param_3 >> 7 | param_4 << 0x19;
      iVar3 = iVar2 + 1;
      param_4 = uVar4;
    } while (param_3 != 0 || uVar4 != 0);
    local_24[iVar2] = bVar1 & 0x7f;
  }
  FUN_60081d50(param_1,local_24,iVar3);
  return;
}


