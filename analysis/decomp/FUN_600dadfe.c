// 600dadfe  FUN_600dadfe  size=30 bytes
// --- callers ---
//   60076e1c FUN_60076e1c
//   600dae1c FUN_600dae1c
//   600dadfe FUN_600dadfe
// --- callees ---
//   6013d310 thunk_EXT_FUN_0000b52a
//   600dadfe FUN_600dadfe


void FUN_600dadfe(undefined4 param_1,int param_2)

{
  int iVar1;
  
  while (param_2 != 0) {
    FUN_600dadfe(param_1,*(undefined4 *)(param_2 + 0xc));
    iVar1 = *(int *)(param_2 + 8);
    thunk_EXT_FUN_0000b52a(param_2);
    param_2 = iVar1;
  }
  return;
}


