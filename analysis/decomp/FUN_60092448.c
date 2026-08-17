// 60092448  FUN_60092448  size=72 bytes
// --- callers ---
// --- callees ---
//   6013d2d0 thunk_EXT_FUN_0000713c
//   6013d0e0 thunk_EXT_FUN_0000728c
//   601007e6 FUN_601007e6
//   6013d038 thunk_EXT_FUN_00008832


undefined4 FUN_60092448(int *param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  
  pcVar1 = DAT_60092490;
  *param_1 = 0;
  thunk_EXT_FUN_0000713c();
  if (*pcVar1 == '\0') {
    iVar2 = FUN_601007e6(1);
    *DAT_60092494 = iVar2;
    if (iVar2 == 0) {
      thunk_EXT_FUN_0000728c();
      return 0xc;
    }
    *pcVar1 = '\x01';
  }
  thunk_EXT_FUN_0000728c();
  puVar3 = (undefined4 *)thunk_EXT_FUN_00008832(0xc);
  if (puVar3 == (undefined4 *)0x0) {
    return 0xc;
  }
  *puVar3 = param_2;
  *param_1 = (int)puVar3;
  puVar3[1] = 0;
  puVar3[2] = 0;
  return 0;
}


