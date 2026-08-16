// 600a51a8  FUN_600a51a8  size=908 bytes
// --- callers ---
//   600a5760 FUN_600a5760
// --- callees ---
//   600f2024 FUN_600f2024
//   600f18e4 FUN_600f18e4
//   600a7b44 FUN_600a7b44
//   600a4b1c FUN_600a4b1c
//   600f18be FUN_600f18be
//   600f190a FUN_600f190a
//   600a81ac FUN_600a81ac
//   600f1746 FUN_600f1746
//   600f1898 FUN_600f1898
//   600a4bb8 FUN_600a4bb8
//   600a7ee8 FUN_600a7ee8
//   600f204a FUN_600f204a


char FUN_600a51a8(undefined4 param_1,undefined2 param_2,char param_3,undefined4 param_4,
                 undefined4 param_5,code *param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ushort local_14;
  char local_11;
  
  iVar1 = FUN_600f1746(param_1);
  iVar2 = FUN_600a7ee8(param_3,param_2,param_4,param_5);
  if (iVar2 == 0) {
    if (param_6 != (code *)0x0) {
      (*param_6)(param_1,0,param_7,4);
    }
    local_11 = '\x03';
  }
  else {
    if ((*(char *)(DAT_600a5460 + 0x1174) == '\x06') && (iVar3 = FUN_600f2024(param_2), iVar3 == 0))
    {
      local_14 = FUN_600f204a(*(undefined2 *)(iVar2 + 0xe),param_3);
    }
    else {
      local_14 = *(ushort *)(iVar2 + 0xe);
    }
    if ((*(int *)(iVar1 + 0xf4) == 0) && (*(char *)(DAT_600a5460 + 0x118c) == '\0')) {
      if (((param_3 == '\0') &&
          (((local_14 & 0x40) != 0 || (*(char *)(DAT_600a5460 + 0x1174) == '\x06')))) &&
         (((*(byte *)(DAT_600a5460 + 0x88c) & 1) == 0 || ((*(byte *)(iVar1 + 0x5c) & 1) == 0)))) {
        if (param_6 != (code *)0x0) {
          (*param_6)(param_1,0,param_7,0x14);
        }
        local_11 = '\x14';
      }
      else {
        *(int *)(iVar1 + 0xf0) = iVar2;
        *(ushort *)(iVar1 + 0x54) = local_14;
        if ((3 < *(byte *)(DAT_600a553c + 0x1174)) && ((*(byte *)(iVar1 + 0x59) & 0x11) == 0x11)) {
          if (((*(ushort *)(iVar1 + 0x54) & 0x40) == 0) || (*(char *)(iVar1 + 0x57) == '\b')) {
            FUN_600a4bb8(iVar1,param_3);
          }
          else {
            if ((*(ushort *)(iVar1 + 0x2a) & 0x10) != 0) {
              *(byte *)(iVar1 + 0x59) = *(byte *)(iVar1 + 0x59) | 4;
            }
            *(ushort *)(iVar1 + 0x2a) = *(ushort *)(iVar1 + 0x2a) & 0xffcd;
          }
        }
        *(char *)(iVar1 + 0x51) = param_3;
        *(code **)(iVar1 + 0xf4) = param_6;
        *(undefined4 *)(iVar1 + 0xf8) = param_7;
        *(ushort *)(iVar1 + 0x2a) = *(ushort *)(iVar1 + 0x2a) & 0xfffe;
        local_11 = FUN_600a7b44(iVar1);
        if ((local_11 != '\x01') && (param_6 != (code *)0x0)) {
          *(undefined4 *)(iVar1 + 0xf4) = 0;
          (*param_6)(param_1,0,param_7,local_11);
        }
      }
    }
    else {
      local_11 = '\x01';
      if (((*(byte *)(DAT_600a5460 + 0x1174) < 4) || (*(char *)(iVar1 + 0x59) == '\x10')) ||
         (((*(byte *)(iVar1 + 0x59) & 0x11) == 0x11 &&
          (iVar3 = FUN_600a4b1c(iVar1,param_3), iVar3 == 0)))) {
        if (param_3 == '\0') {
          if (((((((local_14 & 7) == 0) ||
                 (((local_14 & 7) == 2 && (iVar3 = FUN_600f1898(iVar1), iVar3 != 0)))) ||
                (((local_14 & 7) == 1 &&
                 ((iVar3 = FUN_600f18e4(iVar1), iVar3 != 0 ||
                  (iVar3 = FUN_600f190a(iVar1,iVar2), iVar3 != 0)))))) ||
               (((local_14 & 7) == 3 &&
                (((iVar3 = FUN_600f18e4(iVar1), iVar3 != 0 ||
                  (iVar3 = FUN_600f190a(iVar1,iVar2), iVar3 != 0)) &&
                 (iVar3 = FUN_600f1898(iVar1), iVar3 != 0)))))) ||
              (((local_14 & 7) == 5 &&
               (((iVar3 = FUN_600f18e4(iVar1), iVar3 != 0 ||
                 (iVar3 = FUN_600f190a(iVar1,iVar2), iVar3 != 0)) &&
                (iVar3 = FUN_600f18be(iVar1), iVar3 != 0)))))) ||
             (((local_14 & 7) == 6 && (iVar3 = FUN_600f18be(iVar1), iVar3 != 0)))) {
            local_11 = '\0';
          }
        }
        else if ((((local_14 & 0x38) == 0) ||
                 (((local_14 & 0x38) == 0x10 && (iVar3 = FUN_600f1898(iVar1), iVar3 != 0)))) ||
                (((local_14 & 0x38) == 0x30 && (iVar3 = FUN_600f18be(iVar1), iVar3 != 0)))) {
          local_11 = '\0';
        }
        if (((local_11 == '\0') && ((local_14 & 0x40) != 0)) && (*(char *)(iVar1 + 0x57) != '\b')) {
          local_11 = '\x01';
        }
      }
      if ((local_11 == '\0') &&
         (((param_3 != '\0' && ((*(ushort *)(iVar2 + 0xe) & 8) != 0)) ||
          ((param_3 == '\0' && ((*(ushort *)(iVar2 + 0xe) & 1) != 0)))))) {
        local_11 = '\x01';
      }
      if (*(char *)(iVar1 + 0x50) != '\0') {
        local_11 = '\x01';
      }
      if (local_11 == '\x01') {
        FUN_600a81ac(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
      else if (param_6 != (code *)0x0) {
        (*param_6)(param_1,0,param_7,local_11);
      }
    }
  }
  return local_11;
}


