// 60100e78  FUN_60100e78  size=50 bytes
// --- callers ---
//   6010112c FUN_6010112c
//   600cb598 key_value_store__600cb598
//   600cb6fc key_value_store__600cb6fc
//   60101198 FUN_60101198
//   601010c8 FUN_601010c8
// --- callees ---
//   601024b4 FUN_601024b4


byte FUN_60100e78(int param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  
  bVar1 = *(byte *)(param_1 + 0xab8);
  param_1 = param_1 + 0x158;
  bVar2 = 0;
  do {
    bVar4 = bVar2;
    if (bVar1 <= bVar4) {
      return 100;
    }
    iVar3 = FUN_601024b4(param_2,param_1,0x10);
    param_1 = param_1 + 0x18;
    bVar2 = bVar4 + 1;
  } while (iVar3 != 0);
  return bVar4;
}


