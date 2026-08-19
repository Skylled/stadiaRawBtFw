// 600d94c4  FUN_600d94c4  size=36 bytes
// --- callers ---
//   6005990c sleep_driver__6005990c
// --- callees ---


void FUN_600d94c4(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = (param_1 >> 5) * 4;
  uVar1 = 1 << (param_1 & 0x1f);
  if (param_2 == 0) {
    uVar1 = uVar1 | *(uint *)(&DAT_400f4008 + iVar2);
  }
  else {
    uVar1 = *(uint *)(&DAT_400f4008 + iVar2) & ~uVar1;
  }
  *(uint *)(&DAT_400f4008 + iVar2) = uVar1;
  return;
}


