// 600d1178  FUN_600d1178  size=58 bytes
// --- callers ---
//   600d09c4 FUN_600d09c4
//   600d0a90 FUN_600d0a90
//   600d07d4 FUN_600d07d4
//   600d0a4e FUN_600d0a4e
//   600d0894 FUN_600d0894
// --- callees ---
//   600d0ede FUN_600d0ede


undefined4 FUN_600d1178(int param_1,undefined4 param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  undefined1 uVar2;
  
  if (param_3 == (undefined1 *)0x0) {
    return 4;
  }
  switch(param_2) {
  case 2:
    uVar1 = 0xf;
    break;
  case 3:
    uVar1 = 0x10;
    break;
  case 4:
    uVar1 = 6;
    break;
  case 5:
    uVar1 = 7;
    break;
  case 6:
    uVar2 = *(undefined1 *)(param_1 + 0xce);
    goto LAB_600d119a;
  case 7:
    uVar2 = *(undefined1 *)(param_1 + 0xcc);
LAB_600d119a:
    *param_3 = uVar2;
    return 0;
  case 8:
    uVar1 = 9;
    break;
  default:
    return 1;
  }
  uVar1 = FUN_600d0ede(param_1,uVar1);
  return uVar1;
}


