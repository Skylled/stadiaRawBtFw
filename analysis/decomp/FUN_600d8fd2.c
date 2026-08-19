// 600d8fd2  FUN_600d8fd2  size=108 bytes
// --- callers ---
//   6006b85c FUN_6006b85c
// --- callees ---
//   600d8fa6 FUN_600d8fa6


char FUN_600d8fd2(int param_1,byte param_2,uint param_3)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  
  if (*(byte *)(param_1 + 0xc) == 0) {
    cVar2 = '\t';
  }
  else {
    param_2 = param_2 & 0x3f;
    bVar1 = *(byte *)(param_1 + 0xf);
    if (bVar1 == 0) {
      param_3 = (uint)*(byte *)(param_1 + 0xc);
    }
    if (0x31 < param_2) {
      param_2 = 0x32;
    }
    if (bVar1 == param_2) {
      cVar2 = '\0';
    }
    else {
      bVar3 = param_2;
      if (param_3 == 0) {
        if (bVar1 < param_2) {
          bVar3 = bVar1 + 1;
        }
        else {
          bVar3 = bVar1 - 1;
        }
      }
      cVar2 = FUN_600d8fa6(param_1,0x39,bVar3 | 0x40,200);
      if (((cVar2 == '\0') && (cVar2 = FUN_600d8fa6(param_1,0x3a,bVar3 | 0xc0,200), cVar2 == '\0'))
         && (*(byte *)(param_1 + 0xf) = bVar3, param_2 != bVar3)) {
        cVar2 = '\x0e';
      }
    }
  }
  return cVar2;
}


