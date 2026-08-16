// 6009dc14  FUN_6009dc14  size=342 bytes
// --- callers ---
//   6009ed00 FUN_6009ed00
//   600a1d3c FUN_600a1d3c
//   600b076c FUN_600b076c
// --- callees ---
//   600b09f8 FUN_600b09f8
//   600aa340 FUN_600aa340
//   6009f644 FUN_6009f644
//   6009e84c FUN_6009e84c
//   6009d930 FUN_6009d930
//   6009cad8 FUN_6009cad8
//   600aa3cc FUN_600aa3cc
//   6009e8fc FUN_6009e8fc


char FUN_6009dc14(ushort param_1)

{
  short *psVar1;
  int iVar2;
  undefined2 local_36;
  undefined2 local_34;
  char local_32;
  undefined1 local_31;
  undefined4 local_30;
  undefined2 local_2c;
  char local_27;
  ushort local_26;
  short *local_24;
  char *local_20;
  char local_1a;
  char local_19;
  
  psVar1 = DAT_6009dd70;
  local_20 = DAT_6009dd6c;
  local_24 = DAT_6009dd70;
  local_26 = param_1 & 0x100;
  local_19 = '\x01';
  local_1a = '\0';
  local_30 = 0;
  local_2c = 0;
  local_31 = 0;
  local_32 = *DAT_6009dd6c;
  DAT_6009dd70[1] = local_26;
  local_27 = FUN_6009cad8(psVar1,&local_30,&local_31,&local_32);
  if ((local_26 == 0) && (*local_24 == 0)) {
    local_19 = '\0';
  }
  FUN_6009d930(local_24,local_27,&local_34,&local_36);
  FUN_600aa3cc(local_24 + 0xe);
  if (local_19 == '\x01') {
    if (local_27 == *(char *)((int)local_24 + 0x11)) {
      if (((char)local_24[8] == *local_20) && (*(char *)((int)local_24 + 0x1b) != '\0'))
      goto LAB_6009dd06;
    }
    FUN_6009e8fc();
    iVar2 = FUN_600b09f8(local_34,local_36,local_27,local_32,local_31,&local_30,(char)local_24[0x52]
                         ,(char)local_24[7]);
    if (iVar2 == 0) {
      local_1a = '\x03';
    }
    else {
      *(char *)((int)local_24 + 0x11) = local_27;
      *(char *)(local_24 + 8) = local_32;
    }
  }
LAB_6009dd06:
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
  return local_1a;
}


