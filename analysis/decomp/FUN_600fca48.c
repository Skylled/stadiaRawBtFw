// 600fca48  FUN_600fca48  size=52 bytes
// --- callers ---
//   600fca7c FUN_600fca7c
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600fca48(undefined4 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  uVar2 = *param_1;
  uVar1 = *(undefined1 *)(param_1 + 7);
  thunk_EXT_FUN_0000b5ba(param_1,0,0x204);
  *param_1 = uVar2;
  *(undefined1 *)(param_1 + 7) = uVar1;
  return;
}


