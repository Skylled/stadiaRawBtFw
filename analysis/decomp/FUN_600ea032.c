// 600ea032  FUN_600ea032  size=182 bytes
// --- callers ---
//   600ea438 FUN_600ea438
// --- callees ---
//   6008893c FUN_6008893c


void FUN_600ea032(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = (*param_1 ^ param_1[1] >> 4) & 0xf0f0f0f;
  uVar3 = *param_1 ^ uVar4;
  uVar4 = param_1[1] ^ uVar4 << 4;
  uVar5 = uVar4 ^ uVar3 >> 0x10;
  uVar4 = uVar4 ^ uVar5 & 0xffff;
  uVar3 = uVar3 ^ uVar5 << 0x10;
  uVar5 = (uVar3 ^ uVar4 >> 2) & 0x33333333;
  uVar3 = uVar3 ^ uVar5;
  uVar4 = uVar4 ^ uVar5 << 2;
  uVar5 = (uVar4 ^ uVar3 >> 8) & 0xff00ff;
  uVar4 = uVar4 ^ uVar5;
  uVar3 = uVar3 ^ uVar5 << 8;
  uVar5 = (uVar3 ^ uVar4 >> 1) & 0x55555555;
  uVar3 = uVar3 ^ uVar5;
  *param_1 = uVar3;
  param_1[1] = uVar4 ^ uVar5 << 1;
  uVar1 = FUN_6008893c(param_1,param_2,1,uVar3,param_4);
  uVar1 = FUN_6008893c(uVar1,param_3,0);
  puVar2 = (uint *)FUN_6008893c(uVar1,param_4,1);
  uVar4 = (*puVar2 ^ puVar2[1] >> 1) & 0x55555555;
  uVar3 = *puVar2 ^ uVar4;
  uVar5 = puVar2[1] ^ uVar4 << 1;
  uVar4 = (uVar5 ^ uVar3 >> 8) & 0xff00ff;
  uVar5 = uVar5 ^ uVar4;
  uVar3 = uVar3 ^ uVar4 << 8;
  uVar4 = (uVar3 ^ uVar5 >> 2) & 0x33333333;
  uVar3 = uVar3 ^ uVar4;
  uVar5 = uVar5 ^ uVar4 << 2;
  uVar4 = uVar5 ^ uVar3 >> 0x10;
  uVar5 = uVar5 ^ uVar4 & 0xffff;
  uVar3 = uVar3 ^ uVar4 << 0x10;
  uVar4 = (uVar3 ^ uVar5 >> 4) & 0xf0f0f0f;
  *puVar2 = uVar3 ^ uVar4;
  puVar2[1] = uVar5 ^ uVar4 << 4;
  return;
}


