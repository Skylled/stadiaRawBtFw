// 600c01b8  FUN_600c01b8  size=200 bytes
// --- callers ---
// --- callees ---
//   600fabe0 FUN_600fabe0
//   600fabac FUN_600fabac
//   600c10a4 FUN_600c10a4
//   600c19f4 FUN_600c19f4


void FUN_600c01b8(int param_1,undefined4 param_2)

{
  ushort uVar1;
  
  switch(*(undefined1 *)(param_1 + 0x194)) {
  case 4:
  case 5:
    if (*(char *)(param_1 + 0x26) == '\x01') {
      FUN_600c10a4(param_1);
      FUN_600fabe0(param_1,0);
      FUN_600c19f4(10);
    }
    else if ((*(ushort *)(param_1 + 0x28) & 0x80) != 0) {
      uVar1 = *(ushort *)(param_1 + 0x28) & 0xff7f;
      *(ushort *)(param_1 + 0x28) = uVar1;
      FUN_600fabac(param_1,0,uVar1,param_1,param_2);
      FUN_600c19f4(10);
    }
    break;
  case 6:
  case 7:
    FUN_600c10a4(param_1);
    if (*(char *)(param_1 + 0x26) == '\0') {
      FUN_600fabe0(param_1,0);
    }
    else if ((*(ushort *)(param_1 + 0x28) & 0x80) != 0) {
      FUN_600fabe0(param_1,0);
      FUN_600c19f4(10);
    }
    break;
  case 8:
    if (*(char *)(param_1 + 0x26) == '\0') {
      FUN_600fabac(param_1,0,&switchD_600c01d0::switchdataD_600c01d4,0,param_2);
    }
    FUN_600c19f4(10);
  }
  return;
}


