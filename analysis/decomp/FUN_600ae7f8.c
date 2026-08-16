// 600ae7f8  FUN_600ae7f8  size=270 bytes
// --- callers ---
//   600f6516 FUN_600f6516
// --- callees ---
//   600f6be6 FUN_600f6be6
//   600ff9fe FUN_600ff9fe
//   600f80c4 FUN_600f80c4
//   600f6b96 FUN_600f6b96
//   600c7eb8 FUN_600c7eb8


void FUN_600ae7f8(int param_1,undefined4 param_2,byte *param_3)

{
  ushort uVar1;
  int iVar2;
  byte local_9;
  
  uVar1 = (ushort)param_3[1] * 0x100 + (ushort)*param_3;
  if (*(short *)(param_1 + 0x18) == 4) {
    if (uVar1 < 0x17) {
      *(undefined2 *)(param_1 + 0x1a) = 0x17;
    }
    else if (uVar1 < 0x206) {
      *(ushort *)(param_1 + 0x1a) = uVar1;
    }
    else {
      *(undefined2 *)(param_1 + 0x1a) = 0x205;
    }
    FUN_600f80c4(param_1 + 0xd,4,*(undefined2 *)(param_1 + 0x1a));
    iVar2 = FUN_600c7eb8(param_1,3,param_1 + 0x1a);
    if (iVar2 != 0) {
      FUN_600ff9fe(param_1,iVar2);
      for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
        if (*(char *)(DAT_600ae908 + (uint)local_9 * 0x30 + 0x1095) != '\0') {
          FUN_600f6b96(CONCAT11(*(undefined1 *)(param_1 + 0xfb),
                                *(undefined1 *)(DAT_600ae908 + (uint)local_9 * 0x30 + 0x1094)),0,4,
                       param_1 + 0x1a);
        }
      }
    }
  }
  else {
    FUN_600f6be6(param_1,6,2,0,0);
  }
  return;
}


