// 600a730c  FUN_600a730c  size=456 bytes
// --- callers ---
//   600f2158 FUN_600f2158
// --- callees ---
//   6009a72c FUN_6009a72c
//   6009ed00 FUN_6009ed00
//   6009feb8 FUN_6009feb8
//   600a82a0 FUN_600a82a0
//   600a8108 FUN_600a8108
//   6013d168 thunk_EXT_FUN_0000b554


void FUN_600a730c(short param_1,char param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  char cVar5;
  code *pcVar6;
  undefined4 local_14;
  
  iVar2 = FUN_6009feb8(param_1);
  bVar1 = *(byte *)(DAT_600a74d4 + 0x118d);
  local_14 = 5;
  *(undefined1 *)(DAT_600a74d4 + 0x1acd) = 0;
  FUN_6009a72c();
  if (iVar2 != 0) {
    if (param_1 == *(short *)(iVar2 + 0xc)) {
      cVar5 = '\x01';
    }
    else {
      cVar5 = '\x02';
    }
    *(undefined1 *)(iVar2 + 0xee) = 0;
    *(byte *)(iVar2 + 0x59) = *(byte *)(iVar2 + 0x59) & 0x11;
    if ((*(char *)(DAT_600a74d4 + 0x118c) != '\0') &&
       (iVar3 = thunk_EXT_FUN_0000b554(DAT_600a74d8,iVar2 + 0x10,6), iVar3 == 0)) {
      FUN_600a8108(0);
      *(ushort *)(iVar2 + 0x2a) = *(ushort *)(iVar2 + 0x2a) & 0xffef;
      if (*(int *)(DAT_600a74d4 + 0x1128) != 0) {
        if (param_2 == '\x17') {
          local_14 = 0x17;
        }
        else if ((bVar1 & 1) != 0) {
          local_14 = 0xe;
        }
        (**(code **)(DAT_600a74d4 + 0x1128))(iVar2 + 0x10,iVar2 + 0x16,iVar2 + 0x2c,local_14);
      }
    }
    if (cVar5 == '\x02') {
      *(undefined1 *)(iVar2 + 0x61) = 0;
    }
    else {
      *(undefined1 *)(iVar2 + 0x60) = 0;
    }
    FUN_6009ed00(0xff,iVar2 + 0x10,0);
    if (cVar5 == '\x02') {
      *(undefined2 *)(iVar2 + 0x5e) = 0xffff;
      *(ushort *)(iVar2 + 0x2a) = *(ushort *)(iVar2 + 0x2a) & 63999;
    }
    else {
      *(undefined2 *)(iVar2 + 0xc) = 0xffff;
      *(ushort *)(iVar2 + 0x2a) = *(ushort *)(iVar2 + 0x2a) & 0xffb8;
      *(undefined1 *)(iVar2 + 0x5b) = 0;
    }
    if (*(char *)(iVar2 + 0x50) == '\t') {
      if (cVar5 == '\x02') {
        uVar4 = 6;
      }
      else {
        uVar4 = 8;
      }
      *(undefined1 *)(iVar2 + 0x50) = uVar4;
    }
    else {
      *(undefined1 *)(iVar2 + 0x50) = 0;
      *(undefined2 *)(iVar2 + 0x54) = 0;
      pcVar6 = *(code **)(iVar2 + 0xf4);
      if (pcVar6 != (code *)0x0) {
        *(undefined4 *)(iVar2 + 0xf4) = 0;
        (*pcVar6)(iVar2 + 0x10,cVar5,*(undefined4 *)(iVar2 + 0xf8),10);
      }
      FUN_600a82a0(iVar2 + 0x10,cVar5);
    }
  }
  return;
}


