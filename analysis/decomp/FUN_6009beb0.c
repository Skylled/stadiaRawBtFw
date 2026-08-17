// 6009beb0  FUN_6009beb0  size=104 bytes
// --- callers ---
//   600b59ec FUN_600b59ec
//   600979e4 FUN_600979e4
// --- callees ---
//   6009ff18 FUN_6009ff18
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 FUN_6009beb0(undefined4 param_1,byte *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_6009ff18(param_1);
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 0x72) & 2) == 0)) {
    uVar2 = 0;
  }
  else {
    *param_2 = *(byte *)(iVar1 + 0x6b);
    thunk_EXT_FUN_0000b572(param_1,iVar1 + 0x6c,6);
    if ((*(byte *)(DAT_6009bf18 + 0x831) & 0x40) != 0) {
      *param_2 = *param_2 | 2;
    }
    uVar2 = 1;
  }
  return uVar2;
}


