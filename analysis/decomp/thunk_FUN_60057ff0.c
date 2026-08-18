// 600d34f6  thunk_FUN_60057ff0  size=4 bytes
// --- callers ---
//   60058060 FUN_60058060
//   600d34fa FUN_600d34fa
// --- callees ---


int thunk_FUN_60057ff0(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iStack_20;
  undefined4 uStack_1c;
  
  if (*DAT_60058058 != '\0') {
    iStack_20 = param_3;
    uStack_1c = param_4;
    uVar2 = FUN_6005856c();
    FUN_600cc090(&iStack_20,uVar2,10,DAT_6005805c,0x28,0);
    iVar1 = iStack_20;
    if (iStack_20 == 0) {
      param_2 = 0;
    }
    else {
      iVar3 = iStack_20 + 0xc;
      iVar4 = *(int *)(iStack_20 + 0x14);
      thunk_EXT_FUN_0000b50a(iVar3,param_1,param_2);
      if (*(int *)(iVar1 + 0x14) != 0) {
        if (*(char *)(*(int *)(iVar1 + 0xc) + *(int *)(iVar1 + 0x14) + -1) == '\n') {
          FUN_60101b5a(iVar3);
        }
      }
      param_2 = *(int *)(iVar1 + 0x14) - iVar4;
      FUN_600cbfa0(uStack_1c,iVar1);
    }
  }
  return param_2;
}


