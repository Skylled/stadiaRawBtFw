// 600f7912  FUN_600f7912  size=150 bytes
// --- callers ---
//   600f5d0a FUN_600f5d0a
//   600f5db4 FUN_600f5db4
//   600be060 FUN_600be060
//   600bde90 FUN_600bde90
// --- callees ---
//   600b5e00 FUN_600b5e00
//   600f8450 FUN_600f8450
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600bcc30 FUN_600bcc30


undefined4 FUN_600f7912(undefined2 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_600bcc30(0,param_1);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = FUN_600f8450(iVar1,param_2);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      if ((*(char *)(param_2 + 0x24) == '\0') || (*(char *)(param_2 + 0x26) == '\0')) {
        *(undefined1 *)(param_2 + 0x30) = 0;
        *(undefined1 *)(param_2 + 0x32) = 0;
        if ((*(char *)(param_2 + 2) != '\0') && (0x248 < *(ushort *)(param_2 + 4))) {
          *(undefined2 *)(param_2 + 4) = 0x248;
        }
      }
      thunk_EXT_FUN_0000b572(iVar1 + 0xc,param_2,0x48);
      FUN_600b5e00(iVar1,0x18,param_2);
      uVar3 = 1;
    }
  }
  return uVar3;
}


