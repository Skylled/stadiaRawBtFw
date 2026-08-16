// 600ad710  FUN_600ad710  size=224 bytes
// --- callers ---
//   600a9fce FUN_600a9fce
// --- callees ---
//   600f4d8e FUN_600f4d8e
//   600ff9fe FUN_600ff9fe
//   600d9250 FUN_600d9250
//   6006ddd8 FUN_6006ddd8


void FUN_600ad710(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int local_10;
  byte local_9;
  
  iVar3 = (uint)*(ushort *)(param_1 + 6) * 0x10c + DAT_600ad7f0;
  if (*(char *)(iVar3 + 0xfc) == '\0') {
    FUN_600f4d8e(iVar3);
    if (*(char *)(iVar3 + 0xfc) != '\0') {
      return;
    }
    while (*(int *)(iVar3 + 0x100) != 0) {
      uVar2 = FUN_600d9250(iVar3 + 0x100);
      cVar1 = FUN_600ff9fe(iVar3,uVar2);
      if (cVar1 == -0x71) break;
      if (cVar1 != '\0') {
        FUN_6006ddd8(uVar2,DAT_600ad7f4,0x209);
      }
    }
  }
  local_10 = DAT_600ad7f8;
  for (local_9 = 0; local_9 < 10; local_9 = local_9 + 1) {
    if ((*(char *)(local_10 + 0x2d) != '\0') && (*(int *)(local_10 + 0x28) != 0)) {
      (**(code **)(local_10 + 0x28))
                (CONCAT11(*(undefined1 *)(iVar3 + 0xfb),*(undefined1 *)(local_10 + 0x2c)),
                 *(undefined1 *)(iVar3 + 0xfc));
    }
    local_10 = local_10 + 0x30;
  }
  return;
}


