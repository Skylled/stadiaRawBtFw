// 6009de30  FUN_6009de30  size=144 bytes
// --- callers ---
//   600f1800 FUN_600f1800
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600aa340 FUN_600aa340
//   600f34ca FUN_600f34ca


undefined4 FUN_6009de30(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_6009dec0;
  if ((*(byte *)(DAT_6009dec4 + 0x81b) & 2) == 0) {
    uVar3 = 10;
  }
  else if (((param_2 == 0) || (*(char *)(param_2 + 0x12) == '\0')) ||
          (*(char *)(param_2 + 0x12) == '\x01')) {
    if (*(char *)((int)DAT_6009dec0 + 0x32) == '\0') {
      iVar2 = FUN_600f34ca(param_1,DAT_6009dec8);
      if (iVar2 == 0) {
        uVar3 = 2;
      }
      else {
        *puVar1 = param_3;
        *(undefined1 *)((int)puVar1 + 0x32) = 1;
        thunk_EXT_FUN_0000b572(puVar1 + 0xb,param_1,6);
        FUN_600aa340(puVar1 + 1,8,0x1e);
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 2;
    }
  }
  else {
    uVar3 = 10;
  }
  return uVar3;
}


