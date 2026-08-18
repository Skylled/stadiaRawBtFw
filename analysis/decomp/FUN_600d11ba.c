// 600d11ba  FUN_600d11ba  size=80 bytes
// --- callers ---
//   600d0894 FUN_600d0894
// --- callees ---
//   600d0ede FUN_600d0ede


undefined4 FUN_600d11ba(int param_1,undefined4 param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  undefined1 uVar2;
  
  switch(param_2) {
  case 1:
    uVar1 = 0x12;
    break;
  default:
    return 1;
  case 3:
    uVar1 = 0x11;
    break;
  case 6:
    if (param_3 == (undefined1 *)0x0) {
      return 1;
    }
    uVar2 = *param_3;
LAB_600d11e0:
    *(undefined1 *)(param_1 + 0xce) = uVar2;
    return 0;
  case 7:
    if (*(char *)(param_1 + 0xce) != '\x03') {
      if (param_3 == (undefined1 *)0x0) {
        return 1;
      }
      *(undefined1 *)(param_1 + 0xcc) = *param_3;
      uVar2 = 3;
      goto LAB_600d11e0;
    }
    param_3 = (undefined1 *)(param_1 + 0xcc);
    uVar1 = 8;
    break;
  case 10:
    uVar1 = 0xc;
    break;
  case 0xb:
    uVar1 = 0xd;
    break;
  case 0xc:
    uVar1 = 10;
    break;
  case 0xe:
    uVar1 = 0xb;
  }
  uVar1 = FUN_600d0ede(param_1,uVar1,param_3);
  return uVar1;
}


