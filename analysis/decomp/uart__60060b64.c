// 60060b64  uart__60060b64  size=114 bytes
// src: uart.cc
// --- callers ---
//   600cbdc8 xbara__600cbdc8
// --- callees ---
//   601016a2 FUN_601016a2
//   6005f534 FUN_6005f534
//   601017e8 FUN_601017e8
//   601017fc FUN_601017fc


/* src: uart.cc */

undefined4 uart__60060b64(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  FUN_601017e8(param_1 + 0x74);
  FUN_601017fc(param_1 + 0x20);
  FUN_6005f534(param_1 + 0xc);
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == DAT_60060bd8) {
    (**(code **)(iVar1 + 8))(DAT_60060bdc);
    *(int *)(DAT_60060be0 + 4) = param_1;
  }
  else {
    if (iVar1 != DAT_60060be4) {
      FUN_601016a2(DAT_60060bf0,0x94,DAT_60060bec,iVar1,param_4);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    (**(code **)(iVar1 + 8))(DAT_60060be8);
    *(int *)(DAT_60060be0 + 8) = param_1;
  }
  (**(code **)(*(int *)(param_1 + 8) + 0x10))(2);
  (**(code **)(*(int *)(param_1 + 8) + 0x28))(1,*(undefined4 *)(param_1 + 4));
  *(undefined4 *)(param_1 + 0xd4) = 0;
  (**(code **)(*(int *)(param_1 + 8) + 0x18))(param_1 + 0xc9,1);
  return 0;
}


