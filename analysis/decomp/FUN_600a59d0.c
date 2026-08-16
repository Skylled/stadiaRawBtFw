// 600a59d0  FUN_600a59d0  size=1236 bytes
// --- callers ---
//   600f14f8 FUN_600f14f8
//   600f2202 FUN_600f2202
//   600a96d8 FUN_600a96d8
//   600a3294 FUN_600a3294
// --- callees ---
//   600a42d0 FUN_600a42d0
//   6013d168 thunk_EXT_FUN_0000b554
//   6009a72c FUN_6009a72c
//   600f9d16 FUN_600f9d16
//   601024d8 FUN_601024d8
//   600a7b44 FUN_600a7b44
//   600f1f82 FUN_600f1f82
//   600a8108 FUN_600a8108
//   600a5964 FUN_600a5964
//   600f1800 FUN_600f1800
//   60098ec8 FUN_60098ec8
//   600a8000 FUN_600a8000
//   600a5670 FUN_600a5670
//   6009ff18 FUN_6009ff18


void FUN_600a59d0(int param_1,undefined4 param_2,char param_3)

{
  char cVar1;
  int iVar2;
  int local_24;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  char local_19;
  int local_18;
  int local_14;
  
  if (((param_1 == 0) && (iVar2 = FUN_60098ec8(DAT_600a5c50,1), iVar2 == 0)) ||
     ((param_1 != 0 && (iVar2 = FUN_60098ec8(param_1,1), iVar2 == 0)))) {
    FUN_6009a72c();
  }
  local_24 = param_1;
  if (param_1 == 0) {
    local_14 = DAT_600a5c54;
    for (local_18 = 0; local_18 < 8; local_18 = local_18 + 1) {
      if (((*(ushort *)(local_14 + 0x2a) & 0x80) != 0) && (*(char *)(local_14 + 0x50) == '\x03')) {
        local_24 = local_14 + 0x10;
        break;
      }
      local_14 = local_14 + 0xfc;
    }
    if (local_18 == 8) {
      local_14 = 0;
    }
  }
  else {
    local_14 = FUN_6009ff18(param_1);
  }
  if (local_14 == 0) {
    local_1c = 0;
    local_1b = 0;
    local_1a = 0;
    for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
      if ((*(int *)(DAT_600a5c58 + (local_18 + 0x450) * 4) != 0) && (local_24 != 0)) {
        (**(code **)(DAT_600a5c58 + (local_18 + 0x450) * 4))(local_24,&local_1c,DAT_600a5c5c);
      }
    }
  }
  else {
    local_19 = *(char *)(local_14 + 0x50);
    if (param_3 == '\0') {
      FUN_601024d8(local_14 + 0x2c,param_2,10);
      *(ushort *)(local_14 + 0x2a) = *(ushort *)(local_14 + 0x2a) | 8;
    }
    else {
      *(undefined1 *)(local_14 + 0x2c) = 0;
    }
    if (*(char *)(local_14 + 0x50) == '\x03') {
      *(undefined1 *)(local_14 + 0x50) = 0;
    }
    for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
      if ((*(int *)(DAT_600a5c58 + (local_18 + 0x450) * 4) != 0) && (local_24 != 0)) {
        (**(code **)(DAT_600a5c58 + (local_18 + 0x450) * 4))
                  (local_24,local_14 + 0x16,local_14 + 0x2c);
      }
    }
    if (((*(char *)(DAT_600a5c58 + 0x118c) == '\x03') && (local_24 != 0)) &&
       (iVar2 = thunk_EXT_FUN_0000b554(DAT_600a5c60,local_24,6), iVar2 == 0)) {
      if ((((*(byte *)(DAT_600a5c58 + 0x118d) & 1) == 0) &&
          ((*(byte *)(DAT_600a5c58 + 0x118d) & 8) == 0)) && (*(int *)(DAT_600a5c58 + 0x111c) != 0))
      {
        *(byte *)(DAT_600a5c58 + 0x118d) = *(byte *)(DAT_600a5c58 + 0x118d) | 8;
        (**(code **)(DAT_600a5c58 + 0x111c))(local_14 + 0x10,local_14 + 0x16,param_2);
      }
      FUN_600a8108(3);
    }
    else if (*(char *)(DAT_600a5c58 + 0x118c) == '\x01') {
      if ((local_24 == 0) || (iVar2 = thunk_EXT_FUN_0000b554(DAT_600a5c60,local_24,6), iVar2 != 0))
      {
        FUN_600f1800(DAT_600a5ec4,0,1);
      }
      else if ((*(byte *)(DAT_600a5c58 + 0x118d) & 0x40) == 0) {
        if (param_3 == '\0') {
          if (((*(byte *)(local_14 + 0x59) & 0x11) == 0) &&
             ((*(byte *)(DAT_600a5ebc + 0x118d) & 0x20) == 0)) {
            *(byte *)(local_14 + 0x59) = *(byte *)(local_14 + 0x59) | 0x10;
          }
          if (*(char *)(local_14 + 0x59) == '\x10') {
            FUN_600a8108(3);
            if (*(char *)(DAT_600a5ebc + 0x117b) == '\0') {
              if ((*(int *)(DAT_600a5ebc + 0x111c) != 0) &&
                 ((*(byte *)(DAT_600a5ebc + 0x118d) & 8) == 0)) {
                iVar2 = FUN_60098ec8(local_14 + 0x10,1);
                if (iVar2 == 0) {
                  *(byte *)(DAT_600a5ebc + 0x118d) = *(byte *)(DAT_600a5ebc + 0x118d) | 0x10;
                }
                *(byte *)(DAT_600a5ebc + 0x118d) = *(byte *)(DAT_600a5ebc + 0x118d) | 8;
                (**(code **)(DAT_600a5ebc + 0x111c))(local_24,local_14 + 0x16,local_14 + 0x2c);
              }
            }
            else {
              FUN_600a42d0(local_24,0,*(undefined1 *)(DAT_600a5ebc + 0x117b),DAT_600a5ec0,
                           local_14 + 4);
            }
          }
          else if ((((*(byte *)(DAT_600a5ebc + 0x118d) & 0x20) == 0) &&
                   (iVar2 = FUN_600a5964(local_14), iVar2 != 1)) &&
                  (FUN_600a8108(0), *(int *)(DAT_600a5ebc + 0x1128) != 0)) {
            (**(code **)(DAT_600a5ebc + 0x1128))(local_14 + 0x10,local_14 + 0x16,local_14 + 0x2c,7);
          }
        }
        else {
          FUN_600a8108(0);
          if (*(int *)(DAT_600a5c58 + 0x1128) != 0) {
            (**(code **)(DAT_600a5c58 + 0x1128))
                      (local_14 + 0x10,local_14 + 0x16,local_14 + 0x2c,param_3);
          }
        }
      }
      else {
        FUN_600a5670();
      }
    }
    else {
      if (*(char *)(local_14 + 0x56) != '\0') {
        if (*(short *)(local_14 + 0xc) == -1) {
          return;
        }
        *(undefined1 *)(local_14 + 0x56) = 0;
        FUN_600a8000(local_14);
        if (((*(ushort *)(local_14 + 0x54) & 0x10) == 0) && (*(int *)(DAT_600a5ebc + 0x1128) != 0))
        {
          (**(code **)(DAT_600a5ebc + 0x1128))(local_14 + 0x10,local_14 + 0x16,local_14 + 0x2c,0);
        }
      }
      if (((*(byte *)(DAT_600a5ebc + 0x118d) & 1) == 0) || ((*(ushort *)(local_14 + 0x2a) & 2) == 0)
         ) {
        if (local_19 == '\x03') {
          if (param_3 == '\0') {
            if (((*(byte *)(local_14 + 0x59) & 8) == 0) &&
               (cVar1 = FUN_600a7b44(local_14), cVar1 != '\x01')) {
              FUN_600f1f82(local_14,cVar1,0);
            }
          }
          else {
            FUN_600f1f82(local_14,10,0);
          }
        }
      }
      else {
        *(ushort *)(local_14 + 0x54) = *(ushort *)(local_14 + 0x54) & 0xffef;
        FUN_600f9d16(*(undefined2 *)(local_14 + 0xc));
      }
    }
  }
  return;
}


