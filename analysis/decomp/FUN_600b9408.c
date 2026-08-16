// 600b9408  FUN_600b9408  size=804 bytes
// --- callers ---
//   600b5264 FUN_600b5264
//   600f9a70 FUN_600f9a70
//   600b7800 FUN_600b7800
//   600f9462 FUN_600f9462
//   600f9ae6 FUN_600f9ae6
//   600b7674 FUN_600b7674
//   600b9d94 FUN_600b9d94
//   600f99ee FUN_600f99ee
//   600f8208 FUN_600f8208
//   600b842c FUN_600b842c
//   600f8de8 FUN_600f8de8
//   600bbb2c FUN_600bbb2c
//   600f8f7a FUN_600f8f7a
//   600f9906 FUN_600f9906
//   600f8122 FUN_600f8122
//   600b6d30 FUN_600b6d30
//   600b8d7c FUN_600b8d7c
//   600f8c6a FUN_600f8c6a
//   600f8ed0 FUN_600f8ed0
//   600bb906 FUN_600bb906
//   600a3d8c FUN_600a3d8c
//   600bbbf8 FUN_600bbbf8
//   600f8d34 FUN_600f8d34
//   600b9938 FUN_600b9938
//   600b6900 FUN_600b6900
// --- callees ---
//   600aa340 FUN_600aa340
//   600d9250 FUN_600d9250
//   600bcca8 FUN_600bcca8
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006dfa4 FUN_6006dfa4
//   600b9740 FUN_600b9740


void FUN_600b9408(char *param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  char *local_24;
  undefined1 auStack_20 [6];
  char local_1a;
  char local_19;
  undefined2 local_18;
  undefined2 *local_14;
  char local_d;
  int local_c;
  
  local_d = '\0';
  if ((param_1 != (char *)0x0) && (*(int *)(DAT_600b9698 + 0xd4) != 0)) {
    thunk_EXT_FUN_0000b572(auStack_20,param_1 + 4,6);
    local_1a = param_1[10];
    local_19 = param_1[1];
    local_18 = *(undefined2 *)(param_1 + 2);
    local_14 = param_3;
    iVar1 = (**(code **)(DAT_600b9698 + 0xd4))(0xe,auStack_20);
    if (iVar1 == 1) {
      return;
    }
  }
  if ((param_3 != (undefined2 *)0x0) && (param_1 != (char *)0x0)) {
    if (param_2 == (undefined2 *)0x0) {
      *param_3 = 0;
    }
    else {
      *param_3 = *param_2;
      local_d = '\x01';
    }
    param_3[3] = 0;
    FUN_6006dfa4(param_1 + 0x80,param_3);
    if (*(short *)(param_1 + 0x1a) == 0) {
      if (param_1[0x32] == '\x02') {
        *(undefined1 *)(DAT_600b969c + 0xf54) = 1;
      }
      else {
        *(undefined1 *)(DAT_600b969c + 8) = 1;
      }
    }
  }
  if (*(char *)(DAT_600b969c + 9) == '\0') {
    if ((param_1 == (char *)0x0) || (*(short *)(param_1 + 0x1a) == 0)) {
      if (param_1 == (char *)0x0) {
        local_24 = DAT_600b96a0;
      }
      else {
        local_24 = param_1;
        if (local_d == '\0') {
          local_24 = param_1 + 0xa4;
        }
      }
      local_c = 0;
      while (((local_c < 4 &&
              (((*(short *)(DAT_600b969c + 2) != 0 &&
                (*(ushort *)(DAT_600b969c + 6) < *(ushort *)(DAT_600b969c + 4))) ||
               (local_24[0x32] != '\x01')))) &&
             ((local_24[0x32] != '\x02' ||
              ((*(ushort *)(DAT_600b969c + 0xf52) < *(ushort *)(DAT_600b969c + 0xf50) &&
               (*(short *)(DAT_600b969c + 0xf4a) != 0))))))) {
        if (local_24 == DAT_600b96a4) {
          local_24 = DAT_600b96a0;
        }
        if (((*local_24 != '\0') && (local_24[0xa2] == '\0')) &&
           ((local_24[1] == '\x04' && (*(short *)(local_24 + 0x1a) == 0)))) {
          iVar1 = FUN_600d9250(local_24 + 0x80);
          if (iVar1 == 0) {
            if (local_d != '\0') break;
            iVar1 = FUN_600bcca8(local_24);
            if (iVar1 != 0) {
              FUN_600b9740(local_24,iVar1);
            }
          }
          else {
            FUN_600b9740(local_24,iVar1);
          }
        }
        local_c = local_c + 1;
        local_24 = local_24 + 0xa4;
      }
      if (((*(short *)(DAT_600b969c + 2) != 0) &&
          (*(ushort *)(DAT_600b969c + 6) < *(ushort *)(DAT_600b969c + 4))) &&
         (local_24[0x32] == '\x01')) {
        *(undefined1 *)(DAT_600b969c + 8) = 0;
      }
      if (((*(short *)(DAT_600b969c + 0xf4a) != 0) &&
          (*(ushort *)(DAT_600b969c + 0xf52) < *(ushort *)(DAT_600b969c + 0xf50))) &&
         (local_24[0x32] == '\x02')) {
        *(undefined1 *)(DAT_600b969c + 0xf54) = 0;
      }
    }
    else if ((param_1[0xa2] == '\0') && (param_1[1] == '\x04')) {
      while ((((*(short *)(DAT_600b969c + 2) != 0 && (param_1[0x32] == '\x01')) ||
              ((*(short *)(DAT_600b969c + 0xf4a) != 0 && (param_1[0x32] == '\x02')))) &&
             (*(ushort *)(param_1 + 0xa0) < *(ushort *)(param_1 + 0x1a)))) {
        iVar1 = FUN_600d9250(param_1 + 0x80);
        if ((iVar1 == 0) || (iVar1 = FUN_600b9740(param_1,iVar1), iVar1 == 0)) break;
      }
      if (local_d == '\0') {
        while (((*(short *)(DAT_600b973c + 2) != 0 && (param_1[0x32] == '\x01')) ||
               ((*(short *)(DAT_600b973c + 0xf4a) != 0 && (param_1[0x32] == '\x02'))))) {
          if (((*(ushort *)(param_1 + 0x1a) <= *(ushort *)(param_1 + 0xa0)) ||
              (iVar1 = FUN_600bcca8(param_1), iVar1 == 0)) ||
             (iVar1 = FUN_600b9740(param_1,iVar1), iVar1 == 0)) break;
        }
      }
      if ((*(short *)(param_1 + 0x88) != 0) &&
         (*(ushort *)(param_1 + 0xa0) < *(ushort *)(param_1 + 0x1a))) {
        FUN_600aa340(param_1 + 0x44,2,2);
      }
    }
  }
  return;
}


