// 6009ee8c  FUN_6009ee8c  size=122 bytes
// --- callers ---
//   6009f8c8 FUN_6009f8c8
//   6009f6c0 FUN_6009f6c0
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


undefined4 FUN_6009ee8c(undefined4 param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  byte local_9;
  
  piVar1 = DAT_6009ef08;
  local_9 = *(byte *)((int)DAT_6009ef08 + 9);
  while( true ) {
    if (local_9 == *(byte *)(piVar1 + 2)) {
      return 0;
    }
    iVar2 = thunk_EXT_FUN_0000b554((uint)local_9 * 6 + *piVar1,param_1,6);
    if ((iVar2 == 0) && (param_2 == *(char *)((uint)local_9 + piVar1[1]))) break;
    local_9 = (local_9 + 1) -
              *(byte *)(DAT_6009ef0c + 0xa6b) *
              ((byte)(local_9 + 1) / *(byte *)(DAT_6009ef0c + 0xa6b));
  }
  return 1;
}


