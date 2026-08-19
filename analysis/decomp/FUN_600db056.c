// 600db056  FUN_600db056  size=76 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 FUN_600db056(int param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x18);
  if (param_3 <= uVar1) {
    uVar1 = param_3;
  }
  if (uVar1 == 0) {
    uVar1 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x1c);
    if (param_3 <= uVar1) {
      uVar1 = param_3;
    }
    thunk_EXT_FUN_0000b572(param_2,*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x1c),uVar1);
    *(uint *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + uVar1;
  }
  else {
    thunk_EXT_FUN_0000b572(param_2,*(int *)(param_1 + 8) + *(int *)(param_1 + 0x18),uVar1);
    *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + uVar1;
  }
  *param_4 = uVar1;
  return 0;
}


