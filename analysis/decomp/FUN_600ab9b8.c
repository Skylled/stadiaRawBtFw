// 600ab9b8  FUN_600ab9b8  size=338 bytes
// --- callers ---
//   600fef54 FUN_600fef54
//   600fefd8 FUN_600fefd8
//   600ab88c FUN_600ab88c
//   600c65b0 FUN_600c65b0
//   600c611c FUN_600c611c
// --- callees ---
//   600ab564 FUN_600ab564
//   600f5a98 FUN_600f5a98
//   600afd28 FUN_600afd28
//   600af51c FUN_600af51c
//   600f6132 FUN_600f6132
//   600f59c2 FUN_600f59c2
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f3ed6 FUN_600f3ed6
//   600f592e FUN_600f592e
//   600f6dc6 FUN_600f6dc6
//   600f6d9c FUN_600f6d9c
//   600b05f0 FUN_600b05f0


void FUN_600ab9b8(char param_1)

{
  int iVar1;
  int iVar2;
  int local_18;
  byte local_13;
  byte local_12;
  byte local_11;
  int *local_10;
  int local_c;
  
  iVar1 = FUN_600afd28(param_1);
  if ((param_1 != '\0') && (iVar1 != 0)) {
    local_18 = DAT_600abb0c;
    for (local_12 = 0; local_12 < 10; local_12 = local_12 + 1) {
      if ((*(char *)(local_18 + 0x25) != '\0') && (param_1 == *(char *)(local_18 + 0x24))) {
        FUN_600ab564(*(undefined2 *)(local_18 + 0x20));
      }
      local_18 = local_18 + 0x28;
    }
    FUN_600af51c(iVar1);
    local_c = DAT_600abb10;
    for (local_11 = 0; local_11 < 10; local_11 = local_11 + 1) {
      if (*(char *)(local_c + 0xfa) != '\0') {
        iVar2 = FUN_600f6132(local_c);
        if ((iVar2 != 0) && (iVar2 = FUN_600f59c2(param_1,local_c), iVar2 != 0)) {
          FUN_600f5a98(param_1,local_c,0,1);
          iVar2 = FUN_600f6dc6(local_c);
          if (iVar2 == 0) {
            FUN_600f592e(local_c);
          }
        }
        local_10 = (int *)(DAT_600abb10 + 0x1248);
        for (local_13 = 0; local_13 < 6; local_13 = local_13 + 1) {
          if (((char)local_10[0x17] != '\0') && (param_1 == *(char *)(local_10[1] + 0x2c))) {
            if (*(char *)(*local_10 + 0xfb) == *(char *)(local_c + 0xfb)) {
              FUN_600f6d9c(local_10);
              break;
            }
          }
          local_10 = local_10 + 0x18;
        }
      }
      local_c = local_c + 0x10c;
    }
    FUN_600b05f0(param_1);
    FUN_600f3ed6(param_1,0,0);
    thunk_EXT_FUN_0000b5ba(iVar1,0,0x30);
  }
  return;
}


