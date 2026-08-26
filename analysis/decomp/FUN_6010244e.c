// 6010244e  FUN_6010244e  size=60 bytes
// --- callers ---
//   60075088 audio_states__60075088
//   60074c2c audio_states__60074c2c
// --- callees ---
//   600cdbbc FUN_600cdbbc


void FUN_6010244e(byte *param_1,byte *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  do {
    uVar2 = (uint)*param_1;
    iVar1 = FUN_600cdbbc();
    uVar3 = (uint)*param_2;
    if ((*(byte *)(iVar1 + uVar2 + 1) & 3) == 1) {
      uVar2 = uVar2 + 0x20;
    }
    iVar1 = FUN_600cdbbc();
    if ((*(byte *)(iVar1 + uVar3 + 1) & 3) == 1) {
      uVar3 = uVar3 + 0x20;
    }
  } while ((uVar2 == uVar3) && (param_1 = param_1 + 1, param_2 = param_2 + 1, uVar3 != 0));
  return;
}


