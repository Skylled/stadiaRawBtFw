// 60040b64  FUN_60040b64  size=66 bytes
// --- callers ---
// --- callees ---
//   6004083c FUN_6004083c


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60040b64(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int extraout_r2;
  undefined8 uVar3;
  
  do {
    uVar3 = FUN_6004083c(param_1);
    uVar2 = (uint)((ulonglong)uVar3 >> 0x20);
  } while ((int)uVar3 == 0);
  *(undefined4 *)(param_1 + 0x18) = _DAT_60040ba8;
  *(undefined4 *)(param_1 + 0x1c) = 2;
  for (iVar1 = 0; ((uVar2 & 0xff) + iVar1 & 0xff) < param_4; iVar1 = iVar1 + 1) {
    *(undefined4 *)(param_1 + (uVar2 + 0x80) * 4 + iVar1 * 4) =
         *(undefined4 *)(extraout_r2 + iVar1 * 4);
  }
  *(undefined4 *)(param_1 + 0x18) = _DAT_60040ba8;
  *(undefined4 *)(param_1 + 0x1c) = 1;
  return;
}


