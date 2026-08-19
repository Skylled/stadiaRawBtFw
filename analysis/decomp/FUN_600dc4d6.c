// 600dc4d6  FUN_600dc4d6  size=60 bytes
// --- callers ---
//   600dc38e FUN_600dc38e
// --- callees ---
//   6013d378 thunk_EXT_FUN_0000b532


undefined4 * FUN_600dc4d6(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  iVar1 = thunk_EXT_FUN_0000b532(0x28);
  param_1[3] = iVar1;
  param_1[5] = iVar1 + 0x28;
  iVar2 = iVar1 + 4;
  do {
    *(undefined2 *)(iVar2 + -4) = 0xffff;
    iVar3 = iVar2 + 4;
    *(undefined2 *)(iVar2 + -2) = 0xffff;
    iVar2 = iVar3;
  } while (iVar1 + 0x2c != iVar3);
  param_1[4] = iVar1 + 0x28;
  return param_1;
}


