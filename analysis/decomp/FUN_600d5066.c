// 600d5066  FUN_600d5066  size=88 bytes
// --- callers ---
//   600d50be FUN_600d50be
// --- callees ---
//   600cb598 key_value_store__600cb598
//   601010c8 FUN_601010c8


uint FUN_600d5066(int param_1)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  ushort local_12 [3];
  
  *(undefined2 *)(param_1 + 0x16) = 0;
  *(undefined2 *)(param_1 + 0x18) = 0;
  local_12[0] = 0;
  uVar2 = FUN_601010c8(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),local_12);
  if ((uVar2 & 0xff) == 0) {
    uVar1 = *(ushort *)(param_1 + 0x1a);
    if (uVar1 < local_12[0]) {
      uVar3 = local_12[0] - uVar1;
      if (*(ushort *)(param_1 + 0x14) <= (ushort)(local_12[0] - uVar1)) {
        uVar3 = *(ushort *)(param_1 + 0x14);
      }
      uVar2 = key_value_store__600cb598
                        (*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                         *(undefined4 *)(param_1 + 0x10),uVar3,uVar1);
      if ((uVar2 & 0xff) != 0) {
        return uVar2;
      }
      *(ushort *)(param_1 + 0x18) = uVar3;
      *(ushort *)(param_1 + 0x1a) = uVar3 + *(short *)(param_1 + 0x1a);
    }
    uVar2 = 0;
  }
  return uVar2;
}


