// 600c5ef4  FUN_600c5ef4  size=98 bytes
// --- callers ---
//   600c3f04 FUN_600c3f04
// --- callees ---
//   600efcfe FUN_600efcfe
//   6009633c FUN_6009633c
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60094590 FUN_60094590
//   600c5cd8 FUN_600c5cd8


void FUN_600c5ef4(undefined4 param_1)

{
  int iVar1;
  
  *(undefined1 *)(DAT_600c5f58 + 0x149) = 1;
  iVar1 = FUN_600efcfe(DAT_600c5f5c,param_1);
  if ((iVar1 == 0) && (*(short *)(DAT_600c5f58 + 0x14a) != -1)) {
    thunk_EXT_FUN_0000b5ba(DAT_600c5f5c,0,6);
    FUN_6009633c(DAT_600c5f60);
    FUN_600c5cd8(*(undefined2 *)(DAT_600c5f58 + 0x14a));
  }
  else {
    FUN_60094590(*(undefined1 *)(DAT_600c5f58 + 0x141),param_1,1,2);
  }
  return;
}


