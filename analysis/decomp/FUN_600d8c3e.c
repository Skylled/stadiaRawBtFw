// 600d8c3e  FUN_600d8c3e  size=60 bytes
// --- callers ---
//   600d8c7a FUN_600d8c7a
//   6006b10c led_driver_lp5562__6006b10c
// --- callees ---
//   600d8c1a FUN_600d8c1a


void FUN_600d8c3e(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_1 + 8;
  cVar1 = FUN_600d8c1a(iVar3,1,0,200,param_4);
  if (cVar1 == '\0') {
    if (*(char *)(param_1 + 4) == '\0') {
      uVar2 = 0x40;
    }
    else {
      uVar2 = 0xc0;
    }
    cVar1 = FUN_600d8c1a(iVar3,0,uVar2,200,param_4);
    if (cVar1 == '\0') {
      FUN_600d8c1a(iVar3,0x70,0,200,param_4);
    }
  }
  return;
}


