// 600ef4ae  FUN_600ef4ae  size=98 bytes
// --- callers ---
//   600eedee FUN_600eedee
//   600ee522 FUN_600ee522
//   600ee4c8 FUN_600ee4c8
//   600eef06 FUN_600eef06
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600ef4ae(undefined4 *param_1,undefined2 *param_2)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)*param_1;
  thunk_EXT_FUN_0000b5ba(param_2,0,0x14);
  *param_2 = *(undefined2 *)(param_1 + 2);
  if (*(short *)(param_1 + 2) == 2) {
    param_2[2] = (ushort)pbVar1[1] * 0x100 + (ushort)*pbVar1;
  }
  else {
    thunk_EXT_FUN_0000b572(param_2 + 2,pbVar1,0x10);
  }
  return;
}


