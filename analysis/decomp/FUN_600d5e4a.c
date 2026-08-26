// 600d5e4a  FUN_600d5e4a  size=34 bytes
// --- callers ---
//   600d6866 FUN_600d6866
//   600d67e8 FUN_600d67e8
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d378 thunk_EXT_FUN_0000b532


int * FUN_600d5e4a(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = thunk_EXT_FUN_0000b532(0x18);
  iVar2 = thunk_EXT_FUN_0000b5ba(uVar1,0,0x18);
  *param_1 = iVar2;
  *(undefined1 *)(iVar2 + 4) = 0;
  *(int *)(iVar2 + 0xc) = iVar2 + 4;
  *(int *)(iVar2 + 0x10) = iVar2 + 4;
  return param_1;
}


