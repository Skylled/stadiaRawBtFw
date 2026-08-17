// 600bc760  FUN_600bc760  size=130 bytes
// --- callers ---
//   600b89b8 FUN_600b89b8
// --- callees ---


undefined1 FUN_600bc760(void)

{
  int iVar1;
  ushort local_e;
  char *local_c;
  
  local_c = DAT_600bc7e4;
  local_e = 0;
  do {
    if (3 < local_e) {
      return 0;
    }
    if (*local_c != '\0') {
      if ((*(int *)(local_c + 0x5c) == 0) || (local_c[1] == '\x05')) {
        return 1;
      }
      if (((*(int *)(local_c + 0x5c) == *(int *)(local_c + 0x60)) &&
          (iVar1 = *(int *)(local_c + 0x5c), *(char *)(iVar1 + 5) != '\0')) &&
         ((*(char *)(iVar1 + 4) == '\a' || (*(char *)(iVar1 + 4) == '\b')))) {
        return 1;
      }
    }
    local_e = local_e + 1;
    local_c = local_c + 0xa4;
  } while( true );
}


