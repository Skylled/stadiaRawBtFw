// 600a6720  FUN_600a6720  size=190 bytes
// --- callers ---
//   600a6b20 FUN_600a6b20
//   600a67ec FUN_600a67ec
// --- callees ---
//   6006e154 FUN_6006e154
//   600aa340 FUN_600aa340
//   600a80b4 FUN_600a80b4
//   6009feb8 FUN_6009feb8


void FUN_600a6720(short param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  
  if (*(int *)(DAT_600a67e0 + 0x1168) == 0) {
    uVar1 = FUN_6006e154();
    *(undefined4 *)(DAT_600a67e0 + 0x1168) = uVar1;
  }
  iVar2 = FUN_6006e154();
  if ((uint)(iVar2 - *(int *)(DAT_600a67e0 + 0x1168)) < *(uint *)(DAT_600a67e0 + 0x116c)) {
    if (param_1 == -1) {
      local_c = FUN_600a80b4(1);
      if (local_c == 0) {
        local_c = FUN_600a80b4(2);
      }
    }
    else {
      local_c = FUN_6009feb8(param_1);
    }
    if (local_c != 0) {
      if ((*(char *)(local_c + 0x50) == '\x01') || (*(char *)(local_c + 0x50) == '\x02')) {
        *(undefined1 *)(local_c + 0x50) = 0;
      }
      *(int *)(DAT_600a67e0 + 0x114c) = local_c;
      *(undefined4 *)(DAT_600a67e0 + 0x1160) = DAT_600a67e4;
      FUN_600aa340(DAT_600a67e8,0xd,2);
    }
  }
  return;
}


