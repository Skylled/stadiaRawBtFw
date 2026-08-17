// 6009be40  FUN_6009be40  size=108 bytes
// --- callers ---
//   6009e3f0 FUN_6009e3f0
//   6009b368 FUN_6009b368
// --- callees ---
//   600f0f48 FUN_600f0f48
//   6009bde4 FUN_6009bde4
//   6009f428 FUN_6009f428
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 FUN_6009be40(undefined4 param_1,undefined1 *param_2,char param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_6009bde4(param_1,*param_2);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    if ((param_3 != '\0') && (*(char *)(DAT_6009beac + 0xa6b) != '\0')) {
      FUN_6009f428(iVar1);
    }
    iVar2 = FUN_600f0f48(iVar1,param_1);
    if (iVar2 == 0) {
      thunk_EXT_FUN_0000b572(param_1,iVar1 + 100,6);
    }
    *param_2 = *(undefined1 *)(iVar1 + 0x6a);
    uVar3 = 1;
  }
  return uVar3;
}


