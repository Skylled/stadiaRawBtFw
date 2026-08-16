// 600ad8fc  FUN_600ad8fc  size=216 bytes
// --- callers ---
//   600f5bfc FUN_600f5bfc
//   600f5ede FUN_600f5ede
// --- callees ---
//   600b0548 FUN_600b0548
//   600f6dc6 FUN_600f6dc6
//   600f3bde FUN_600f3bde
//   600f7138 FUN_600f7138
//   600f5a98 FUN_600f5a98


void FUN_600ad8fc(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  undefined1 local_11;
  
  iVar1 = FUN_600b0548(param_1 + 0xd);
  local_18 = DAT_600ad9d4;
  for (local_11 = 0; local_11 < 10; local_11 = local_11 + 1) {
    if (*(char *)(local_18 + 0x2d) != '\0') {
      if ((iVar1 != 0) && (iVar2 = FUN_600f7138(iVar1,*(undefined1 *)(local_18 + 0x2c)), iVar2 != 0)
         ) {
        FUN_600f5a98(*(undefined1 *)(local_18 + 0x2c),param_1,1,1);
      }
      if (*(int *)(local_18 + 0x14) != 0) {
        (**(code **)(local_18 + 0x14))
                  (*(undefined1 *)(local_18 + 0x2c),param_1 + 0xd,
                   CONCAT11(*(undefined1 *)(param_1 + 0xfb),*(undefined1 *)(local_18 + 0x2c)),1,0,
                   *(undefined1 *)(param_1 + 0x13));
      }
    }
    local_18 = local_18 + 0x30;
  }
  iVar1 = FUN_600f6dc6(param_1);
  if ((iVar1 != 0) && (*(short *)(param_1 + 0x18) == 4)) {
    FUN_600f3bde(param_1 + 0xd,0xffff,*(undefined1 *)(param_1 + 0x13));
  }
  return;
}


