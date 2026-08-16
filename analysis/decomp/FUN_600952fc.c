// 600952fc  FUN_600952fc  size=374 bytes
// --- callers ---
//   600fdab8 FUN_600fdab8
//   600fdbb8 FUN_600fdbb8
//   600fd6d6 FUN_600fd6d6
//   600fee40 FUN_600fee40
// --- callees ---
//   600efcc6 FUN_600efcc6
//   600efcfe FUN_600efcfe
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined4 FUN_600952fc(byte param_1,int param_2,char param_3,char param_4)

{
  int iVar1;
  ushort *puVar2;
  byte local_d;
  char *local_c;
  
  local_c = DAT_60095474;
  local_d = 0;
  while( true ) {
    if (1 < local_d) {
      if (param_3 != '\0') {
        local_c = DAT_60095474;
        for (local_d = 0; local_d < 2; local_d = local_d + 1) {
          if (*local_c == '\0') {
            *local_c = '\x01';
            if (param_2 == 0) {
              FUN_600efcc6(local_c + 1,DAT_60095478);
            }
            else {
              FUN_600efcc6(local_c + 1,param_2);
            }
            if (param_4 == '\0') {
              local_c = local_c + 8;
            }
            else {
              local_c = local_c + 10;
            }
            *(short *)local_c = (short)(1 << (param_1 - 1 & 0xff));
            return 1;
          }
          local_c = local_c + 0xc;
        }
      }
      return 0;
    }
    if ((*local_c != '\0') &&
       (((param_2 != 0 && (iVar1 = FUN_600efcfe(local_c + 1,param_2), iVar1 == 0)) ||
        ((param_2 == 0 && (iVar1 = FUN_600efcfe(local_c + 1,DAT_60095478), iVar1 == 0)))))) break;
    local_d = local_d + 1;
    local_c = local_c + 0xc;
  }
  if (param_4 == '\0') {
    puVar2 = (ushort *)(local_c + 8);
  }
  else {
    puVar2 = (ushort *)(local_c + 10);
  }
  if (param_3 == '\0') {
    if (param_1 == 0) {
      *puVar2 = 0;
    }
    else {
      *puVar2 = ~(ushort)(1 << (param_1 - 1 & 0xff)) & *puVar2;
    }
  }
  else {
    *puVar2 = (ushort)(1 << (param_1 - 1 & 0xff)) | *puVar2;
  }
  if ((*(short *)(local_c + 8) == 0) && (*(short *)(local_c + 10) == 0)) {
    thunk_EXT_FUN_0000b5ba(local_c,0,0xc);
  }
  return 1;
}


