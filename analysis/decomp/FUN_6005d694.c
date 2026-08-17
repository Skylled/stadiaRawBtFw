// 6005d694  FUN_6005d694  size=92 bytes
// --- callers ---
// --- callees ---
//   60101c48 FUN_60101c48
//   600511c8 timer__600511c8


void FUN_6005d694(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = DAT_6005d710;
  uVar3 = DAT_6005d6fc;
  uVar2 = DAT_6005d6f8;
  uVar1 = DAT_6005d6f4;
  timer__600511c8(DAT_6005d6f4,DAT_6005d700,5000,DAT_6005d710,DAT_6005d6f0,0,0);
  FUN_60101c48(uVar1,uVar3,uVar2);
  uVar1 = DAT_6005d704;
  timer__600511c8(DAT_6005d704,DAT_6005d70c,10000,uVar4,DAT_6005d708,1,0);
  FUN_60101c48(uVar1,uVar3,uVar2);
  return;
}


