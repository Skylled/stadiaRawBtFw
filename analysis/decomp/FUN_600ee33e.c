// 600ee33e  FUN_600ee33e  size=250 bytes
// --- callers ---
// --- callees ---
//   60093d20 FUN_60093d20
//   6009362c FUN_6009362c
//   600944c0 FUN_600944c0
//   600936d4 FUN_600936d4


void FUN_600ee33e(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = FUN_600944c0(param_1 + 8);
  if (iVar3 != 0) {
    bVar1 = *(byte *)(iVar3 + 0xb);
    cVar2 = *(char *)(param_1 + 0xe);
    if (cVar2 == '\x02') {
      *(byte *)(iVar3 + 0xb) = *(byte *)(iVar3 + 0xb) & 0xf8;
      if ((bVar1 & 1) == 0) {
        *(byte *)(iVar3 + 0xb) = *(byte *)(iVar3 + 0xb) | 4;
      }
      else {
        *(byte *)(iVar3 + 0xb) = *(byte *)(iVar3 + 0xb) | 2;
      }
    }
    else if (cVar2 == '\x06') {
      *(byte *)(iVar3 + 0xb) = *(byte *)(iVar3 + 0xb) & 0xfe;
    }
    else if (cVar2 == '\0') {
      if (*(char *)(param_1 + 0x12) == '\0') {
        FUN_6009362c(param_1 + 8);
        FUN_60093d20(param_1 + 8,0,1);
      }
      else {
        *(byte *)(iVar3 + 0xb) = *(byte *)(iVar3 + 0xb) & 0xf8;
        if ((*(byte *)(iVar3 + 0x18) & 0x30) != 0) {
          *(byte *)(iVar3 + 0x19) = *(byte *)(iVar3 + 0x18) & 0x30 | *(byte *)(iVar3 + 0x19);
          FUN_600936d4(param_1 + 8,*(undefined1 *)(iVar3 + 0x18));
          FUN_60093d20(param_1 + 8,0,1);
        }
      }
    }
  }
  return;
}


