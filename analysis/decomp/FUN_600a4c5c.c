// 600a4c5c  FUN_600a4c5c  size=1346 bytes
// --- callers ---
//   600b61c4 FUN_600b61c4
//   600b5ec8 FUN_600b5ec8
//   600b6378 FUN_600b6378
// --- callees ---
//   600f1898 FUN_600f1898
//   600a4bb8 FUN_600a4bb8
//   600a7e8c FUN_600a7e8c
//   600f2024 FUN_600f2024
//   600f1746 FUN_600f1746
//   600f18e4 FUN_600f18e4
//   600a7df8 FUN_600a7df8
//   600f204a FUN_600f204a
//   600a7b44 FUN_600a7b44
//   600a4b1c FUN_600a4b1c
//   600f190a FUN_600f190a
//   600f18be FUN_600f18be


char FUN_600a4c5c(undefined4 param_1,ushort param_2,undefined2 param_3,char param_4,code *param_5,
                 undefined4 param_6)

{
  undefined1 uVar1;
  undefined2 uVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort local_12;
  
  bVar3 = false;
  iVar5 = FUN_600f1746(param_1);
  *(undefined2 *)(iVar5 + 0xc) = param_3;
  iVar6 = FUN_600a7df8(param_4,param_2);
  if (iVar6 == 0) {
    (*param_5)(param_1,0,param_6,4);
    cVar4 = '\x04';
  }
  else {
    iVar7 = FUN_600f2024(param_2);
    if ((iVar7 == 0) || (*(char *)(DAT_600a4fac + 0x88d) != '\0')) {
      if (*(char *)(DAT_600a4fac + 0x1174) == '\x06') {
        local_12 = FUN_600f204a(*(undefined2 *)(iVar6 + 0xe),param_4);
      }
      else {
        local_12 = *(ushort *)(iVar6 + 0xe);
      }
      if (((param_4 == '\0') && ((local_12 & 0x40) != 0)) &&
         (((*(byte *)(DAT_600a4fac + 0x88c) & 1) == 0 || ((*(byte *)(iVar5 + 0x5c) & 1) == 0)))) {
        if (param_5 != (code *)0x0) {
          (*param_5)(param_1,0,param_6,0x14);
        }
        cVar4 = '\x14';
      }
      else if ((*(int *)(iVar5 + 0xf4) == 0) && (*(char *)(DAT_600a4fac + 0x118c) == '\0')) {
        *(int *)(iVar5 + 0xf0) = iVar6;
        if (3 < *(byte *)(DAT_600a4fac + 0x1174)) {
          if ((*(byte *)(iVar5 + 0x59) & 0x11) == 0x11) {
            if (param_4 == '\0') {
              bVar3 = true;
              local_12 = local_12 | 6;
            }
            else {
              local_12 = local_12 | 0x30;
            }
          }
          else if ((*(byte *)(iVar5 + 0x59) & 0x10) == 0) {
            *(byte *)(iVar5 + 0x59) = *(byte *)(iVar5 + 0x59) | 8;
            return '\x01';
          }
        }
        uVar2 = *(undefined2 *)(iVar5 + 0x54);
        uVar1 = *(undefined1 *)(iVar5 + 0x51);
        *(ushort *)(iVar5 + 0x54) = local_12;
        *(undefined4 *)(iVar5 + 0xf8) = param_6;
        *(char *)(iVar5 + 0x51) = param_4;
        iVar6 = FUN_600a7e8c(iVar6);
        if ((iVar6 == 0) || ((*(byte *)(iVar5 + 0x59) & 0x11) == 0x11)) {
          if ((param_4 == '\0') ||
             (((3 < *(byte *)(DAT_600a51a4 + 0x1174) && ((*(byte *)(iVar5 + 0x59) & 0x11) == 0x11))
              || (param_2 < 0x1001)))) {
            if ((bVar3) &&
               (((*(ushort *)(iVar5 + 0x2a) & 2) == 0 || ((*(ushort *)(iVar5 + 0x2a) & 4) == 0)))) {
              *(code **)(iVar5 + 0xf4) = param_5;
              *(undefined1 *)(iVar5 + 0x50) = 7;
              (*param_5)(param_1,0,param_6,0xf);
              cVar4 = '\0';
            }
            else {
              *(code **)(iVar5 + 0xf4) = param_5;
              if ((*(char *)(iVar5 + 0xef) == '\0') ||
                 (*(char *)(iVar5 + 0xef) != *(char *)(*(int *)(iVar5 + 0xf0) + 0x10))) {
                *(ushort *)(iVar5 + 0x2a) = *(ushort *)(iVar5 + 0x2a) & 0xfffe;
              }
              if ((*(byte *)(iVar5 + 0x59) & 0x11) == 0x11) {
                if (((*(ushort *)(iVar5 + 0x54) & 0x40) == 0) || (*(char *)(iVar5 + 0x57) == '\b'))
                {
                  FUN_600a4bb8(iVar5,param_4);
                }
                else {
                  if ((*(ushort *)(iVar5 + 0x2a) & 0x10) != 0) {
                    *(byte *)(iVar5 + 0x59) = *(byte *)(iVar5 + 0x59) | 4;
                  }
                  *(ushort *)(iVar5 + 0x2a) = *(ushort *)(iVar5 + 0x2a) & 0xffcd;
                }
              }
              cVar4 = FUN_600a7b44(iVar5);
              if (cVar4 != '\x01') {
                *(undefined4 *)(iVar5 + 0xf4) = 0;
                (*param_5)(param_1,0,*(undefined4 *)(iVar5 + 0xf8),cVar4);
              }
            }
          }
          else {
            *(undefined2 *)(iVar5 + 0x54) = uVar2;
            *(undefined1 *)(iVar5 + 0x51) = uVar1;
            (*param_5)(param_1,0,param_6,0);
            cVar4 = '\0';
          }
        }
        else {
          *(undefined2 *)(iVar5 + 0x54) = uVar2;
          *(undefined1 *)(iVar5 + 0x51) = uVar1;
          (*param_5)(param_1,0,param_6,0);
          cVar4 = '\0';
        }
      }
      else {
        bVar3 = true;
        if ((*(byte *)(DAT_600a4fac + 0x1174) < 4) ||
           ((*(char *)(iVar5 + 0x59) == '\x10' ||
            (((*(byte *)(iVar5 + 0x59) & 0x11) == 0x11 &&
             (iVar7 = FUN_600a4b1c(iVar5,param_4), iVar7 == 0)))))) {
          if (param_4 == '\0') {
            if (((((((local_12 & 7) == 0) ||
                   (((local_12 & 7) == 2 && (iVar7 = FUN_600f1898(iVar5), iVar7 != 0)))) ||
                  (((local_12 & 7) == 6 && (iVar7 = FUN_600f18be(iVar5), iVar7 != 0)))) ||
                 (((local_12 & 7) == 1 &&
                  ((iVar7 = FUN_600f18e4(iVar5), iVar7 != 0 ||
                   (iVar7 = FUN_600f190a(iVar5,iVar6), iVar7 != 0)))))) ||
                (((local_12 & 7) == 3 &&
                 (((iVar7 = FUN_600f18e4(iVar5), iVar7 != 0 ||
                   (iVar7 = FUN_600f190a(iVar5,iVar6), iVar7 != 0)) &&
                  (iVar7 = FUN_600f1898(iVar5), iVar7 != 0)))))) ||
               (((((local_12 & 7) == 5 &&
                  ((iVar7 = FUN_600f18e4(iVar5), iVar7 != 0 ||
                   (iVar7 = FUN_600f190a(iVar5,iVar6), iVar7 != 0)))) &&
                 (iVar7 = FUN_600f18be(iVar5), iVar7 != 0)) ||
                ((((local_12 & 7) == 7 && (iVar7 = FUN_600f18be(iVar5), iVar7 != 0)) &&
                 ((iVar7 = FUN_600f18e4(iVar5), iVar7 != 0 ||
                  (iVar6 = FUN_600f190a(iVar5,iVar6), iVar6 != 0)))))))) {
              bVar3 = false;
            }
          }
          else if (((((local_12 & 0x38) == 0) ||
                    (((local_12 & 0x38) == 0x10 && (iVar6 = FUN_600f1898(iVar5), iVar6 != 0)))) ||
                   (((local_12 & 0x38) == 0x30 && (iVar6 = FUN_600f18be(iVar5), iVar6 != 0)))) ||
                  ((((local_12 & 0x38) == 0x38 && (iVar6 = FUN_600f18e4(iVar5), iVar6 != 0)) &&
                   (iVar6 = FUN_600f18be(iVar5), iVar6 != 0)))) {
            bVar3 = false;
          }
          if (((!bVar3) && ((local_12 & 0x40) != 0)) && (*(char *)(iVar5 + 0x57) != '\b')) {
            bVar3 = true;
          }
          if (!bVar3) {
            if (param_5 != (code *)0x0) {
              (*param_5)(param_1,0,param_6,0);
            }
            return '\0';
          }
        }
        *(undefined1 *)(DAT_600a4fac + 0x117a) = 1;
        cVar4 = '\x01';
      }
    }
    else {
      (*param_5)(param_1,0,param_6,0x11);
      cVar4 = '\0';
    }
  }
  return cVar4;
}


