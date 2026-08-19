// 600def14  FUN_600def14  size=60 bytes
// --- callers ---
//   600def50 FUN_600def50
// --- callees ---


undefined4 FUN_600def14(int param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  
  uVar2 = *(ushort *)(param_1 + 0x18e);
  if ((uVar2 == 0xffff) &&
     (uVar2 = *(ushort *)(param_1 + 0x180), *(ushort *)(param_1 + 0x180) == 0xffff)) {
    return 0;
  }
  if (*(int *)(param_1 + 0x184) != 0) {
    if (*(int *)(param_1 + 0x184) == 3) {
      uVar1 = 5;
    }
    else {
      uVar1 = 4;
    }
    return uVar1;
  }
  if (uVar2 != 0) {
    if (uVar2 < 0x14) {
      uVar1 = 2;
    }
    else {
      uVar1 = 3;
    }
    return uVar1;
  }
  return 1;
}


