// 600a6d70  FUN_600a6d70  size=1246 bytes
// --- callers ---
//   600a9308 FUN_600a9308
//   600a96d8 FUN_600a96d8
// --- callees ---
//   6009fcf4 FUN_6009fcf4
//   600f0252 FUN_600f0252
//   6013d168 thunk_EXT_FUN_0000b554
//   600aa340 FUN_600aa340
//   6009a72c FUN_6009a72c
//   60098f88 FUN_60098f88
//   600a7b44 FUN_600a7b44
//   600f1f82 FUN_600f1f82
//   600a8108 FUN_600a8108
//   600f1800 FUN_600f1800
//   60098ec8 FUN_60098ec8
//   600a8000 FUN_600a8000
//   600a804c FUN_600a804c
//   600f8c0a FUN_600f8c0a
//   6009ff18 FUN_6009ff18


void FUN_600a6d70(undefined4 param_1,short param_2,char param_3,char param_4)

{
  byte bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  sbyte local_17;
  int *local_14;
  
  local_14 = (int *)FUN_6009ff18(param_1);
  bVar2 = false;
  local_17 = 0;
  FUN_6009a72c();
  if (local_14 == (int *)0x0) {
    if (param_3 != '\0') {
      return;
    }
    local_14 = (int *)FUN_6009fcf4(param_1);
  }
  else {
    if (param_2 == *(short *)((int)local_14 + 0x5e)) {
      local_17 = 8;
    }
    else {
      local_17 = 0;
    }
    iVar4 = *(int *)(DAT_600a709c + 0x1170);
    *(int *)(DAT_600a709c + 0x1170) = iVar4 + 1;
    *local_14 = iVar4;
    if ((*(byte *)((int)local_14 + 0x59) & 0x40) != 0) {
      if (((*(char *)(DAT_600a709c + 0x118c) != '\0') &&
          (iVar4 = thunk_EXT_FUN_0000b554(DAT_600a70a0,local_14 + 4,6), iVar4 == 0)) &&
         ((*(byte *)(DAT_600a709c + 0x118d) & 1) != 0)) {
        if ((param_3 != '\0') && (*(char *)(DAT_600a709c + 0x118c) == '\x02')) {
          *(byte *)((int)local_14 + 0x59) = *(byte *)((int)local_14 + 0x59) & 0xbf;
          if ((*(ushort *)((int)local_14 + 0x2a) & 8) == 0) {
            FUN_600a8108(1);
            FUN_600f1800(local_14 + 4,0,1);
          }
          else {
            *(int **)(DAT_600a709c + 0x114c) = local_14;
            *(undefined4 *)(DAT_600a709c + 0x1160) = DAT_600a70a4;
            FUN_600aa340(DAT_600a70a8,0xd,0);
          }
          *(undefined1 *)((int)local_14 + 0xee) = 0;
          return;
        }
        FUN_600f8c0a(local_14 + 4,1);
      }
      *(byte *)((int)local_14 + 0x59) = *(byte *)((int)local_14 + 0x59) & 0xbf;
    }
  }
  *(byte *)(local_14 + 0x39) = *(byte *)(local_14 + 0x39) | 1;
  *(undefined1 *)((int)local_14 + 0xee) = 0;
  if ((*(char *)(DAT_600a709c + 0x118c) != '\0') &&
     (iVar4 = thunk_EXT_FUN_0000b554(DAT_600a70a0,param_1,6), iVar4 == 0)) {
    if ((param_3 == '\x0f') && ((*(byte *)(DAT_600a709c + 0x118d) & 0x20) != 0)) {
      *(byte *)(DAT_600a709c + 0x118d) = *(byte *)(DAT_600a709c + 0x118d) & 0xdf;
      if ((*(byte *)((int)local_14 + 0x59) & 0x11) == 0) {
        FUN_600a8108(1);
        FUN_600f1800(param_1,0,1);
        return;
      }
      if (*(char *)(DAT_600a709c + 0x118c) == '\x03') {
        return;
      }
      *(int **)(DAT_600a709c + 0x114c) = local_14;
      *(undefined4 *)(DAT_600a709c + 0x1160) = DAT_600a70a4;
      FUN_600aa340(DAT_600a70a8,0xd,0);
      return;
    }
    if (param_3 == '\v') {
      return;
    }
    bVar2 = true;
  }
  FUN_600a804c();
  if (param_3 == '\0') {
    if ((bVar2) && ((*(ushort *)((int)local_14 + 0x2a) & 0x10) != 0)) {
      if (*(char *)((int)local_14 + 0x56) != '\0') {
        *(undefined1 *)((int)local_14 + 0x56) = 0;
        FUN_600a8000(local_14);
      }
      *(ushort *)(local_14 + 0x15) = *(ushort *)(local_14 + 0x15) & 0xffef;
      bVar1 = *(byte *)(DAT_600a7260 + 0x118d);
      if (*(int *)(DAT_600a7260 + 0x1128) != 0) {
        (**(code **)(DAT_600a7260 + 0x1128))(local_14 + 4,(int)local_14 + 0x16,local_14 + 0xb,0);
      }
      FUN_600a8108(0);
      if ((bVar1 & 1) != 0) {
        FUN_600f8c0a(local_14 + 4,1);
      }
    }
    else {
      *(short *)(local_14 + 3) = param_2;
      iVar4 = FUN_60098ec8(param_1,1);
      if ((iVar4 != 0) && (*(short *)(DAT_600a7260 + 0x640) != 0)) {
        FUN_600f0252(iVar4 + 6,DAT_600a7264);
      }
      FUN_60098f88(param_1,(int)local_14 + 0x16,local_14 + 0xb,param_2,0xff,1);
      *(ushort *)((int)local_14 + 0x2a) =
           ~(ushort)(0x47 << local_17) & *(ushort *)((int)local_14 + 0x2a);
      if (param_4 != '\0') {
        *(ushort *)((int)local_14 + 0x2a) =
             (ushort)(6 << local_17) | *(ushort *)((int)local_14 + 0x2a);
      }
      if (*(char *)(DAT_600a7260 + 0x1174) == '\x03') {
        *(ushort *)((int)local_14 + 0x2a) =
             (ushort)(2 << local_17) | *(ushort *)((int)local_14 + 0x2a);
      }
      *(undefined1 *)(local_14 + 0x16) = 0;
      if ((((*(ushort *)((int)local_14 + 0x2a) & 8) == 0) ||
          (*(char *)((int)local_14 + 0x51) != '\0')) &&
         (cVar3 = FUN_600a7b44(local_14), cVar3 != '\x01')) {
        FUN_600f1f82(local_14,cVar3,0);
      }
    }
  }
  else {
    if (bVar2) {
      *(ushort *)(local_14 + 0x15) = *(ushort *)(local_14 + 0x15) & 0xffef;
      *(ushort *)((int)local_14 + 0x2a) =
           ~(ushort)(0x30 << local_17) & *(ushort *)((int)local_14 + 0x2a);
      FUN_600a8108(0);
      if (*(int *)(DAT_600a709c + 0x1128) != 0) {
        (**(code **)(DAT_600a709c + 0x1128))
                  (local_14 + 4,(int)local_14 + 0x16,local_14 + 0xb,param_3);
      }
    }
    else if (((((param_3 == '\x05') || (param_3 == '\x06')) ||
              ((param_3 == '\x0e' || ((param_3 == '\x18' || (param_3 == '&')))))) ||
             (param_3 == ')')) || ((param_3 == '%' || (param_3 == '\x17')))) {
      *(ushort *)(local_14 + 0x15) = *(ushort *)(local_14 + 0x15) & 0xffef;
      *(ushort *)((int)local_14 + 0x2a) = *(ushort *)((int)local_14 + 0x2a) & 0xffef;
      if (*(int *)(DAT_600a709c + 0x1128) != 0) {
        (**(code **)(DAT_600a709c + 0x1128))
                  (local_14 + 4,(int)local_14 + 0x16,local_14 + 0xb,param_3);
      }
    }
    if ((((param_3 == '\b') || (param_3 == '\"')) || (param_3 == '\x1f')) || (param_3 == '\x04')) {
      FUN_600f1f82(local_14,8,0);
    }
    else {
      FUN_600f1f82(local_14,10,0);
    }
  }
  return;
}


