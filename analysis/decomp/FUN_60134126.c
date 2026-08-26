// 60134126  FUN_60134126  size=32 bytes
// --- callers ---
//   60134088 FUN_60134088
// --- callees ---


undefined8 FUN_60134126(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  int unaff_r6;
  uint uVar3;
  undefined4 unaff_r7;
  uint uVar4;
  
  *(short *)(param_4 + 4) = (short)param_2;
  *(undefined4 *)(unaff_r6 + 0x3c) = unaff_r7;
  uVar1 = *(uint *)(param_2 + 0xc);
  puVar2 = *(uint **)(param_2 + 0x10);
  uVar3 = *(uint *)(param_2 + 0x14);
  uVar4 = *(uint *)(param_2 + 0x18);
  *puVar2 = uVar1;
  puVar2[1] = (uint)puVar2;
  puVar2[2] = uVar3;
  puVar2[3] = uVar4;
  return CONCAT44(uVar1 >> 8,(int)uVar4 >> 7);
}


