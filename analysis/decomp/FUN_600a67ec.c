// 600a67ec  FUN_600a67ec  size=686 bytes
// --- callers ---
//   600f21ba FUN_600f21ba
//   600a96d8 FUN_600a96d8
// --- callees ---
//   600f9d16 FUN_600f9d16
//   600a8108 FUN_600a8108
//   6009feb8 FUN_6009feb8
//   600a6720 FUN_600a6720
//   600a7b44 FUN_600a7b44
//   600f1ce4 FUN_600f1ce4
//   6013d168 thunk_EXT_FUN_0000b554
//   600f1f82 FUN_600f1f82
//   600a804c FUN_600a804c


void FUN_600a67ec(undefined2 param_1,char param_2)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  char local_23;
  
  cVar3 = *(char *)(DAT_600a6a9c + 0x118c);
  iVar4 = FUN_6009feb8(param_1);
  bVar2 = false;
  if ((param_2 == '#') || (param_2 == '*')) {
    FUN_600a6720(param_1);
  }
  else {
    *(undefined4 *)(DAT_600a6a9c + 0x1168) = 0;
    FUN_600a804c();
    if (((iVar4 != 0) && ((*(byte *)(DAT_600a6a9c + 0x118d) & 1) != 0)) &&
       ((*(byte *)(DAT_600a6a9c + 0x118d) & 4) == 0)) {
      *(ushort *)(iVar4 + 0x54) = *(ushort *)(iVar4 + 0x54) & 0xffef;
      FUN_600f9d16(*(undefined2 *)(iVar4 + 0xc));
    }
    if (iVar4 != 0) {
      bVar1 = *(byte *)(iVar4 + 0x59);
      *(byte *)(iVar4 + 0x59) = *(byte *)(iVar4 + 0x59) & 0xfd;
      if (((*(char *)(DAT_600a6a9c + 0x118c) != '\0') &&
          ((*(byte *)(DAT_600a6a9c + 0x118d) & 1) != 0)) &&
         (iVar5 = thunk_EXT_FUN_0000b554(iVar4 + 0x10,DAT_600a6aa0,6), iVar5 == 0)) {
        bVar2 = true;
      }
      FUN_600a8108(0);
      if (*(char *)(iVar4 + 0x50) == '\x01') {
        local_23 = param_2;
        if ((param_2 == '\f') && ((*(ushort *)(iVar4 + 0x2a) & 6) == 6)) {
          local_23 = '\0';
        }
        if ((*(int *)(DAT_600a6a9c + 0x1128) != 0) && (cVar3 != '\0')) {
          (**(code **)(DAT_600a6a9c + 0x1128))(iVar4 + 0x10,iVar4 + 0x16,iVar4 + 0x2c,local_23);
        }
        *(undefined1 *)(iVar4 + 0x50) = 0;
        if (bVar2) {
          *(ushort *)(iVar4 + 0x54) = *(ushort *)(iVar4 + 0x54) & 0xffef;
          if (local_23 == '\0') {
            FUN_600f9d16(*(undefined2 *)(iVar4 + 0xc));
          }
          else {
            FUN_600f1ce4(iVar4,0x13,*(undefined2 *)(iVar4 + 0xc));
          }
        }
        else if (local_23 == '\0') {
          *(ushort *)(iVar4 + 0x2a) = *(ushort *)(iVar4 + 0x2a) | 2;
          cVar3 = FUN_600a7b44(iVar4);
          if (cVar3 != '\x01') {
            FUN_600f1f82(iVar4,cVar3,0);
          }
        }
        else {
          if ((bVar1 & 2) == 0) {
            if (local_23 == '#') {
              *(byte *)(iVar4 + 0x59) = *(byte *)(iVar4 + 0x59) | 2;
            }
            else if ((local_23 == '\x06') && ((*(byte *)(iVar4 + 0x59) & 0x11) == 0x11)) {
              *(byte *)(iVar4 + 0x59) = *(byte *)(iVar4 + 0x59) | 2;
              *(ushort *)(iVar4 + 0x2a) = *(ushort *)(iVar4 + 0x2a) & 0xffef;
            }
            if ((*(byte *)(iVar4 + 0x59) & 2) != 0) {
              FUN_600a7b44(iVar4);
              return;
            }
          }
          FUN_600f1f82(iVar4,10,0);
          if ((*(byte *)(DAT_600a6a9c + 0x118d) & 4) != 0) {
            FUN_600f1ce4(iVar4,5,*(undefined2 *)(iVar4 + 0xc));
          }
        }
      }
      else if (((*(int *)(DAT_600a6a9c + 0x1128) != 0) && (param_2 != '\0')) && (cVar3 != '\0')) {
        (**(code **)(DAT_600a6a9c + 0x1128))(iVar4 + 0x10,iVar4 + 0x16,iVar4 + 0x2c,param_2);
      }
    }
  }
  return;
}


