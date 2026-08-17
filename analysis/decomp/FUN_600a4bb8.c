// 600a4bb8  FUN_600a4bb8  size=158 bytes
// --- callers ---
//   600a4c5c FUN_600a4c5c
//   600a51a8 FUN_600a51a8
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600a4b1c FUN_600a4b1c


void FUN_600a4bb8(int param_1,undefined1 param_2)

{
  int iVar1;
  undefined1 auStack_10 [6];
  char local_a;
  
  if (((*(ushort *)(param_1 + 0x2a) & 0x10) != 0) &&
     (iVar1 = FUN_600a4b1c(param_1,param_2), iVar1 == 1)) {
    thunk_EXT_FUN_0000b572(auStack_10,param_1 + 0x10,6);
    local_a = '\x01';
    if (*(int *)(DAT_600a4c58 + 0x1134) != 0) {
      (**(code **)(DAT_600a4c58 + 0x1134))(9,auStack_10);
    }
    if (local_a != '\0') {
      *(byte *)(param_1 + 0x59) = *(byte *)(param_1 + 0x59) | 4;
      *(ushort *)(param_1 + 0x2a) = *(ushort *)(param_1 + 0x2a) & 0xffcf;
      *(ushort *)(param_1 + 0x2a) = *(ushort *)(param_1 + 0x2a) & 0xfffd;
    }
  }
  return;
}


