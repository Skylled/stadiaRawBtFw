// 6009bbb0  FUN_6009bbb0  size=122 bytes
// --- callers ---
// --- callees ---
//   600fbc02 FUN_600fbc02
//   6009bb50 FUN_6009bb50


void FUN_6009bbb0(int param_1)

{
  int iVar1;
  undefined1 auStack_20 [20];
  int local_c;
  
  iVar1 = DAT_6009bc2c;
  local_c = DAT_6009bc2c;
  if (param_1 != 0) {
    *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) & 0x3f;
    *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) | 0x40;
    *(undefined1 *)(iVar1 + 3) = *(undefined1 *)(param_1 + 4);
    *(undefined1 *)(iVar1 + 2) = *(undefined1 *)(param_1 + 5);
    *(undefined1 *)(iVar1 + 1) = *(undefined1 *)(param_1 + 6);
    iVar1 = FUN_600fbc02(DAT_6009bc30,0x10,param_1 + 4,3,auStack_20);
    if (iVar1 == 0) {
      FUN_6009bb50(0);
    }
    else {
      FUN_6009bb50(auStack_20);
    }
  }
  return;
}


