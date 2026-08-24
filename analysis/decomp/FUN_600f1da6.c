// 600f1da6  FUN_600f1da6  size=126 bytes
// --- callers ---
//   600f2de0 FUN_600f2de0
// --- callees ---
//   600f1746 FUN_600f1746


void FUN_600f1da6(byte *param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  byte *local_2c;
  byte local_24 [13];
  byte local_17 [7];
  
  pbVar1 = local_17;
  local_2c = param_1;
  for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
    *pbVar1 = *local_2c;
    pbVar1 = pbVar1 + -1;
    local_2c = local_2c + 1;
  }
  iVar3 = FUN_600f1746(local_24 + 8);
  if ((*(byte *)(iVar3 + 0x59) & 0x11) == 0) {
    *(undefined1 *)(iVar3 + 0x59) = 0x10;
    for (iVar2 = 0; iVar2 < 8; iVar2 = iVar2 + 1) {
      local_24[iVar2] = *local_2c;
      local_2c = local_2c + 1;
    }
    if ((local_24[0] & 1) != 0) {
      *(undefined1 *)(iVar3 + 0x59) = 0x11;
    }
  }
  return;
}


