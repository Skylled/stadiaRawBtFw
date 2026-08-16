// 6009daac  FUN_6009daac  size=352 bytes
// --- callers ---
//   600a1900 FUN_600a1900
// --- callees ---
//   600b09f8 FUN_600b09f8
//   600aa340 FUN_600aa340
//   6009f644 FUN_6009f644
//   6009e84c FUN_6009e84c
//   6009d930 FUN_6009d930
//   6009cad8 FUN_6009cad8
//   600aa3cc FUN_600aa3cc
//   6009e8fc FUN_6009e8fc


char FUN_6009daac(ushort param_1)

{
  ushort *puVar1;
  int iVar2;
  undefined2 local_36;
  undefined2 local_34;
  char local_32;
  undefined1 local_31;
  undefined4 local_30;
  undefined2 local_2c;
  char local_27;
  ushort local_26;
  ushort *local_24;
  char *local_20;
  char local_1a;
  char local_19;
  
  puVar1 = DAT_6009dc10;
  local_20 = DAT_6009dc0c;
  local_24 = DAT_6009dc10;
  local_26 = param_1 & 0x300;
  local_19 = '\x01';
  local_1a = '\0';
  local_30 = 0;
  local_2c = 0;
  local_31 = 0;
  local_32 = *DAT_6009dc0c;
  if (local_26 < 0x201) {
    *DAT_6009dc10 = local_26;
    local_27 = FUN_6009cad8(puVar1,&local_30,&local_31,&local_32);
    if ((local_24[1] == 0) && (local_26 == 0)) {
      local_19 = '\0';
    }
    FUN_6009d930(local_24,local_27,&local_34,&local_36);
    FUN_600aa3cc(local_24 + 0xe);
    if ((local_19 == '\x01') &&
       (((local_27 != *(char *)((int)local_24 + 0x11) || ((char)local_24[8] != local_32)) ||
        (*(char *)((int)local_24 + 0x1b) == '\0')))) {
      FUN_6009e8fc();
      iVar2 = FUN_600b09f8(local_34,local_36,local_27,local_32,local_31,&local_30,
                           (char)local_24[0x52],(char)local_24[7]);
      if (iVar2 == 0) {
        local_1a = '\x03';
      }
      else {
        *(char *)((int)local_24 + 0x11) = local_27;
        *(char *)(local_24 + 8) = local_32;
      }
    }
    if ((local_1a == '\0') && (local_19 != (char)local_24[9])) {
      if (local_19 == '\x01') {
        local_1a = FUN_6009e84c();
      }
      else {
        local_1a = FUN_6009e8fc();
      }
    }
    if ((char)local_24[9] == '\x01') {
      *(undefined1 *)((int)local_24 + 0x1b) = 1;
      FUN_600aa340(local_24 + 0xe,0x37,0x1e);
    }
    else {
      FUN_6009f644(4,1);
    }
  }
  else {
    local_1a = '\x05';
  }
  return local_1a;
}


