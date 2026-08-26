// 600d50be  FUN_600d50be  size=100 bytes
// --- callers ---
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600d5066 FUN_600d5066


uint FUN_600d50be(int param_1,int param_2,int param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  
  *param_4 = 0;
  do {
    if (param_3 == 0) {
      return 0;
    }
    if (*(ushort *)(param_1 + 0x18) <= *(ushort *)(param_1 + 0x16)) {
      uVar1 = FUN_600d5066(param_1);
      if ((uVar1 & 0xff) != 0) {
        return uVar1;
      }
      if (*(short *)(param_1 + 0x18) == 0) {
        return 0;
      }
    }
    iVar2 = (uint)*(ushort *)(param_1 + 0x18) - (uint)*(ushort *)(param_1 + 0x16);
    if (param_3 <= iVar2) {
      iVar2 = param_3;
    }
    thunk_EXT_FUN_0000b572
              (param_2,*(int *)(param_1 + 0x10) + (uint)*(ushort *)(param_1 + 0x16),iVar2);
    param_3 = param_3 - iVar2;
    *param_4 = *param_4 + iVar2;
    *(short *)(param_1 + 0x16) = (short)iVar2 + *(short *)(param_1 + 0x16);
    param_2 = param_2 + iVar2;
  } while( true );
}


