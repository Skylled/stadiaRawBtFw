// 600a76cc  FUN_600a76cc  size=378 bytes
// --- callers ---
// --- callees ---
//   600b4714 FUN_600b4714
//   600f1ce4 FUN_600f1ce4
//   600b45b4 FUN_600b45b4
//   600a8108 FUN_600a8108
//   600a5670 FUN_600a5670
//   6009ff18 FUN_6009ff18
//   600b25c8 FUN_600b25c8


void FUN_600a76cc(void)

{
  int iVar1;
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  
  iVar1 = DAT_600a786c;
  local_14 = DAT_600a786c;
  *(undefined4 *)(DAT_600a786c + 0x11a4) = 0;
  local_18 = FUN_6009ff18(iVar1 + 0x118e);
  switch(*(undefined1 *)(local_14 + 0x118c)) {
  case 2:
    FUN_600a5670();
    break;
  case 3:
    if ((*(byte *)(DAT_600a786c + 0x118d) & 0x10) == 0) {
      FUN_600b25c8(local_14 + 0x118e);
    }
    FUN_600a8108(0);
    if (*(int *)(DAT_600a786c + 0x1128) != 0) {
      if (local_18 == 0) {
        local_1c[0] = 0;
        (**(code **)(DAT_600a786c + 0x1128))(local_14 + 0x118e,0,local_1c,8);
      }
      else {
        (**(code **)(DAT_600a786c + 0x1128))(local_18 + 0x10,local_18 + 0x16,local_18 + 0x2c,8);
      }
    }
    break;
  case 4:
    FUN_600b45b4(local_14 + 0x118e,0);
    break;
  case 5:
    FUN_600b4714(local_14 + 0x118e);
    break;
  default:
    FUN_600a8108(0);
    break;
  case 9:
    FUN_600a8108(0);
    if (*(int *)(DAT_600a786c + 0x1128) != 0) {
      if (local_18 == 0) {
        local_1c[0] = 0;
        (**(code **)(DAT_600a786c + 0x1128))(local_14 + 0x118e,0,local_1c,8);
      }
      else {
        (**(code **)(DAT_600a786c + 0x1128))(local_18 + 0x10,local_18 + 0x16,local_18 + 0x2c,8);
      }
    }
    break;
  case 10:
    if (local_18 != 0) {
      FUN_600f1ce4(local_18,5,*(undefined2 *)(local_18 + 0xc));
      FUN_600a8108(0);
    }
  }
  return;
}


