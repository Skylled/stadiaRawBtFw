// 600a12a4  FUN_600a12a4  size=56 bytes
// --- callers ---
//   60093a30 FUN_60093a30
// --- callees ---


undefined4 FUN_600a12a4(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_600a12dc;
  if (*(byte *)(DAT_600a12dc + 0x881) < 2) {
    uVar2 = 0xc;
  }
  else {
    uVar2 = *(undefined4 *)(DAT_600a12dc + 0x80a);
    *param_1 = *(undefined4 *)(DAT_600a12dc + 0x806);
    param_1[1] = uVar2;
    *(undefined2 *)(param_1 + 2) = *(undefined2 *)(iVar1 + 0x80e);
    uVar2 = 0;
  }
  return uVar2;
}


