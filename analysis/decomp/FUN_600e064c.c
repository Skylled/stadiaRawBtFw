// 600e064c  FUN_600e064c  size=52 bytes
// --- callers ---
//   6008506c evp__6008506c
// --- callees ---
//   600e092c FUN_600e092c
//   600e09dc thunk_FUN_600cdd6c
//   600e04f4 FUN_600e04f4


void FUN_600e064c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar2 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  iVar1 = FUN_600e092c(0x101);
  if (iVar1 != 0) {
    thunk_FUN_600cdd6c(iVar1,0x100,param_1,&uStack_c,uVar2,&uStack_c);
    *(undefined1 *)(iVar1 + 0x100) = 0;
    FUN_600e04f4(iVar1);
  }
  return;
}


