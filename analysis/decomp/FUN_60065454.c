// 60065454  FUN_60065454  size=106 bytes
// --- callers ---
//   60073bf0 timer__60073bf0
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 * FUN_60065454(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_80 [104];
  
  iVar1 = DAT_600654c0;
  thunk_EXT_FUN_0000b572(local_80,DAT_600654c0,0x68);
  *param_1 = param_2;
  thunk_EXT_FUN_0000b572(param_1 + 1,local_80,0x68);
  uVar2 = *(undefined4 *)(iVar1 + 0x6c);
  uVar3 = *(undefined4 *)(iVar1 + 0x70);
  uVar4 = *(undefined4 *)(iVar1 + 0x74);
  param_1[0x1b] = *(undefined4 *)(iVar1 + 0x68);
  param_1[0x1c] = uVar2;
  param_1[0x1d] = uVar3;
  param_1[0x1e] = uVar4;
  *(undefined1 *)(param_1 + 0x28) = 0;
  param_1[0x2a] = 0;
  param_1[0x2c] = 0;
  param_1[0x1f] = 0xffffffff;
  param_1[0x20] = 0;
  param_1[0x21] = 0xffffffff;
  param_1[0x22] = 0;
  param_1[0x25] = 100;
  param_1[0x26] = 10;
  param_1[0x2d] = 0x1000;
  return param_1;
}


