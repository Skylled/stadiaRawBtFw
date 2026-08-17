// 6009ef10  FUN_6009ef10  size=136 bytes
// --- callers ---
//   600f15b0 FUN_600f15b0
//   6009f1fc FUN_6009f1fc
//   6009f27c FUN_6009f27c
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d3a0 thunk_EXT_FUN_0000b572


bool FUN_6009ef10(undefined4 param_1)

{
  int *piVar1;
  bool bVar2;
  
  piVar1 = DAT_6009ef98;
  bVar2 = (char)DAT_6009ef98[2] != *(char *)((int)DAT_6009ef98 + 9);
  if (bVar2) {
    thunk_EXT_FUN_0000b572(param_1,(uint)*(byte *)((int)DAT_6009ef98 + 9) * 6 + *DAT_6009ef98,6);
    thunk_EXT_FUN_0000b5ba((uint)*(byte *)((int)piVar1 + 9) * 6 + *piVar1,0,6);
    *(char *)((int)piVar1 + 9) = *(char *)((int)piVar1 + 9) + '\x01';
    *(byte *)((int)piVar1 + 9) =
         *(byte *)((int)piVar1 + 9) -
         *(byte *)(DAT_6009ef9c + 0xa6b) *
         (*(byte *)((int)piVar1 + 9) / *(byte *)(DAT_6009ef9c + 0xa6b));
  }
  return bVar2;
}


