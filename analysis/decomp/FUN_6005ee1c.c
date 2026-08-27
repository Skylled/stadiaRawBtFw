// 6005ee1c  FUN_6005ee1c  size=38 bytes
// --- callers ---
// --- callees ---
//   60101c48 FUN_60101c48
//   601017e8 FUN_601017e8


void FUN_6005ee1c(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  *(undefined4 *)(DAT_6005ee44 + 0x50) = 0;
  FUN_601017e8();
  uVar2 = DAT_6005ee4c;
  puVar1 = DAT_6005ee48;
  *(undefined1 *)(DAT_6005ee48 + 1) = 0;
  *(undefined1 *)(puVar1 + 4) = 0;
  uVar4 = DAT_6005ee54;
  uVar3 = DAT_6005ee50;
  *puVar1 = uVar2;
  puVar1[2] = 0;
  puVar1[3] = 0;
  FUN_60101c48(puVar1,uVar4,uVar3);
  return;
}


