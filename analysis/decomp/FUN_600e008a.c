// 600e008a  FUN_600e008a  size=64 bytes
// --- callers ---
//   600849a4 state_machine__600849a4
//   600848bc state_machine__600848bc
// --- callees ---
//   60084644 state_machine__60084644
//   6013d310 thunk_EXT_FUN_0000b52a


void FUN_600e008a(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  while (puVar1 = *(undefined4 **)(param_1 + 0x38), *(undefined4 **)(param_1 + 0x48) != puVar1) {
    state_machine__60084644(param_1,*puVar1,puVar1[1]);
    if (*(int *)(param_1 + 0x38) == *(int *)(param_1 + 0x40) + -8) {
      thunk_EXT_FUN_0000b52a(*(undefined4 *)(param_1 + 0x3c));
      iVar2 = *(int *)(*(int *)(param_1 + 0x44) + 4);
      *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 4;
      *(int *)(param_1 + 0x3c) = iVar2;
      *(int *)(param_1 + 0x40) = iVar2 + 0x200;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x38) + 8;
    }
    *(int *)(param_1 + 0x38) = iVar2;
  }
  return;
}


