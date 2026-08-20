// 600ebc6e  FUN_600ebc6e  size=102 bytes
// --- callers ---
//   6008df14 FUN_6008df14
// --- callees ---


void FUN_600ebc6e(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_2[2];
  uVar4 = param_2[3];
  param_1[2] = uVar3;
  param_1[3] = uVar4;
  uVar1 = *param_2;
  uVar2 = param_2[1];
  param_1[2] = (int)uVar2 >> 0x1f & 1U ^ uVar3 * 2;
  param_1[3] = uVar4 * 2 + (uint)CARRY4(uVar3,uVar3);
  *param_1 = uVar1 * 2 | uVar4 >> 0x1f;
  param_1[1] = uVar2 * 2 + (uint)CARRY4(uVar1,uVar1) ^ -(uint)((int)uVar2 < 0) & 0xc2000000;
  return;
}


