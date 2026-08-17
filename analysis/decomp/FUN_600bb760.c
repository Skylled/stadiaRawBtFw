// 600bb760  FUN_600bb760  size=62 bytes
// --- callers ---
//   600ba1c4 FUN_600ba1c4
// --- callees ---
//   600f8c6a FUN_600f8c6a


undefined4 FUN_600bb760(undefined1 param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 2:
  case 4:
  case 6:
  case 8:
  case 10:
  case 0xc:
  case 0xe:
  case 0x12:
    FUN_600f8c6a(param_3,1,param_2,0x2a0,0);
    uVar1 = 1;
    break;
  default:
    uVar1 = 0;
  }
  return uVar1;
}


