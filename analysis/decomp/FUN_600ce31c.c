// 600ce31c  FUN_600ce31c  size=56 bytes
// --- callers ---
//   6007991c http_flash_writer__6007991c
//   6005dbec FUN_6005dbec
//   60079668 http_flash_writer__60079668
// --- callees ---


int FUN_600ce31c(int param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  
  for (iVar3 = 0; iVar3 != param_2; iVar3 = iVar3 + 1) {
    bVar1 = *(byte *)(param_1 + iVar3) >> 4;
    bVar2 = *(byte *)(param_1 + iVar3) & 0xf;
    if (bVar1 < 10) {
      cVar4 = bVar1 + 0x30;
    }
    else {
      cVar4 = bVar1 + 0x37;
    }
    *(char *)(param_3 + iVar3 * 2) = cVar4;
    if (bVar2 < 10) {
      cVar4 = bVar2 + 0x30;
    }
    else {
      cVar4 = bVar2 + 0x37;
    }
    *(char *)(param_3 + iVar3 * 2 + 1) = cVar4;
  }
  *(undefined1 *)(param_3 + iVar3 * 2) = 0;
  return param_3;
}


