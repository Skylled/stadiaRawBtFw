// 600a2f3c  FUN_600a2f3c  size=208 bytes
// --- callers ---
//   600a29a0 FUN_600a29a0
//   600a2884 FUN_600a2884
//   600f2532 FUN_600f2532
//   600a96d8 FUN_600a96d8
//   6009e70c FUN_6009e70c
//   600f20f6 FUN_600f20f6
// --- callees ---
//   600a2e68 FUN_600a2e68
//   600a25f8 FUN_600a25f8
//   6009e2e0 FUN_6009e2e0


void FUN_600a2f3c(char param_1,byte param_2)

{
  int iVar1;
  undefined1 uVar2;
  code *pcVar3;
  
  iVar1 = DAT_600a3010;
  pcVar3 = *(code **)(DAT_600a300c + 0xb28);
  *(byte *)(DAT_600a3010 + 0x608) = ~param_2 & *(byte *)(DAT_600a3010 + 0x608);
  if (*(char *)(iVar1 + 0x61e) != '\0') {
    if (param_1 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 10;
    }
    *(undefined1 *)(iVar1 + 0x613) = uVar2;
    if (((*(byte *)(iVar1 + 0x61e) & 8) == 0) && (*(char *)(iVar1 + 0x608) == '\0')) {
      FUN_6009e2e0();
      *(undefined1 *)(iVar1 + 0x61d) = 0;
      *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) + 1;
      FUN_600a25f8();
      if ((*(char *)(iVar1 + 0x613) == '\0') && ((*(byte *)(DAT_600a300c + 0x816) & 0x40) != 0)) {
        FUN_600a2e68();
      }
      *(undefined4 *)(iVar1 + 0x38) = 0;
      *(undefined1 *)(iVar1 + 0x61e) = 0;
      *(undefined4 *)(iVar1 + 0x34) = 0;
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1 + 0x613);
      }
    }
  }
  return;
}


