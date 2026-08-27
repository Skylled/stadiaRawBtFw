// 6005dafc  FUN_6005dafc  size=30 bytes
// --- callers ---
// --- callees ---
//   60050c18 FUN_60050c18
//   601019b2 FUN_601019b2


undefined1 FUN_6005dafc(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x14);
  uVar1 = FUN_60050c18(DAT_6005db1c,0,*puVar2,puVar2[1] + 1);
  FUN_601019b2(puVar2,uVar1);
  return *(undefined1 *)(puVar2 + 3);
}


